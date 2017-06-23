#include <string>

#include "name_generator.h"
#include "random_handler.h"

const int NameGenerator::num_syllables_min = 2;
const int NameGenerator::num_syllables_max = 5;
std::vector<std::string> NameGenerator::syllables = {"pa", "rash", "ti", "ko", "kal", "vin", "da", "loo"};

std::string NameGenerator::get_random_name() {
  RandomHandler rh;

  std::string name = "";
  int name_length = rh.randint(num_syllables_min, num_syllables_max);
  for (int s = 0; s < name_length; ++s) {
    name += syllables[rh.randint(0, syllables.size() - 1)];
  }

  return name;
}
