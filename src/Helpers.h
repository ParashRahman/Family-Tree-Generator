//
// Created by parash on 25/11/16.
//

#ifndef GS_HELPERS_H
#define GS_HELPERS_H

#include <string>
#include <random>

class Helpers {
private:
  static std::mt19937 generator;
public:
  static void init_generator();
  static int get_random_int(int low_inclusive, int high_inclusive);
  static double get_random_double(double low_inclusive, double high_exclusive);

  static std::string convertDoubleToString(double toConvert);
  static std::string convertIntegerToString(int toConvert);
};


#endif //GS_HELPERS_H
