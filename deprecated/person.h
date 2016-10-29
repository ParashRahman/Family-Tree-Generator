#ifndef __PERSON_H__
#define __PERSON_H__

#include <vector>
#include <string>
#include <random>
#include <utility>
#include "helpers.h"

typedef unsigned long long int ulli;

/* 
   TODO: science stat 
   TODO: generational history
   TODO: emotional average 
*/

class Person {
 public:
  // Constants
  enum sexual_orientations : unsigned int {
    straight = 0,
    homosexual = 1,
    bisexual = 2,
    other = 3
  };
  enum genders : unsigned int { 
    male = 0,
    female = 1,
    transgender = 2
  };

  static const std::vector<std::string> name_parts;
  static std::string generate_name(int syllables);
  static float love_probability (const Person *p1,
				 const Person *p2); 
  static bool check_sympatico_p1_to_p2(const Person *p1, const Person *p2);
  static bool check_mateability(const Person *p1, const Person *p2);
  Person(std::string personName, int sex_orient, int gend,
	 std::string relig, double econStatus, double religStatus,
	 double socStatus, double healthStatus, double abilStatus,
	 ulli x_coord, ulli y_coord);

  // getters
  std::string getName() const;
  std::string getUID() const;
  unsigned int getGender() const;
  unsigned int getSexOrient() const;
  std::string getReligion() const;
  double getReligiousStatus() const;
  double getAbility() const;
  double getEconomicStatus() const;
  double getHealthStatus() const;
  double getSocialStatus() const;
  ulli getLocationX() const;
  ulli getLocationY() const;
  std::pair<ulli, ulli> getLocation() const;
  int getGenerationalAge() const;
  std::vector<std::string> getMiracleAbilities() const;
  std::vector<std::string> getMiracleHistory() const;
  std::string getEpithet() const;
  std::vector<std::string> getScienceHistory() const;
  std::vector<std::string> getCelebHistory() const;
  std::vector<std::string> getGoodHistory() const;
  std::vector<std::string> getEvilHistory() const;

  // setters
  void setEpithet(std::string message);
  void setReligion(std::string relig);
  void setReligiousStatus(double stat);
  void setAbility(double stat);
  void setEconomicStatus(double stat);
  void setHealthStatus(double stat);
  void setSocialStatus(double stat);
  void setLocationX(ulli x);
  void setLocationY(ulli y);

  void increase_generational_age();
  void receive_miracle(std::string miracle);
  void add_miracle_ability(std::string ability);

  std::string toString();

 private:
  std::string name;
  std::string UID;
  std::vector<Person> peopleKnown;
  int sex_orientation;
  int gender;
  double economic_status;
  double health_status;
  double religious_status;
  double social_status;
  double ability;
  ulli location_x;
  ulli location_y;  
  int generational_age;
  std::string religion;

  // book keeping of the person
  std::vector<std::string> miracle_abilities; // collection of miracles this person can perform onto others
  std::vector<std::string> miracles_observed; // history of miracles cast on this individual
  std::vector<std::string> scientific_achievements;
  std::vector<std::string> celeb_achievements;
  std::vector<std::string> good_achievements;
  std::vector<std::string> evil_achievements;
  std::string epithet;
};

#endif

