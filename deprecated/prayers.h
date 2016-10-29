#ifndef __PRAYERS_H__
#define __PRAYERS_H__

#include <vector>
#include <string>

/* A prayer/wish generator class */

class Prayers {
 private:
  /* FOR PEOPLE'S SOCIAL DESIRES */
  static std::string social_desire_prefix;
  static std::vector<std::string> social_desires;
  
  /* FOR PEOPLE'S ECONOMIC DESIRES */
  static std::string economic_desire_prefix;
  static std::vector<std::string> economic_desires;

  /* FOR PEOPLE'S RELIGIOUS DESIRES */
  static std::string religious_desire_prefix;
  static std::vector<std::string> religious_desires;
  
  /* FOR PEOPLE'S HEALTH DESIRES */
  static std::string health_desire_prefix;
  static std::vector<std::string> health_desires;

 public:
  static std::string get_random_social_desire();
  static std::string get_random_economic_desire();
  static std::string get_random_religious_desire();
  static std::string get_random_health_desire();
};

#endif
