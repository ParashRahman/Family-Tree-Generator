#include <vector>
#include <cmath>
#include <algorithm>

#include "world.h"
#include "person.h"

typedef unsigned long long int ulli;

ulli WORLD_WIDTH = 1000;
ulli WORLD_HEIGHT = 1000;

ulli generation_count = 0;

std::vector<Person *> World::get_living_people() {
  return world_living_people;
}
std::vector<Person *> World::get_dead_people(ulli generation) {
  return world_graveyard;
}
std::vector<Person *> World::get_messiahs() {
  return world_messiahs;
}
std::vector<Person *> World::get_major_good_people() {
  return world_major_good_people;
}
std::vector<Person *> World::get_major_evil_people() {
  return world_major_evil_people;
}
std::vector<Person *> World::get_major_science_people() {
  return world_major_science_people;
}
std::vector<Person *> World::get_major_celeb_people() {
  return world_major_celeb_people;
}

/* WORLD should determine child's stats, not biology */
Person *World::generate_child(const Person *p1, const Person *p2) {  
  // TODO: make syllables random
  std::string childs_name = Person::generate_name(3);
  
  double MALE_PROBABILITY_MARK = 0.475;
  double FEMALE_PROBABILITY_MARK = 0.95;
  double TRANSGENDER_PROBABILITY_MARK = 1.0;
  
  double STRAIGHT_PROBABILITY_MARK = 0.96;
  double HOMOSEXUAL_PROBABILITY_MARK = 0.98;
  double BISEXUAL_PROBABILITY_MARK = 1.0;

  int gender;
  int sexOrient;

  // CREATE A HUMAN
  if (p1->getGender() != p2->getGender() ||
      (p1->getGender() == Person::genders::transgender &&
       p2->getGender() == Person::genders::transgender) ) {
    // In this case mating is possible. Im not going to spell
    // out the conditions; you decipher them and see if they
    // are politically acceptable.
  
    // Now, we randomly determine the child's gender and
    // and sexual orientation
    
    // set up the randomizer
    std::random_device rd; // seed creator
    std::default_random_engine generator {rd()};
    std::uniform_real_distribution<double> distribution(0,1);

    double genderProbability = distribution(generator);
    if (genderProbability < MALE_PROBABILITY_MARK) {
      gender = Person::genders::male;
    } else if (genderProbability < FEMALE_PROBABILITY_MARK) {
      gender = Person::genders::female;
    } else {
      gender = Person::genders::transgender;
    }

    double sexOrientProbability = distribution(generator);
    if (sexOrientProbability < STRAIGHT_PROBABILITY_MARK) {
      sexOrient = Person::sexual_orientations::straight;
    } else if (sexOrientProbability < HOMOSEXUAL_PROBABILITY_MARK) {
      sexOrient = Person::sexual_orientations::homosexual;
    } else if (sexOrientProbability < BISEXUAL_PROBABILITY_MARK) {
      sexOrient = Person::sexual_orientations::bisexual;
    }

    // make the child persist and send the pointer over
    return new Person(childs_name, sexOrient, gender, "YOKISM", 0.1, 0.1, 0.1, 0.1, 0.1, 1, 1);
  } 

  // no child; this child was never meant to be :(
  return NULL;
}

// TODO: static?
ulli World::get_distance_bw(std::pair<ulli, ulli> point1,
		     std::pair<ulli, ulli> point2) {
  ulli x_diff = std::llabs(point1.first - point2.first);
  ulli y_diff = std::llabs(point1.second - point2.second);
  
  return std::sqrt(std::pow(x_diff, 2) + std::pow(y_diff, 2));
}

void World::make_person_indelible(Person *to_add, unsigned int TYPE) {
  switch (TYPE) {
  case World::people_type::messiah:
    world_messiahs.push_back(to_add);
    break;
  case World::people_type::celeb:
    world_major_celeb_people.push_back(to_add);
    break;
  case World::people_type::scientist:
    world_major_science_people.push_back(to_add);
    break;
  case World::people_type::evil:
    world_major_evil_people.push_back(to_add);
    break;
  case World::people_type::good:
    world_major_evil_people.push_back(to_add);
    break;
  default:
    break;
  }
} 

void World::add_person(Person *to_add) {
  world_living_people.push_back(to_add);
}

void World::kill_person(Person *to_kill, std::string death_reason) {
  std::vector<Person *>::iterator it = std::find(world_living_people.begin(),
						 world_living_people.end(), to_kill);
  world_living_people.erase(it, it + 1);
  to_kill->setEpithet(death_reason);  
  world_graveyard.push_back(to_kill);
}

void World::appoint_messiah(Person *messiah, std::vector<std::string> miracles) {
  for (int i = 0; i < miracles.size(); ++i) {
    messiah->add_miracle_ability(miracles[i]);
  }

  world_messiahs.push_back(messiah);
}

// TODO: Thought: Perform great good complementing function?
// TODO: Better way of organizing people (e.g. by location rather than an enourmous vector?)
void World::perform_dangerous_disaster(ulli x_coord, ulli y_coord, ulli radius) {
  std::vector<Person *> people = get_living_people(); 
  for (int i = 0; i < people.size(); ++i) {
    ulli dist_bw = get_distance_bw(std::make_pair(x_coord, y_coord), people[i]->getLocation());

    if (dist_bw < radius) {
      // TODO: negatively affect this person
    }
  }
}

void update_to_next_generation() {
  
}

World::World() {
}

World::~World() {
  for (int i = 0; i < world_living_people.size(); ++i) {
    delete(world_living_people[i]);
  }
  for (int i = 0; i < world_graveyard.size(); ++i) {
    delete(world_graveyard[i]);
  }
}
