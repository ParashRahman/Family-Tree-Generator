//
// Created by parash on 28/10/16.
//

#include <functional>
#include <vector>

#include "Helpers.h"
#include "Person.h"

typedef std::function<void(double)> setter;
typedef std::function<double()> getter;

#define MINIMUM_EBB -0.01
#define MAXIMUM_EBB 0.01

/////////////////////////////
// VALUE OF STATS ARE DETERMINED BY THIS:
// min(1 / (1 - stat), MAX_INT)
/////////////////////////////

double Person::evolutionary_ebb() {
  return Helpers::get_random_double(MINIMUM_EBB, MAXIMUM_EBB);
}

void Person::limit_statistics() {
  auto getters = this->get_getters();
  auto setters = this->get_setters();

  for (int g = 0; g < getters.size(); ++g) {
    double statistic = getters[g]();

    statistic = statistic < 0 ? 0 : statistic;
    statistic = statistic > 1 ? 1 : statistic;

    setters[g](statistic);
  }
}

Person::Person(double hormones, double sexuality, double health, double emotion,
               double social, double ability, double fertility) {
  this->hormones = hormones + evolutionary_ebb();
  this->sexuality = sexuality + evolutionary_ebb();
  this->health = health + evolutionary_ebb();
  this->emotion = emotion + evolutionary_ebb();
  this->social = social + evolutionary_ebb();
  this->ability = ability + evolutionary_ebb();
  this->fertility = fertility + evolutionary_ebb();

  limit_statistics();
}

std::vector<getter> Person::get_getters() {
  std::vector<getter> getters = {
    std::bind(&Person::getHormones, this),
    std::bind(&Person::getSexuality, this),
    std::bind(&Person::getHealth, this),
    std::bind(&Person::getEmotion, this),
    std::bind(&Person::getSocial, this),
    std::bind(&Person::getAbility, this),
    std::bind(&Person::getFertility, this)
  };

  return getters;
}

std::vector<setter> Person::get_setters() {
  std::vector<setter> setters = {
    std::bind(&Person::setHormones, this, std::placeholders::_1),
    std::bind(&Person::setSexuality, this, std::placeholders::_1),
    std::bind(&Person::setHealth, this, std::placeholders::_1),
    std::bind(&Person::setEmotion, this, std::placeholders::_1),
    std::bind(&Person::setSocial, this, std::placeholders::_1),
    std::bind(&Person::setAbility, this, std::placeholders::_1),
    std::bind(&Person::setFertility, this, std::placeholders::_1)
  };

  return setters;
}

double Person::getHormones() const {
  return hormones;
}

void Person::setHormones(double hormones) {
  Person::hormones = hormones;
}

double Person::getSexuality() const {
  return sexuality;
}

void Person::setSexuality(double sexuality) {
  Person::sexuality = sexuality;
}

double Person::getHealth() const {
  return health;
}

void Person::setHealth(double health) {
  Person::health = health;
}

double Person::getEmotion() const {
  return emotion;
}

void Person::setEmotion(double emotion) {
  Person::emotion = emotion;
}

double Person::getSocial() const {
  return social;
}

void Person::setSocial(double social) {
  Person::social = social;
}

double Person::getAbility() const {
  return ability;
}

void Person::setAbility(double ability) {
  Person::ability = ability;
}

double Person::getFertility() const {
  return fertility;
}

void Person::setFertility(double fertility) {
  Person::fertility = fertility;
}

const std::vector<std::string> &Person::getCelebrityism() const {
  return celebrityism;
}

void Person::setCelebrityism(const std::vector<std::string> &celebriyism) {
  Person::celebrityism = celebriyism;
}

const std::vector<std::string> &Person::getHorror() const {
  return horror;
}

void Person::setHorror(const std::vector<std::string> &horror) {
  Person::horror = horror;
}

const std::vector<std::string> &Person::getHonor() const {
  return honor;
}

void Person::setHonor(const std::vector<std::string> &honor) {
  Person::honor = honor;
}

const std::vector<std::string> &Person::getScience() const {
  return science;
}

void Person::setScience(const std::vector<std::string> &science) {
  Person::science = science;
}

const std::vector<std::string> &Person::getReligious_achievements() const {
  return religious_achievements;
}

void Person::setReligious_achievements(const std::vector<std::string> &religious_achievements) {
  Person::religious_achievements = religious_achievements;
}

std::string Person::toString() {
  std::string to_return = "";

  auto getters = get_getters();


  //TODO: string conversion
  for (int i = 0; i < getters.size(); ++i) {
    to_return += "property " + Helpers::convertIntegerToString(i) + ": " + Helpers::convertDoubleToString(getters[i]()) + "\n";
  }

  return to_return;
}