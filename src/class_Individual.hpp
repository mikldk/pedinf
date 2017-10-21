#include "pedinf_types.hpp"

#include <vector>

class Individual {
private:
  int m_pid; 

  std::vector<Individual*>* m_children = nullptr;
  Individual* m_mother = nullptr;
  Individual* m_father = nullptr;
  
  std::vector<Individual*>* m_neighbours = nullptr;
    
  Pedigree* m_pedigree = nullptr;
  int m_pedigree_id = 0;
  
  int m_visit_color = 0;
  
public:
  Individual(int pid);
  ~Individual();
  int get_pid() const;
  void add_child(Individual* child);
  void set_mother(Individual* i);
  void set_father(Individual* i);
  Individual* get_mother() const;
  Individual* get_father() const;
  std::vector<Individual*>* get_children() const;
  std::vector<Individual*>* get_neighbours() const;
  bool pedigree_is_set() const;
  void reset_pedigree();
  Pedigree* get_pedigree() const;
  int get_pedigree_id() const;

  void set_pedigree_id_recursive(int id, Pedigree* ped, int* pedigree_size);

  void set_pedigree_id_recursive_parents(int id, Pedigree* ped, int* pedigree_size);
  void set_pedigree_id_recursive_children(int id, Pedigree* ped, int* pedigree_size);
  
  void set_pedigree_raw(Pedigree* ped);
  
  void set_visit_color(int color);
  int get_visit_color() const;
};

