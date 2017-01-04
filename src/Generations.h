//
// Created by parash on 26/11/16.
//

#ifndef GS_GENERATION_H
#define GS_GENERATION_H

#include <vector>
#include "Person.h"

class Generations {
private:
  int generation_number = 0;

  std::vector<Person *> people_container;
  std::vector<double> death_distribution;
  std::vector<double> procreation_distribution;
public:
  Generations();

  // the people who will die this generation
  std::vector<Person*> get_and_remove_condemned();

  // the people who will make the next generation
  std::vector<Person*> get_intimate_pool();

  // the people who are the next generation
  void add_new_generation(std::vector<Person *>);

  int get_num_generations();
  void set_death_distribution(std::vector<double>);  // expect heavily favored for older gen
  void set_procreation_distribution(std::vector<double>);  // expect a normal/chi square/poisson dist
};


#endif //GS_GENERATION_H
