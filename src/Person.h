//
// Created by parash on 28/10/16.
//

#ifndef GS_PERSON_H
#define GS_PERSON_H

#include <vector>
#include <string>
#include <functional>
#include <string>

typedef std::function<void(double)> setter;
typedef std::function<double()> getter;

class Person {
private:
  // all stats are from 0 to 1
  double hormones; // 0 testostrone to 1 estrogen
  double sexuality; // 0 hetero to 1 homo
  double health; // physcial health
  double emotion; // emotional intelligence
  double social; // social talent
  double ability; // talent
  double fertility; // willingness to have kids

  std::string first_name;
  std::string last_name;

  // recorded achievements
  std::vector<std::string> celebrityism;
  std::vector<std::string> horror;
  std::vector<std::string> honor;
  std::vector<std::string> science;
  std::vector<std::string> religious_achievements;

  std::vector<getter> getters;
  std::vector<setter> setters;

public:
  enum stats : unsigned int {
    HORMONES = 0,
    SEXUALITY = 1,
    HEALTH = 2,
    EMOTION = 3,
    SOCIAL = 4,
    ABILITY = 5,
    FERTILITY = 6
  };

  std::vector<getter> get_getters();
  std::vector<setter> get_setters();
  double getHormones() const;
  void setHormones(double hormones);
  double getSexuality() const;
  void setSexuality(double sexuality);
  double getHealth() const;
  void setHealth(double health);
  double getEmotion() const;
  void setEmotion(double emotion);
  double getSocial() const;
  void setSocial(double social);
  double getAbility() const;
  void setAbility(double ability);
  double getFertility() const;
  void setFertility(double fertility);
  const std::vector<std::string> &getCelebrityism() const;
  void setCelebrityism(const std::vector<std::string> &celebriyism);
  const std::vector<std::string> &getHorror() const;
  void setHorror(const std::vector<std::string> &horror);
  const std::vector<std::string> &getHonor() const;
  void setHonor(const std::vector<std::string> &honor);
  const std::vector<std::string> &getScience() const;
  void setScience(const std::vector<std::string> &science);
  const std::vector<std::string> &getReligious_achievements() const;
  void setReligious_achievements(const std::vector<std::string> &religious_achievements);

  std::string toString();
};


#endif //GS_PERSON_H
