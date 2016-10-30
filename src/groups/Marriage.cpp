//
// Created by parash on 28/10/16.
//

#include "Marriage.h"
#include "../Person.h"

void Marriage::augment_person(Person *p) {
  auto averageSetters = average->get_setters();
  auto averageGetters = average->get_getters();
  auto pSetters = p->get_setters();
  auto pGetters = p->get_getters();

  ++n;

  // update average
  for (int ps = 0; ps < pertinent_stats.size(); ++ps) {
    auto avgget = averageGetters[ps];
    auto avgset = averageSetters[ps];
    auto pget = pGetters[ps];

    avgset(avgget() + ((pget()) - avgget()) / n);
  }

  // update person
  for (int ps = 0; ps < pertinent_stats.size(); ++ps) {
    auto pget = pGetters[ps];
    auto pset = pSetters[ps];
    auto avgget = averageGetters[ps];

    pset((avgget() + pget())/2);
  }
}

Marriage::Marriage() {
  average = new Person();
  n = 0;
}

Marriage::~Marriage() {
  delete(average);
}