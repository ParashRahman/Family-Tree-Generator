#include <random>

#include "random_handler.h"

RandomHandler::RandomHandler() {
  rng.seed(rd());
}

int RandomHandler::randint(int incl_min, int incl_max) {
  std::uniform_int_distribution<int> uni(incl_min, incl_max);

  return uni(rng);
}

double RandomHandler::randdoubl(double incl_min, double incl_max) {
  std::uniform_real_distribution<double> uni(incl_min, incl_max);

  return uni(rng);
}
