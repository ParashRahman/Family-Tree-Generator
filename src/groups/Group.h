//
// Created by parash on 28/10/16.
//

#ifndef GS_GROUP_H
#define GS_GROUP_H

#include <vector>

#include "../Person.h"

class Group {
private:
  std::vector<Person *> people;

public:

  void add_person(Person *p);
  void augment_person(Person *p);
};


#endif //GS_GROUP_H
