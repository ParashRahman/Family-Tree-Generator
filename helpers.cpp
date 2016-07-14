#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include "helpers.h"

std::mt19937 Helpers::generator;

void Helpers::init_seed() {
  std::random_device rd;
  int the_seed = rd();
  std::cout << "THE SEED IS: " << the_seed << std::endl;
  generator.seed(the_seed);
}

std::string Helpers::generate_UID() {
  const int uuid_length = 64;
  
  std::string retUID = "";

  for (int i = 0; i < uuid_length; i++) {
    int number = get_random_double(0, 35);
    
    if (number <= 9) {
      // assumes number > 0, but 
      // it doesn't matter much
      std::ostringstream converter;
      converter << number;
 
      retUID += converter.str();
    } else {
      retUID += char('a' + (number - 10));
    }
  }

  return retUID;
}

// returns true if trial by given param prob
// succeeded. else returns false.
bool Helpers::try_probability(double prob) {
  return get_random_double(0, 1) < prob;
}

int Helpers::get_random_int(int low_inclusive, int high_inclusive) {
  // set up randomizer

  /** TODO: GENERATE GETSEED PROPERLY **/
  std::uniform_int_distribution<int> distribution(low_inclusive, high_inclusive);

  return distribution(generator);
}

double Helpers::get_random_double(double low_inclusive, double high_exclusive) {
  std::uniform_real_distribution<double> distribution(low_inclusive, high_exclusive);
  
  return distribution(generator);
}



