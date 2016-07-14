#ifndef __PRAYERS_H__
#define __PRAYERS_H__

#include <vector>
#include <string>

/* A prayer/wish generator class */

class Prayers {
 private:
  /* FOR PEOPLE'S SOCIAL DESIRES */
  std::string social_desire_prefix = "I wish ";
  std::vector<std::string> social_desires { "taken seriously", "to be in control", "to have my niche", "to have a purpose", "to connect with others", "to belong", "for something exciting", "for love", "to have a bigger dick" };
  
  /* FOR PEOPLE'S ECONOMIC DESIRES */
  std::string economic_desire_prefix = "I wish to have ";
  std::vector<std::string> economic_desires { "more money", "a better car", "more business", "less bills" };
  
  /* FOR PEOPLE'S RELIGIOUS DESIRES */
  
  
  /* FOR PEOPLE'S HEALTH DESIRES */
};

#endif
