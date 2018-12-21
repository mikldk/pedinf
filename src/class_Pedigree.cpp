#include "pedinf_types.hpp"

#include <Rcpp.h>

/*
==========================================
Pedigree
==========================================
*/

Pedigree::Pedigree(int id) {
  //Rcpp::Rcout << "Pedigree with id = " << id << " created" << std::endl;
  
  m_pedigree_id = id;
  
  m_all_individuals = new std::vector<Individual*>();
  m_relations = new std::vector< std::pair<Individual*, Individual*>* >();
}

Pedigree::~Pedigree() {
  delete m_all_individuals;
  
  for (auto it = m_relations->begin(); it != m_relations->end(); ++it) {
    delete *it;
  }
  
  delete m_relations;  
}

int Pedigree::get_id() const {
  return m_pedigree_id;
}

void Pedigree::add_member(Individual* i) {
  m_all_individuals->push_back(i);
}

void Pedigree::add_relation(Individual* lhs, Individual* rhs) {
  //std::pair<Individual*, Individual*>* pair = new std::pair(lhs, rhs);
  std::pair<Individual*, Individual*>* pair = new std::pair<Individual*, Individual*>(lhs, rhs);
  m_relations->push_back(pair);
  
  //Rcpp::Rcout << "Adding relation..." << std::endl;
}

void Pedigree::remove_member(Individual* i) {
  Rcpp::stop("Have to be implemented!");
}

std::vector<Individual*>* Pedigree::get_all_individuals() const {
  return m_all_individuals;
}

std::vector< std::pair<Individual*, Individual*>* >* Pedigree::get_relations() const {
  return m_relations;
}





