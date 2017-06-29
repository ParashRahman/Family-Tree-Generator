#include <iostream>
#include <unordered_map>
#include <vector>

#include "person.h"

typedef std::shared_ptr<Person> person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;

ID_type Person::CURRENT_ID = 0;

Person::Person(std::string nom, gen_type gen, ID_type dad, ID_type mom) : name(nom), my_generation(gen), father(dad), mother(mom) {
  my_id = CURRENT_ID;
  ++CURRENT_ID;
}

void Person::add_children(person_ptr spouse, std::vector<person_ptr> children) {

  std::vector<ID_type> children_IDs(children.size(), 0);
  for (int c = 0; c < children.size(); ++c) {
    children_IDs[c] = children[c]->get_ID();
  }

  child_map[spouse->get_ID()] = children_IDs;
}

void Person::add_child(person_ptr spouse, person_ptr child) {
  add_children(spouse, std::vector<person_ptr>({child}));
}

void Person::clear_children() {
  child_map = children_map();
}

void Person::add_friendships(person_ptr friendo) {
  friends.push_back(friendo->get_ID());
}

void Person::clear_friendships() {
  friends = friend_vector();
}

ID_type Person::get_ID() {
  return my_id;
}

gen_type Person::get_generation() {
  return my_generation;
}

ID_type Person::get_mother() {
  return mother;
}

ID_type Person::get_father() {
  return father;
}

std::string Person::toString() {
  return name;
}
