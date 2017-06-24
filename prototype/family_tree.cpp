#include <iostream>
#include <string>
#include <vector>

#include "family_tree.h"
#include "name_generator.h"
#include "person.h"

typedef std::shared_ptr<Person> person_ptr;
typedef std::weak_ptr<Person> weak_person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;
typedef std::vector<ID_type> friend_vector;
typedef std::unordered_map< ID_type, std::vector<ID_type> > children_map;

FamilyTree::FamilyTree() {
  // id of god node parents??? potentially nonzero in unusual case
  std::shared_ptr<FamilyNode> godnode(new FamilyNode(person_ptr(new Person("O.G.D", 0, 0, 0))));
  this->root = godnode;
  
  ID_type god_ID = godnode->parent->get_ID();
  
  weak_node_ptrs[god_ID] = godnode;
  needs_updating[god_ID] = false;
  gen_mapping[0] = std::vector<ID_type>({god_ID});
  
  make_kids(god_ID, god_ID, 2);
}

void FamilyTree::visit_person(ID_type id) {
  
}

children_map FamilyTree::generate_love_lives(ID_type id) {

}

friend_vector FamilyTree::generate_friendships(ID_type id) {

}

std::vector<ID_type> FamilyTree::make_kids(ID_type person1, ID_type person2, int number) {
  for (int i = 0; i < number; ++i) {
    std::string childs_name = NameGenerator::get_random_name();
    
    std::shared_ptr<FamilyNode> person1_node = weak_node_ptrs[person1].lock();
    std::shared_ptr<FamilyNode> person2_node = weak_node_ptrs[person2].lock();
    
    gen_type person1_gen = person1_node->parent->get_generation();
    gen_type person2_gen = person2_node->parent->get_generation();
    
    std::shared_ptr<FamilyNode> childs_node(new FamilyNode(person_ptr(new Person(childs_name, person1_gen + 1, person1, person2))));
    
    weak_node_ptrs[childs_node->parent->get_ID()] = childs_node;
    
    if(person1 != person2) {
      person1_node->children.push_back(childs_node);
    }
    person2_node->children.push_back(childs_node);
  }
}

void FamilyTree::make_friends(ID_type person1, ID_type person2) {
  
}

std::string FamilyTree::toString_node(ID_type id) {
  std::weak_ptr<FamilyNode> weak_node = weak_node_ptrs[id];
  std::shared_ptr<FamilyNode> node = weak_node.lock();
  
  std::string ret = node->parent->toString();
  for (int i = 0; i < node->children.size(); ++i) {
    ret += "\n";
    ret += toString_node(node->children[i]->parent->get_ID());
  }

  return ret;
}

std::string FamilyTree::toString() {
  return toString_node(root->parent->get_ID());
}
