#ifndef __HELPERS_H__
#define __HELPERS_H__

#include <string>
#include <random>

class Helpers {
 private:
  /* keeps track of the random generation */
  static std::mt19937 generator;
 public:
  static void init_seed();
  static std::string generate_UID();
  static bool try_probability(double prob);
  static int get_random_int(int low_inclusive, int high_inclusive);
  static double get_random_double(double low_inclusive, double high_exclusive);
};

#endif
