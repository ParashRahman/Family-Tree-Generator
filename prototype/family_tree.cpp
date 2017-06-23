#include <vector>

#include "family_tree.h"
#include "person.h"

typedef std::shared_ptr<Person> person_ptr;
typedef std::weak_ptr<Person> weak_person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;
typedef std::vector<ID_type> friend_vector;
typedef std::unordered_map< ID_type, std::vector<ID_type> > children_map;

FamilyTree::FamilyTree() {
  o_god = person_ptr(new Person("G.O.D.", 0, 0, 0));
  people_cache[o_god->get_ID()] = o_god;
  needs_updating[o_god->get_ID()] = false;
  gen_mapping[0].push_back(o_god->get_ID());

  // make adam and eve
  make_kids(o_god->get_ID(), o_god->get_ID(), 2);
}

void FamilyTree::visit_person(ID_type id) {
  
}

children_map FamilyTree::generate_love_lives(ID_type id) {

}

friend_vector FamilyTree::generate_friendships(ID_type id) {

}

std::vector<ID_type> FamilyTree::make_kids(ID_type person1, ID_type person2, int number) {

}

void make_friends(ID_type person1, ID_type person2) {

}
