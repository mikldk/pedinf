#include "pedinf_types.hpp"

#include <Rcpp.h>

// [[Rcpp::depends(RcppProgress)]]
#include <progress.hpp>

#include <stdexcept>

/*
==========================================
Individual
==========================================
*/
Individual::Individual(int pid) {
  m_pid = pid;
  m_children = new std::vector<Individual*>();
  m_neighbours = new std::vector<Individual*>();
}

Individual::~Individual() {
  delete m_children;
  delete m_neighbours;
}

int Individual::get_pid() const {
  return m_pid;
}

void Individual::add_child(Individual* child) {
  m_children->push_back(child);
  m_neighbours->push_back(child);
}

void Individual::set_mother(Individual* i) {
  m_mother = i;
  m_neighbours->push_back(i);
}

void Individual::set_father(Individual* i) {
  m_father = i;
  m_neighbours->push_back(i);
}

Individual* Individual::get_mother() const {
  return m_mother;
}

Individual* Individual::get_father() const {
  return m_father;
}

std::vector<Individual*>* Individual::get_children() const {
  return m_children;
}

std::vector<Individual*>* Individual::get_neighbours() const {
  return m_neighbours;
}

bool Individual::pedigree_is_set() const {
  return (m_pedigree_id != 0);
}

int Individual::get_pedigree_id() const {
  return m_pedigree_id;
}

void Individual::reset_pedigree() {
  if (pedigree_is_set()) {
    m_pedigree->remove_member(this);
    m_pedigree_id = 0;
    m_pedigree = nullptr;
  }
}

Pedigree* Individual::get_pedigree() const {
  return m_pedigree;
}

void Individual::set_pedigree_id_recursive(int id, Pedigree* ped, int* pedigree_size) {
  if (this->pedigree_is_set()) {
    return;
  }
  
  m_pedigree = ped;
  m_pedigree_id = id;
  *pedigree_size += 1;
  ped->add_member(this);
  
  if (Progress::check_abort() ) {
    Rcpp::stop("Aborted");
  }
  
  if (m_mother != nullptr) {
    m_mother->set_pedigree_id_recursive(id, ped, pedigree_size);
  }
  
  if (m_father != nullptr) {  
    m_father->set_pedigree_id_recursive(id, ped, pedigree_size);
  }
  
  for (auto &child : (*m_children)) {
    ped->add_relation(this, child);
    child->set_pedigree_id_recursive(id, ped, pedigree_size);
  }
}



void Individual::set_pedigree_id_recursive_parents(int id, Pedigree* ped, int* pedigree_size) {
  if (this->pedigree_is_set()) {
    return;
  }
  
  m_pedigree = ped;
  m_pedigree_id = id;
  *pedigree_size += 1;
  ped->add_member(this);
  
  if (Progress::check_abort() ) {
    Rcpp::stop("Aborted");
  }
  
  if (m_mother != nullptr) {
    m_mother->set_pedigree_id_recursive(id, ped, pedigree_size);
  }
  
  if (m_father != nullptr) {  
    m_father->set_pedigree_id_recursive(id, ped, pedigree_size);
  }  
}


void Individual::set_pedigree_id_recursive_children(int id, Pedigree* ped, int* pedigree_size) {
  if (this->pedigree_is_set()) {
    return;
  }
  
  m_pedigree = ped;
  m_pedigree_id = id;
  *pedigree_size += 1;
  ped->add_member(this);
  
  if (Progress::check_abort() ) {
    Rcpp::stop("Aborted");
  }  
  
  for (auto &child : (*m_children)) {
    ped->add_relation(this, child);
    child->set_pedigree_id_recursive(id, ped, pedigree_size);
  }
}


void Individual::set_pedigree_raw(Pedigree* ped) {
  if (this->pedigree_is_set()) {
    Rcpp::stop("pedigree_is_set");
  }
  
  m_pedigree = ped;
  m_pedigree_id = ped->get_id();
}


void Individual::set_visit_color(int color) {
  m_visit_color = color;
}

int Individual::get_visit_color() const {
  return m_visit_color;
}


