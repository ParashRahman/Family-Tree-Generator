#ifndef _PERSON_H_
#define _PERSON_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "person_stats.h"

class Person;
typedef std::shared_ptr<Person> person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;
typedef std::unordered_map< ID_type, std::vector<ID_type> > children_map;
typedef std::vector<ID_type> friend_vector;

class Person {  
 private:
  std::string name;
  static ID_type CURRENT_ID;
  ID_type my_id;
  children_map child_map;
  gen_type my_generation;
  friend_vector friends;
  ID_type father;
  ID_type mother;

  PersonStats person_stats;
  
 public:
  
  Person(std::string name, gen_type generation, ID_type dad, ID_type mom, PersonStats ps);
  void add_children(person_ptr spouse, std::vector<person_ptr> children);
  void add_child(person_ptr spouse, person_ptr child);
  void clear_children();
  void add_friendships(person_ptr friendo);
  void clear_friendships();
  ID_type get_ID();
  gen_type get_generation();
  ID_type get_mother();
  ID_type get_father();

  PersonStats get_stats();
  
  std::string toString();
};

#endif
