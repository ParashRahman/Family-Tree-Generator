#include "family_tree.h"
#include "person.h"

typedef std::shared_ptr<Person> person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;
typedef std::vector<ID_type> friend_vector;
typedef std::unordered_map< ID_type, std::vector<ID_type> > children_map;

FamilyTree::FamilyTree() {
  
}

void FamilyTree::visit_person(ID_type id) {

}

children_map FamilyTree::generate_love_lives(ID_type id) {

}

friend_vector FamilyTree::generate_friendships(ID_type id) {

}
