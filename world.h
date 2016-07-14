#ifndef __WORLD_H__
#define __WORLD_H__
#include <vector>
#include <string>
#include <utility>

#include "connection.h"
#include "person.h"

typedef unsigned long long int ulli;

class World {
 private:
  static ulli WORLD_WIDTH;
  static ulli WORLD_HEIGHT;
  
  ulli world_generation_counter;
  std::vector<Person *> world_living_people;
  std::vector<Person *> world_graveyard;

  // dem messiahs
  std::vector<Person *> world_messiahs;

  // people who have increased the happiness of others
  std::vector<Person *> world_major_good_people;

  // people who have increased the overall science level of the world
  std::vector<Person *> world_major_science_people;

  // people who have gained a lot of fame 
  std::vector<Person *> world_major_celeb_people;

  // people who have done a lot of crime
  std::vector<Person *> world_major_evil_people;
  
  /* these rates are a measure of health
     from 0 to 1 inclusive */
  double rate_of_world_technology;
  double rate_of_world_economics;
  double rate_of_world_health;

  void mate_all_the_people(); /* the angel of life (sex) */
  void kill_all_the_people(); /* the angel of death */
  void update_people_connections(); /* removes the dead connections and forms new ones on the living */
  void update_accomplishments(); /* from nobel prize winning to mass murder */
  void update_people_statistics(); /* people become happier, sadder, fatter, unhealthier, richer, poorer as they grow older and know new people */
  void update_people_locations(); /* jiggle people around as technology gets better and as people become lovers */
  ulli get_distance_bw(std::pair<ulli, ulli> point1,
		       std::pair<ulli, ulli> point2);
  Person *generate_child(const Person *p1, const Person*p2);

 public:
  World();
  ~World();

  enum people_type : unsigned int {
    messiah = 0,
    celeb = 1,
    scientist = 2,
    evil = 3,
    good = 4
  };

  std::vector< std::pair<Person *, std::string> > get_wishes(); 
  std::vector<Person *> get_living_people();
  std::vector<Person *> get_dead_people(ulli generation);
  std::vector<Person *> get_messiahs();
  std::vector<Person *> get_major_good_people();
  std::vector<Person *> get_major_evil_people();
  std::vector<Person *> get_major_science_people();
  std::vector<Person *> get_major_celeb_people();

  void add_person(Person *to_add);
  void make_person_indelible(Person *to_add, unsigned int TYPE);
  void kill_person(Person *to_kill, std::string death_reason);
  void appoint_messiah(Person *messiah, std::vector<std::string> miracles);
  void perform_dangerous_disaster(ulli x_coord, ulli y_coord, ulli radius);
  void update_to_next_generation();
  void print_world();
};

#endif


/* 
   Thoughts on how world works:
   Generation counter;
   Size limits: w and h, but also wrap around
   Assign people homes
   Assign people wishes
   function: grant person's wish REMOVED (view takes care of this) -> (world assists with range (current generation))
   Assign people connections
   Trigger disasters in certain coordinates
   World should have some graphical representation
   World keeps track of stats (e.g. members per religion, false prophets,
                               average person stats)
   World births and kills people 
   Generation expectency 
   Population rate based on population curve
   World initialized with certain amount of people
   World keeps track of overall science level and overall economic status
   World has query system.
   World keeps tracks death dates.
   World has graveyard 

   If world is regional should be specified
   STRETCH: world has geography
   STRETCH: world has other species? ? ? OGRES ?? ALIENS ?? ? ? DOGGGS ?? 

   Major science ? Major evil ? Major good ? Major celeb ?

   function: kill person REMOVED (view will do this) -> (world assists with range (current generation))

   Dictate actions of people based on emotions and connections (e.g. strong
   connection + anger == MURDER || social -> give to all connections)
   - Good will and ill will (is this the SIMs?)

   Any culture part of this simulation should be kept track of by world

   Are you ready, son? Are you ready to play GOD? 


   Satisfaction of people determine whether they will go more toward religion 
   or science
*/
