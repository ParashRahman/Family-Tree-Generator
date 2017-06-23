#include <memory>
#include <unordered_map>
#include <vector>

#include "person.h"

typedef std::shared_ptr<Person> person_ptr;
typedef unsigned long long ID_type;
typedef unsigned long long gen_type;
typedef std::vector<ID_type> friend_vector;
typedef std::unordered_map< ID_type, std::vector<ID_type> > children_map;

class FamilyTree {
 private:
  // this is the most future generation kept track of
  gen_type last_generation = 0;

  // these maps allow caching of people and keeping track
  //   of which people need to be reprocedurally generated
  // TODO: weak pointers or they'll last forever
  std::unordered_map<ID_type, person_ptr> people_cache;
  std::unordered_map<ID_type, bool> needs_updating;
  std::unordered_map< gen_type, std::vector<ID_type> > gen_mapping; 
 public:
  FamilyTree();
  void visit_person(ID_type id);
  children_map generate_love_lives(ID_type id);
  friend_vector generate_friendships(ID_type id);
};
