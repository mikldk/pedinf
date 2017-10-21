#include <Rcpp.h>

// [[Rcpp::depends(RcppProgress)]]
#include <progress.hpp>

#include <string>

#include "pedinf_types.hpp"

using namespace Rcpp;

//[[Rcpp::export]]
void pedinf_test() {
  Rcout << "mikl was here 1324" << std::endl;
}


//[[Rcpp::export]]
int pop_size(Rcpp::XPtr<Population> population) {
  return population->get_population_size();
}

//' Get number of pedigrees
//' 
//' @export
// [[Rcpp::export]]
int pedigrees_count(Rcpp::XPtr< std::vector<Pedigree*> > pedigrees) {
  return pedigrees->size();
}

//' Get pedigree size
//' 
//' @export
// [[Rcpp::export]]
int pedigree_size(Rcpp::XPtr<Pedigree> ped) {  
  return ped->get_all_individuals()->size();
}

//' Get distribution of pedigree sizes
//' 
//' @export
//[[Rcpp::export]]
std::unordered_map<int, int> pedigrees_table(Rcpp::XPtr< std::vector<Pedigree*> > pedigrees) {
  std::vector<Pedigree*>* peds = pedigrees;
  std::unordered_map<int, int> tab;
  
  for (auto it = peds->begin(); it != peds->end(); ++it) {
    tab[(*it)->get_all_individuals()->size()] += 1;
  }
  
  return tab;
}

//[[Rcpp::export]]
Rcpp::XPtr<Pedigree> get_pedigree(Rcpp::XPtr< std::vector<Pedigree*> > pedigrees, int index) {  
  std::vector<Pedigree*>* peds = pedigrees;
  Pedigree* p = peds->at(index);
  
  //Rcpp::XPtr<Pedigree> res(p, true);
  Rcpp::XPtr<Pedigree> res(p, false); // do NOT delete pedigree when not used any more, it still exists in list of pedigrees etc.!
  res.attr("class") = CharacterVector::create("pedinf_pedigree", "externalptr");
  
  return res;
}

//[[Rcpp::export]]
Rcpp::XPtr<Individual> get_individual(Rcpp::XPtr<Population> population, int pid) {  
  Population* pop = population;
  
  Individual* ind = population->get_individual(pid);
  //Rcpp::XPtr<Individual> res(ind, true);
  Rcpp::XPtr<Individual> res(ind, false); // do NOT delete individual when not used any more, it still exists in pedigree and population etc.!
  res.attr("class") = CharacterVector::create("pedinf_individual", "externalptr");
  
  return res;
}

//[[Rcpp::export]]
void print_individual(Rcpp::XPtr<Individual> individual) {  
  Individual* i = individual;
  
  int pid_m = (i->get_mother() != nullptr) ? i->get_mother()->get_pid() : 0;
  int pid_f = (i->get_father() != nullptr) ? i->get_father()->get_pid() : 0;
  std::vector<Individual*>* children = i->get_children();
  
  Rcpp::Rcout << "  " << i->get_pid() << " with mother  = " << pid_m << " and father " << pid_f << " and children (n = " << children->size() << ")";
  
  if (children->size() == 0) {
    Rcpp::Rcout << std::endl;
  } else {
    Rcpp::Rcout << ": " << std::endl;

    for (auto child : *children) {    
      std::vector<Individual*>* child_children = child->get_children();
      
      Rcpp::Rcout << "  " << child->get_pid() << " with mother  = " << pid_m << " and father " << pid_f << " and " <<  child_children->size() << " children" << std::endl;
    }
  }
}


//[[Rcpp::export]]
int get_children_count(Rcpp::XPtr<Individual> individual) {  
  return individual->get_children()->size();
}


//[[Rcpp::export]]
void print_pedigree(Rcpp::XPtr<Pedigree> ped) {  
  Pedigree* p = ped;
  
  std::vector<Individual*>* inds = p->get_all_individuals();
  std::vector< std::pair<Individual*, Individual*>* >* rels = p->get_relations();
  
  Rcpp::Rcout << "Pedigree with " << p->get_all_individuals()->size() << " individuals:" << std::endl;
  
  for (auto i : *inds) {    
    int pid_m = (i->get_mother() != nullptr) ? i->get_mother()->get_pid() : 0;
    int pid_f = (i->get_father() != nullptr) ? i->get_father()->get_pid() : 0;
    
    Rcpp::Rcout << "  " << i->get_pid() << " with mother  = " << pid_m << " and father " << pid_f << std::endl;
  } 
}

//' get pids in pedigree
//' 
//' @export
// [[Rcpp::export]]
IntegerVector get_pids_in_pedigree(Rcpp::XPtr<Pedigree> ped) {  
  Pedigree* p = ped;
  
  std::vector<Individual*>* inds = p->get_all_individuals();
  
  IntegerVector res(inds->size());
  int i = 0;
  for (auto ind : *inds) {   
    res(i) = ind->get_pid();
    ++i;
  } 
  
  return res;
}


//[[Rcpp::export]]
CharacterMatrix get_pedigree_edgelist(Rcpp::XPtr<Pedigree> ped) {  
  Pedigree* p = ped;
  
  std::vector< std::pair<Individual*, Individual*>* >* rels = p->get_relations();
  
  CharacterMatrix edgelist(rels->size(), 2);
  int i = 0;
  
  for (auto pair: *rels) {
    edgelist(i, 0) = std::to_string(pair->first->get_pid());
    edgelist(i, 1) = std::to_string(pair->second->get_pid());
    ++i;
  }
  
  return edgelist;
}


//' Get pedigree information as graph (mainly intended for plotting)
//' 
//' @export
// [[Rcpp::export]]
List get_pedigree_as_graph(Rcpp::XPtr<Pedigree> ped) {  
  Pedigree* p = ped;
  
  std::vector<Individual*>* inds = p->get_all_individuals();
  
  CharacterVector nodes(inds->size());
  
  int i = 0;
  for (auto individual : *inds) {
    nodes(i) = std::to_string(individual->get_pid());   
    ++i;
  }
  
  List ret;
  ret["nodes"] = nodes;
  ret["edgelist"] = get_pedigree_edgelist(ped);
  
  return ret;
}


//' Get pedigree from individual
//' 
//' @export
//[[Rcpp::export]]
Rcpp::XPtr<Pedigree> get_pedigree_from_individual(Rcpp::XPtr<Individual> individual) {  
  Individual* i = individual;  
  Rcpp::XPtr<Pedigree> res(i->get_pedigree(), false); // do NOT delete pedigree when not used any more, it still exists in list of pedigrees etc.!
  res.attr("class") = CharacterVector::create("pedinf_pedigree", "externalptr");
  
  return res;
}

//' Get pedigree id from pid
//' 
//' @export
// [[Rcpp::export]]
IntegerVector get_pedigree_id_from_pid(Rcpp::XPtr<Population> population, IntegerVector pids) {  
  std::unordered_map<int, Individual*> pop = *(population->get_population());
  
  int N = pids.size();
  IntegerVector pedigree_ids(N);
  
  for (int i = 0; i < N; ++i) {
    Individual* ind = population->get_individual(pids[i]);
    pedigree_ids[i] = ind->get_pedigree_id();
  }
  
  return pedigree_ids;
}


//' Get pedigree id from pid
//' 
//' @export
// [[Rcpp::export]]
IntegerVector get_pedigree_size_from_pid(Rcpp::XPtr<Population> population, IntegerVector pids) {  
  std::unordered_map<int, Individual*> pop = *(population->get_population());
  
  int N = pids.size();
  IntegerVector pedigree_sizes(N);
  
  for (int i = 0; i < N; ++i) {
    Individual* ind = population->get_individual(pids[i]);
    pedigree_sizes[i] = ind->get_pedigree()->get_all_individuals()->size();
  }
  
  return pedigree_sizes;
}

//' Get pedigree id from pedigree
//' 
//' @export
// [[Rcpp::export]]
int get_pedigree_id_from_pedigree(Rcpp::XPtr<Pedigree> ped) {   
  return ped->get_id();
}




//' Build pedigrees
//' 
//' @export
// [[Rcpp::export]]
int number_of_singletons(Rcpp::XPtr<Population> population) {
  std::unordered_map<int, Individual*> pop = *(population->get_population());
  int N = pop.size();
  
  int singletons = 0;

  for (auto it = pop.begin(); it != pop.end(); ++it) {
    Individual* indv = it->second;
    
    if (indv->get_mother() == nullptr && indv->get_father() == nullptr && indv->get_children()->size() == 0) {
      singletons += 1;
    }
  }
  
  return singletons;
}






