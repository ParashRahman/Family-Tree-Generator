#ifndef _FAMILY_TREE_H_
#define _FAMILY_TREE_H_

#include <memory>
#include <unordered_map>
#include <vector>

#include "person.h"

typedef std::shared_ptr<Person> person_ptr;
typedef std::weak_ptr<Person> weak_person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;
typedef std::vector<ID_type> friend_vector;
typedef std::unordered_map< ID_type, std::vector<ID_type> > children_map;

struct FamilyNode {
  person_ptr parent;
  std::vector< std::shared_ptr<FamilyNode> > children;

  FamilyNode(person_ptr p) {
    parent = p;
    children = std::vector< std::shared_ptr<FamilyNode> >();
  }
};

class FamilyTree {
 private:
  // this is the most future generation kept track of
  gen_type last_generation = 0;

  std::unordered_map< ID_type, std::weak_ptr<FamilyNode> > weak_node_ptrs;
  std::unordered_map<ID_type, bool> needs_updating;
  std::unordered_map< gen_type, std::vector<ID_type> > gen_mapping;

  std::shared_ptr<FamilyNode> root;

  ID_type find_random_same_generation(int steps, ID_type id);
  void restricted_visit_person(ID_type id);
  children_map generate_love_lives(ID_type id);
  children_map restricted_generate_love_lives(ID_type id);
  friend_vector generate_friendships(ID_type id);
  void make_friends(ID_type person1, ID_type person2);
  std::vector<ID_type> make_kids(ID_type person1, ID_type person2, int number);

 public:
  FamilyTree();
  void visit_person(ID_type id);

  std::string toString_node(ID_type id);
  std::string toString();
};

#endif
