#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>

#include "world.h"
#include "person.h"
#include "helpers.h"

typedef unsigned long long int ulli;

ulli WORLD_WIDTH = 1000;
ulli WORLD_HEIGHT = 1000;

ulli NUM_TO_SAMPLE = 100;

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

std::vector<Person *> World::sample_living_people(ulli sample_size){
    ulli population = world_living_people.size();

    if (population <= sample_size)  {
        return world_living_people;
    }

    std::vector<Person *> ret_sample;

    // behave differently for small sample sizes opposed to larger ones
    if (population < 2 * sample_size) {
        std::vector<Person *> people(world_living_people);
        for (int p_i = 0; p_i < sample_size; ++p_i) {
            int random_index = Helpers::get_random_int(0, people.size());

            ret_sample.push_back(world_living_people[random_index]);

            people.erase(people.begin() + random_index, people.begin() + random_index + 1);
        }
    } else {
        std::unordered_set<ulli> sample_indices;

        while (sample_indices.size() < sample_size) {
            int random_index = Helpers::get_random_int(0, world_living_people.size());
            sample_indices.insert(random_index);
        }

        for (auto samp = sample_indices.begin(); samp != sample_indices.end(); ++samp) {
            ret_sample.push_back(world_living_people[*samp]);
        }
    }

    return ret_sample;
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
void World::perform_dangerous_disaster(ulli x_coord, ulli y_coord, ulli radius, std::string disaster_type) {
  std::vector<Person *> people = get_living_people(); 
  for (std::vector<Person *>::size_type i = 0; i < people.size(); ++i) {
    ulli dist_bw = get_distance_bw(std::make_pair(x_coord, y_coord), people[i]->getLocation());

    if (dist_bw < radius) {
      // TODO: negatively affect this person i.e. kill them
      kill_person(people[i], disaster_type);
    }
  }
}

void World::update_to_next_generation() {
  
}

// Private methods for update_to_next_generation //
void World::update_rates() {
  std::vector<Person *> sample = sample_living_people(NUM_TO_SAMPLE);

  // these counters are for the following respectively:
  //  - scientific achievements
  //  - miracles set upon the world
  //  - other significant achievements (good, evil, celeb)
  ulli count_sci, count_mir, count_sig = 0;

  double average_ability = 0;
  ulli n_ability = 0;
  double average_economic = 0;
  ulli n_economic = 0;
  double average_health = 0;
  ulli n_health = 0;
  double average_social = 0;
  ulli n_social = 0;

  for (auto samp = sample.begin(); samp != sample.end(); ++samp) {
    count_sci += (*samp)->getScienceHistory().size();
    count_mir += (*samp)->getMiracleHistory().size();
    count_sig += (*samp)->getCelebHistory().size() + (*samp)->getGoodHistory().size() + (*samp)->getEvilHistory().size();

    average_ability = (average_ability  * n_ability) / (n_ability + 1) + ((*samp) -> getAbility() / (n_ability + 1));
    ++n_ability;
    average_health = (average_health  * n_health) / (n_health + 1) + ((*samp) -> getHealthStatus() / (n_health + 1));
    ++n_health;
    average_economic = (average_economic  * n_economic) / (n_economic + 1) + ((*samp) -> getEconomicStatus() / (n_economic + 1));
    ++n_economic;
    average_social = (average_social  * n_social) / (n_social + 1) + ((*samp) -> getSocialStatus() / (n_social + 1));
    ++n_social;
  }


  // TODO: Perhaps make these rates based on more sophisticated calculations
  //rate_of_world_technology based on scientific progress
  rate_of_world_technology = log2(count_sci) / log2(world_living_people.size());
  //rate_of_world_economics based on economic status of people
  rate_of_world_health = (average_health + average_ability) / 2;
  //rate_of_world_health based on health status of people
  rate_of_world_economics = average_economic;


  // TODO: place holder calculations inputted. Determine a solid measurement of rates
  int ARBITRARY = 3;
  // death_rate based on health rate (not economic)...maybe.
  death_rate = rate_of_world_health < 1 ? rate_of_world_health : 1 / rate_of_world_health;
  // birth_rate based on health rate (not economic)...maybe.
  birth_rate = ARBITRARY * death_rate;
}
void World::mate_all_the_people() {
  std::vector<Person *> males, females, transgenders;

  for (auto person = world_living_people.begin(); person != world_living_people.end(); ++person) {
    switch ((*person)->getGender()) {
    case Person::genders::male:
      males.push_back((*person));
      break;
    case Person::genders::female:
      females.push_back((*person));
      break;
    case Person::genders::transgender:
      transgenders.push_back((*person));
      break;
    default:
      break;
    }
  }


}
void World::kill_all_the_people(std::string reason) {
  std::vector<Person *> people = get_living_people();
  
  for (std::vector<Person *>::size_type i = 0; i < people.size(); ++i) {
    kill_person(people[i], reason);
  }
}
void World::update_people_connections() {
  
} 
void World::update_accomplishments() {
  
} 
void World::update_people_statistics() {
  
}
void World::update_people_locations() {
  
}
// END: Private methods for update_to_next_generation() //


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
