#include <iostream>
#include <string>
#include <vector>

#include "family_tree.h"
#include "logger.h"
#include "name_generator.h"
#include "person.h"
#include "random_handler.h"

typedef std::shared_ptr<Person> person_ptr;
typedef std::weak_ptr<Person> weak_person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;
typedef std::vector<ID_type> friend_vector;
typedef std::unordered_map< ID_type, std::vector<ID_type> > children_map;

FamilyTree::FamilyTree() {
  // id of god node parents??? potentially nonzero in case where there exists multiple family trees
  // therefore, do not depend on godnode's parents.
  std::shared_ptr<FamilyNode> godnode(new FamilyNode(person_ptr(new Person("O.G.D", 0, -1, -1))));
  this->root = godnode;

  godnode->needs_update = false;
  
  ID_type god_ID = godnode->parent->get_ID();
  
  weak_node_ptrs[god_ID] = godnode;
  gen_mapping[0] = std::vector<ID_type>({god_ID});
  
  make_kids(god_ID, god_ID, 2);
}

void FamilyTree::visit_person(ID_type id) {
  Logger::log("visit person: " + std::to_string(id));
  
  // called only on people user explicitly sees.
  std::shared_ptr<FamilyNode> node_ptr = weak_node_ptrs[id].lock();

  if (node_ptr->needs_update) {
    Logger::log("visit person: needs update");
      
    // node_ptr->parent->clear_children();
    // node_ptr->parent->clear_friendships();
    
    node_ptr->needs_update = false;
    /*children_map children =*/ generate_love_lives(id);
    //friend_vector friends = generate_friendships(id);    
  }
}

void FamilyTree::restricted_visit_person(ID_type id) {
  // as opposed to visit_person, restricted visit person does not generate
  //    full love lives/friendships of the person.
  std::shared_ptr<FamilyNode> node_ptr = weak_node_ptrs[id].lock();
  restricted_generate_love_lives(id);
}

ID_type FamilyTree::find_random_same_generation(gen_type steps, ID_type id) {
  RandomHandler rh;
  std::shared_ptr<FamilyNode> current_node = weak_node_ptrs[id].lock();

  gen_type steps_forward = 0;

  // random walk up tree
  while (steps > 0) {
    int random_number = rh.randint(0,1);
    ID_type parent_id;
    if (random_number) {
      parent_id = current_node->parent->get_mother();
    } else {
      parent_id = current_node->parent->get_father();
    }

    current_node = weak_node_ptrs[parent_id].lock();

    ++steps_forward;    
    --steps;

    if (current_node == root) {
      break;
    }
  }

  // random walk down tree
  while (steps_forward) {
    if (current_node->needs_update && current_node->children.size() == 0) {
      restricted_generate_love_lives(current_node->parent->get_ID());
    }
    if (current_node->children.size() == 0) {
      return -1;
    }
    int random_number = rh.randint(0, current_node->children.size() - 1);
    current_node = current_node->children[random_number];
    
    --steps_forward;
  }

  return current_node->parent->get_ID();
}

children_map FamilyTree::restricted_generate_love_lives(ID_type id) {
  // used when generating the random love walk for people the user has yet to
  //     see.
  const gen_type STEPS = 10;
  const int NUM_KIDS = 3;
  
  ID_type funID;
  do {
    funID = find_random_same_generation(STEPS, id);
  } while (funID == -1);

  make_kids(id, funID, NUM_KIDS);

  // TODO: fix
  return children_map();
}

children_map FamilyTree::generate_love_lives(ID_type id) {
  const gen_type STEPS = 10;
  const int NUM_KIDS = 3;
  const int NUM_PARTNERS = 3;

  for (int p = 0; p < NUM_PARTNERS; ++p) {
    ID_type funID;
    do {
      funID = find_random_same_generation(STEPS, id);
    } while (funID == -1);

    make_kids(id, funID, NUM_KIDS);
  }

  // TODO: fix
  return children_map();
}

friend_vector FamilyTree::generate_friendships(ID_type id) {
  // TODO: do
  return friend_vector();
}

std::vector<ID_type> FamilyTree::make_kids(ID_type person1, ID_type person2, int number) {
  std::vector<ID_type> children_IDs;
  
  for (int c = 0; c < number; ++c) {
    std::string childs_name = NameGenerator::get_random_name();
    
    std::shared_ptr<FamilyNode> person1_node = weak_node_ptrs[person1].lock();
    std::shared_ptr<FamilyNode> person2_node = weak_node_ptrs[person2].lock();
    
    gen_type person1_gen = person1_node->parent->get_generation();
    gen_type person2_gen = person2_node->parent->get_generation();

    gen_type childs_gen = person1_gen + 1;
    
    std::shared_ptr<FamilyNode> childs_node(new FamilyNode(person_ptr(new Person(childs_name, childs_gen, person1, person2))));

    ID_type childs_ID = childs_node->parent->get_ID();

    children_IDs.push_back(childs_ID);
    
    // update the appropriate dictionaries
    weak_node_ptrs[childs_ID] = childs_node;
    if (gen_mapping.find(childs_gen) == gen_mapping.end()) {
      gen_mapping[childs_gen] = std::vector<ID_type>();
    }
    gen_mapping[childs_gen].push_back(childs_ID);
    
    if(person1 != person2) {
      person1_node->children.push_back(childs_node);
      person1_node->parent->add_child(weak_node_ptrs[person2].lock()->parent, childs_node->parent);
    }
    person2_node->children.push_back(childs_node);
    person2_node->parent->add_child(weak_node_ptrs[person1].lock()->parent, childs_node->parent);
  }

  return children_IDs;
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
