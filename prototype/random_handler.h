#ifndef _RANDOM_HANDLER_H_
#define _RANDOM_HANDLER_H_

#include <random>

class RandomHandler {
 private:
  std::random_device rd;  // seeder function
  std::mt19937 rng;
 public:
  RandomHandler();
  int randint(int incl_min, int incl_max);
  double randdoubl(double incl_min, double incl_max);
};

#endif
