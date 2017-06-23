//
// Created by parash on 28/10/16.
//

#include "../Person.h"
#include "Group.h"

void Group::add_person(Person *p) {
  augment_person(p);
  this->people.push_back(p);
}

void Group::augment_person(Person *p) {}