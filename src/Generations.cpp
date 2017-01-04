//
// Created by parash on 26/11/16.
//

#include <iostream>

#include "Generations.h"

Generations::Generations() {
  // default distributions set
  this->death_distribution = {0.1, 0.05, 0.05, 0.1, 0.2, 0.5};
  this->procreation_distribution = {0, 0.2, 0.6, 0.2, 0, 0, 0};
}

void Generations::add_new_generation(std::vector<Person *> people) {
  people.insert(people.end(), this->people_container.begin(), this->people_container.end());
  this->people_container = people;
  ++this->generation_number;
}

int Generations::get_num_generations() {
  return this->generation_number;
}

void Generations::set_death_distribution(std::vector<double> distro) {
  if (distro.size() == 0) {
    std::cout << "Generations.cpp: set_death_distribution : distro cannot be empty" << std::endl;
    exit(1);
  }
  this->death_distribution = distro;
}

void Generations::set_procreation_distribution(std::vector<double> distro) {
  if (distro.size() == 0) {
    std::cout << "Generations.cpp: set_procreation_distribution : distro cannot be empty" << std::endl;
    exit(1);
  }
  this->procreation_distribution = distro;
}

std::vector<Person*> Generations::get_intimate_pool() {
  if (this->people_container.size() == 0) {
    return std::vector<Person *>();
  }

  // based on procreation distribution
  int slices = this->procreation_distribution.size();
  int slice_size = this->people_container.size() / slices;

  std::vector<Person *> procreation_pool;

  for (int s = 0; s < slices; s += slice_size) {
    int lower_bound = s;
    int upper_bound = (s + slice_size) < this->people_container.size() ? (s + slice_size) : this-> people_container.size() - 1;
    int distro_index = s / slice_size;

    double probability = this->procreation_distribution[distro_index];

    for (int p = lower_bound; p <= upper_bound; ++p) {
      // if (probability) then add person to procreation pool;
    }
  }
}

std::vector<Person*> Generations::get_and_remove_condemned() {

}

