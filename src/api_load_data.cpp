//#include <sys/resource.h>
#include <sstream>

#include <Rcpp.h>

// [[Rcpp::depends(RcppProgress)]]
#include <progress.hpp>

#include "pedinf_types.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
void wipe_population(Rcpp::XPtr<Population> population) {
  Population* pop = population;
  delete pop;
}

//' Construct a population
//' 
//' @export
// [[Rcpp::export]]
Rcpp::XPtr<Population> load_individuals(IntegerVector pid, 
                                        LogicalVector is_male,
                                        IntegerVector pid_mom, 
                                        IntegerVector pid_dad, 
                                        bool progress = true,
                                        bool error_on_pid_not_found = true) {
  std::unordered_map<int, Individual*>* pop = new std::unordered_map<int, Individual*>(); // pid's are garanteed to be unique

  Population* population = new Population(pop);
  Rcpp::XPtr<Population> res(population, true);
  res.attr("class") = CharacterVector::create("pedinf_abort", "pedinf_population_abort", "externalptr");
  
  
  int N = pid.size();
  
  if (is_male.size() != N || pid_mom.size() != N || pid_dad.size() != N) {
    stop("all vectors (pid, is_male, pid_mom, pid_dad) must have same length");
  }
  
  
  // N for building hashmap, and N for building relations (adding children)
  //Progress p(2*N, true);
  Progress p(2*N, progress);
  
  

  // Build hashmap
  for (int k = 0; k < N; ++k) {
    int i_pid = pid[k];
    bool i_is_male = is_male[k];
    
    Individual* i = new Individual(i_pid, i_is_male);

    (*pop)[i->get_pid()] = i;
    
    if (k % CHECK_ABORT_EVERY == 0 && Progress::check_abort() ) {
      return res;
    }
    
    if (progress) {
      p.increment();
    }
  }
  
  // Fill out parents
  for (int k = 0; k < N; ++k) {
    //if (lim_parents_children != -1 && k > lim_parents_children) {
    //  break;
    //}
    
    int i_pid = pid[k];
    int i_pid_mom = pid_mom[k];
    int i_pid_dad = pid_dad[k];
    
    Individual* i = (*pop)[i_pid];
    
    if (i_pid_mom > 0) {
      std::unordered_map<int, Individual*>::const_iterator m = pop->find(i_pid_mom);
      
      if (m == pop->end()) {
        std::ostringstream err;
        err << "NOT FOUND: pid_mom = " << i_pid_mom << " for pid = " << i_pid << " was not found as a pid itself!";
        
        if (error_on_pid_not_found) {
          stop(err.str());
        } else {
          warning(err.str());
        }
      } else {
        // FIXME: Check sex and age (younger than child?) of mother?
        i->set_mother(m->second);
        m->second->add_child(i);
      }
    }
    
    if (i_pid_dad > 0) {
      std::unordered_map<int, Individual*>::const_iterator f = pop->find(i_pid_dad);    
      if (f == pop->end()) {
        std::ostringstream err;
        err << "NOT FOUND: pid_dad = " << i_pid_dad << " for pid = " << i_pid << " was not found as a pid itself!";
        
        if (error_on_pid_not_found) {
          stop(err.str());
        } else {
          warning(err.str());
        }
      } else {
        // FIXME: Check sex and age (younger than child?) of father?        
        i->set_father(f->second);
        f->second->add_child(i);
      }
    }
    
    if (k % CHECK_ABORT_EVERY == 0 && Progress::check_abort() ) {      
      return res;
    }
    
    if (progress) {
      p.increment();
    }
  }
  
  res.attr("class") = CharacterVector::create("pedinf_population", "externalptr");
  
  return res;
}

