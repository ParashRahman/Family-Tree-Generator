#include <iostream>
#include <string>
#include <vector>
#include <cstring> // for memcpy
#include <utility>

#include "person.h"
#include "helpers.h"

typedef unsigned long long int ulli;

const std::vector<std::string> Person::name_parts = {
    "ai", "ao", "bi", "bo", "be", "po", "pa", 
    "la", "hi", "he", "ha", "shi", "sho", "sha",
    "ri", "bor", "bar", "na", "an", "is", "wa", 
    "hi", "da", "rah", "man", "mo", "hu"
  };

std::string Person::generate_name(int syllables) {
  // concatenate the random syllables together
  std::string retName = "";
  for (int i = 0; i < syllables; i++) {
    int name_part_index = Helpers::get_random_int(0, name_parts.size() - 1);
    retName += name_parts[name_part_index];
  }

  // wallah, you get the the name
  return retName;
}

bool Person::check_sympatico_p1_to_p2(const Person *p1, const Person *p2) {
  // Helper method to check if p1
  // could love p2

  if ( (p2->getGender() == Person::genders::transgender &&
	p1->getSexOrient() == Person::sexual_orientations::other) ) {
    return true;
  }

  if ( (p2->getGender() == Person::genders::male ||
	p2->getGender() == Person::genders::female) &&
       (p1->getGender() == Person::genders::male ||
	p1->getGender() == Person::genders::female) ) {
    if ( p1->getSexOrient() == Person::sexual_orientations::bisexual || 
	 (p1->getGender() != p2->getGender() &&
	  p1->getSexOrient() == Person::sexual_orientations::straight) ||
	 (p1->getGender() == p2->getGender() &&
	  p1->getSexOrient() == Person::sexual_orientations::homosexual) ) {
      return true;
    }
  }

  return false;
}

float Person::love_probability (const Person *p1, const Person *p2) {
  float p1lovesp2;
  float p2lovesp1;

  const float SYMPATICO = 0.95;
  const float NONSYMPATICO = 0.2;
  const float DIFFRELIGIONPENALTY = 0.1;

  if (check_sympatico_p1_to_p2(p1, p2)) {
    p1lovesp2 = SYMPATICO;
  } else {
    p1lovesp2 = NONSYMPATICO;
  }

  if (check_sympatico_p1_to_p2(p2, p1)) {
    p2lovesp1 = SYMPATICO;
  } else {
    p2lovesp1 = NONSYMPATICO;
  }

  if (p1->getReligion() != p2->getReligion()) {
    p1lovesp2 -= DIFFRELIGIONPENALTY;
    p2lovesp1 -= DIFFRELIGIONPENALTY;
  }

  return p2lovesp1 < p1lovesp2 ? p2lovesp1 : p1lovesp2;
}

bool Person::check_mateability(const Person *p1, const Person *p2) {
  if (p1->getGender() != p2->getGender()) {
    return true;
  }
  return false;
}

Person::Person(std::string personName, int sex_orient, int gend,
	       std::string relig, double econStatus, double religStatus,
	       double socStatus, double healthStatus, double abilStatus,
	       ulli x_coord, ulli y_coord) {
  name = personName;

  generational_age = 0;
  epithet = "";

  UID = Helpers::generate_UID();
  gender = gend;
  sex_orientation = sex_orient; 
  religion = relig;
  economic_status = econStatus;
  religious_status = religStatus;
  social_status = socStatus;
  health_status = healthStatus;
  ability = abilStatus;
  location_x = x_coord;
  location_y = y_coord;
}

std::string Person::getName() const{
  return name;
}

std::string Person::getUID() const{
  return UID;
}

unsigned int Person::getGender() const{
  return gender;
}

unsigned int Person::getSexOrient() const{
  return sex_orientation;
}

double Person::getAbility() const {
  return ability;
}

std::string Person::getReligion() const {
  return religion;
}

double Person::getReligiousStatus() const {
  return religious_status;
}

double Person::getEconomicStatus() const {
  return economic_status;
}

double Person::getHealthStatus() const {
  return health_status;
}

double Person::getSocialStatus() const {
  return social_status;
}

ulli Person::getLocationX() const { 
  return location_x;
}

ulli Person::getLocationY() const {
  return location_y;
}

std::pair<ulli, ulli> Person::getLocation() const {
  return std::pair<ulli, ulli> (location_x, location_y);
}

std::string Person::getEpithet() const {
  return epithet;
}

std::vector<std::string> Person::getMiracleAbilities() const {
  return miracle_abilities;
}

std::vector<std::string> Person::getMiracleHistory() const {
  return miracles_observed;
}

std::vector<std::string> Person::getScienceHistory() const {
  return scientific_achievements;
}

std::vector<std::string> Person::getCelebHistory() const {
  return celeb_achievements;
}

std::vector<std::string> Person::getGoodHistory() const {
  return good_achievements;
}

std::vector<std::string> Person::getEvilHistory() const {
  return evil_achievements;
}

int Person::getGenerationalAge() const {
  return generational_age;
}

void Person::setReligion(std::string relig) {
  religion = relig;
}

void Person::setReligiousStatus(double stat) {
  religious_status = stat;
}

void Person::setEpithet(std::string message) {
  epithet = message;
}

void Person::setAbility(double stat) {
  ability = stat;
}

void Person::setEconomicStatus(double stat) {
  economic_status = stat;
}

void Person::setHealthStatus(double stat) {
  health_status = stat;
}

void Person::setSocialStatus(double stat) {
  social_status = stat;
}

void Person::receive_miracle(std::string miracle)  {
  // miracles_observed will always be unique
  for (int i = 0; i < miracles_observed.size(); ++i) {
    if (miracles_observed[i] == miracle) {
      return;
    }
  }

  miracles_observed.push_back(miracle);
}

void Person::increase_generational_age() {
  ++generational_age;
}

void Person::add_miracle_ability(std::string ability) {
  // miraculous abilities are unique

  for (int i = 0; i < miracle_abilities.size(); ++i) {
    if (miracle_abilities[i] == ability) {
      return;
    }
  }

  miracle_abilities.push_back(ability);
}

std::string Person::toString() {
  return "name: " + name + " UID: " + UID + " orient: "
    + std::to_string(sex_orientation) + " gender: " + std::to_string(gender)
    + " religion: " + religion + " estat: " + std::to_string(economic_status)
    + " hstat: " + std::to_string(health_status) + " rstat: "
    + std::to_string(religious_status) + " sstat: "
    + std::to_string(social_status) + " abil: " + std::to_string(ability);
}
