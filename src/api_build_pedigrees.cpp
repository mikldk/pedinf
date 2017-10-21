#include <Rcpp.h>

// [[Rcpp::depends(RcppProgress)]]
#include <progress.hpp>

#include "pedinf_types.hpp"

#include <queue>

using namespace Rcpp;

// [[Rcpp::export]]
void wipe_pedigrees(Rcpp::XPtr< std::vector<Pedigree*> > pedigrees) {
  std::vector<Pedigree*>* peds = pedigrees;
  
  for (auto it = pedigrees->begin(); it != pedigrees->end(); ++it) {
    delete *it;
  }
  
  delete peds;
}

bool pedigree_size_comparator(Pedigree* p1, Pedigree* p2) { 
  return (p1->get_all_individuals()->size() > p2->get_all_individuals()->size());
}

//' Build pedigrees
//' 
//' @export
// [[Rcpp::export]]
Rcpp::XPtr< std::vector<Pedigree*> > build_pedigrees_recursive(Rcpp::XPtr<Population> population, bool progress = true) {
  //Rcpp::Rcout << "Bulding pedigrees!" << std::endl;
  
  // Construct pedigrees
  //std::cout << "Starts giving pedigrees ids..." << std::endl;

  std::vector<Pedigree*>* pedigrees = new std::vector<Pedigree*>();
  Rcpp::XPtr< std::vector<Pedigree*> > res(pedigrees, true);
  //Rcpp::XPtr< std::vector<Pedigree*> > res(pedigrees, false);
  res.attr("class") = CharacterVector::create("pedinf_abort", "pedinf_pedigreelist_abort", "externalptr");

  int pedigree_id = 1;
  Pedigree* ped;
  
  std::unordered_map<int, Individual*> pop = *(population->get_population());
  int N = pop.size();
  int k = 0;
  Progress p(N, progress);

  ped = new Pedigree(pedigree_id);
  
  for (auto it = pop.begin(); it != pop.end(); ++it) {
    if (it->second->pedigree_is_set()) {
      continue;
    }
    
    int ped_size = 0;
    it->second->set_pedigree_id_recursive(pedigree_id, ped, &ped_size);

    pedigree_id += 1;
    
    pedigrees->push_back(ped);
    ped = new Pedigree(pedigree_id);
    
    // FIXME: Iterative instead of recursive
    
    if (k % CHECK_ABORT_EVERY == 0 && Progress::check_abort() ) {
      return res;
    }
    
    if (progress) {
      // FIXME: p.increment(ped_size);
      p.increment();
    }
    
    ++k;
  }
  
  if (ped->get_all_individuals()->size() > 0) {
    pedigrees->push_back(ped);
  } else {
    delete ped;
  }
  
  std::sort(pedigrees->begin(), pedigrees->end(), pedigree_size_comparator);
  
  res.attr("class") = CharacterVector::create("pedinf_pedigreelist", "externalptr");

  return res;
}




















//' Build pedigrees
//' 
//' @export
// [[Rcpp::export]]
Rcpp::XPtr< std::vector<Pedigree*> > build_pedigrees_iterative(Rcpp::XPtr<Population> population, bool progress = true) {
  //Rcpp::Rcout << "Bulding pedigrees!" << std::endl;
  
  // Construct pedigrees
  //std::cout << "Starts giving pedigrees ids..." << std::endl;

  int pedigree_id = 1;
  std::vector<Pedigree*>* pedigrees = new std::vector<Pedigree*>();
  Rcpp::XPtr< std::vector<Pedigree*> > res(pedigrees, true);  
  //Rcpp::XPtr< std::vector<Pedigree*> > res(pedigrees, false);
  res.attr("class") = CharacterVector::create("pedinf_abort", "pedinf_pedigreelist_abort", "externalptr");

  std::unordered_map<int, Individual*> pop = *(population->get_population());
  int N = pop.size();
  int k = 0;
  Progress p(N, progress);
  
  //=====================================================
  // BFS
  //=====================================================  
  //http://www.boost.org/doc/libs/1_54_0/libs/graph/doc/breadth_first_search.html
  //
  // white: color = 0
  // grey:  color = 1
  // black: color = 2
  
  //-----------------------------------------------------
  // Reset colors
  //-----------------------------------------------------
  for (auto it = pop.begin(); it != pop.end(); ++it) {
    Individual* indv = it->second;
    indv->reset_pedigree();
    indv->set_visit_color(0);
  }
  
  // Loop through all individuals and assign pedigree
  Individual* s = nullptr;
  
  std::unordered_map<int, Individual*> possible_s;
  
  // Collect possible start nodes;
  // Simultanously, deal with the singletons (individuals with no parents and no children)
  // For DK, that is approx 30%:
  int singletons = 0;
  for (auto it = pop.begin(); it != pop.end(); ++it) {
    Individual* indv = it->second;
    
    if (indv->get_mother() == nullptr && indv->get_father() == nullptr && indv->get_children()->size() == 0) {
      singletons += 1;
      
      Pedigree* ped = new Pedigree(pedigree_id);
      pedigree_id += 1;
      pedigrees->push_back(ped);    
    
      // found an individual needing pedigree
      ped->add_member(indv);
      indv->set_pedigree_raw(ped);
      indv->set_visit_color(2);
    } else {    
      // Not singleton, perform generic BFS
      possible_s[indv->get_pid()] = indv;
    }
  }  
  
  if (progress) {
    p.increment(singletons);
  }
  
  
  do {
    s = nullptr;
    
    //Rcout << "possible_s.size() = " << possible_s.size() << std::endl;
    
    for (auto it = possible_s.begin(); it != possible_s.end(); ++it) {
      Individual* indv = it->second;
      
      if (indv->get_visit_color() != 0) { continue; }
      if (indv->pedigree_is_set()) { continue; }
      
      s = indv;
    }
    
    if (s == nullptr) {
      continue;
    }
    
    //Rcout << "  Chose s with pid = " << s->get_pid() << " ";
    
    Pedigree* ped = new Pedigree(pedigree_id);
    pedigree_id += 1;
    pedigrees->push_back(ped);    
    
    // found an individual needing pedigree
    s->set_visit_color(1);
    
    std::queue< Individual* > Q;
    Q.push(s);
    
    while (Q.size() != 0) {
      Individual* u = Q.front();
      Q.pop();
      ped->add_member(u);
      u->set_pedigree_raw(ped);
      possible_s.erase(u->get_pid());
      
      /*
      std::vector<Individual*> adj = *(u->get_neighbours());
      
      for(size_t adj_i = 0; adj_i < adj.size(); ++adj_i) {
        Individual* v = adj[adj_i];
        
        if (v->get_visit_color() == 0) { // white
          v->set_visit_color(1); // grey   
          ped->add_relation(u, v);
          Q.push(v);
        } else {
          ///
          if (v->get_visit_color() == 1) { // grey
            ped->add_relation(u, v);
          }          
        }
      }
      */
      
      Individual* v;
      
      std::vector<Individual*> adj = *(u->get_children());      
      for(size_t adj_i = 0; adj_i < adj.size(); ++adj_i) {
        v = adj[adj_i];
        
        if (v->get_visit_color() == 0) { // white
          v->set_visit_color(1); // grey   
          ped->add_relation(u, v);
          Q.push(v);
        } else {
          /// ???
          if (v->get_visit_color() == 1) { // grey
            ped->add_relation(u, v);
          }          
        }
      }
      
      adj = {u->get_mother(), u->get_father()};
      for(size_t adj_i = 0; adj_i < adj.size(); ++adj_i) {
        v = adj[adj_i];
        
        if (v == nullptr) {
          continue;
        }
        
        if (v->get_visit_color() == 0) { // white
          v->set_visit_color(1); // grey   
          ped->add_relation(v, u); // reverse compared to for children
          Q.push(v);
        } else {
          /// ???
          if (v->get_visit_color() == 1) { // grey
            ped->add_relation(v, u);
          }          
        }
      }
      
      u->set_visit_color(2); // black
      //Rcout << "inner queue now size = " << Q.size() << std::endl;
    }
    
    if (Progress::check_abort()) {
      Rcpp::stop("Aborted");
    }
    
    //Rcpp::Rcout << ped->get_all_individuals()->size() << std::endl;
    
    //Rcout << "gave pedigree with size = " << ped->get_all_individuals()->size() << std::endl;
    
    if (progress) {
      p.increment(ped->get_all_individuals()->size());
    }
    
    //Rcout << "outer s" << std::endl;
    
  } while (s != nullptr);
  
  //-----------------------------------------------------
  // Reset colors
  //-----------------------------------------------------
  for (auto it = pop.begin(); it != pop.end(); ++it) {
    Individual* indv = it->second;
    indv->set_visit_color(0);
  }
  
  res.attr("class") = CharacterVector::create("pedinf_pedigreelist", "externalptr");

  return res;
}





