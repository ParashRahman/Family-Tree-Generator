//
// Created by parash on 28/10/16.
//

#include "Marriage.h"
#include "../Person.h"

void Marriage::update_average(Person *p) {
  auto averageSetters = average->get_setters();
  auto averageGetters = average->get_getters();
  auto pSetters = p->get_setters();
  auto pGetters = p->get_getters();

  // update person
  for (int ps = 0; ps < pertinent_stats.size(); ++ps) {

  }

  // update average

}

void Marriage::augment_person(Person * p) {

}