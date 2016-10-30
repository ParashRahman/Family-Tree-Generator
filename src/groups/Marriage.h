//
// Created by parash on 28/10/16.
//

#ifndef GS_MARRIAGE_H
#define GS_MARRIAGE_H

#include <vector>

#include "Group.h"
#include "../Person.h"

class Marriage : Group {
private:
  ~Marriage();

  std::vector<int> pertinent_stats = {
    Person::stats::HEALTH,
    Person::stats::EMOTION,
    Person::stats::SOCIAL,
    Person::stats::ABILITY,
    Person::stats::FERTILITY
  };

  Person *average;
  int n;
public:
  Marriage();
  void augment_person(Person *p);
};


#endif //GS_MARRIAGE_H