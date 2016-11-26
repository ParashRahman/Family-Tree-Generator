//
// Created by parash on 25/11/16.
//

#include <iostream>
#include <string>
#include <sstream>

#include "Helpers.h"

std::mt19937 Helpers::generator;

void Helpers::init_generator() {
  std::random_device rd;
  int the_seed = rd();
  std::cout << "THE SEED IS: " << the_seed << std::endl;
  generator.seed(the_seed);
}

int Helpers::get_random_int(int low_inclusive, int high_inclusive) {
  std::uniform_int_distribution<int> distribution(low_inclusive, high_inclusive);

  return distribution(generator);
}

double Helpers::get_random_double(double low_inclusive, double high_exclusive) {
  std::uniform_real_distribution<double> distribution(low_inclusive, high_exclusive);

  return distribution(generator);
}


std::string Helpers::convertIntegerToString(int toConvert) {
  std::stringstream ss;
  ss << toConvert;
  return ss.str();
}

std::string Helpers::convertDoubleToString(double toConvert) {
  std::stringstream ss;
  ss << toConvert;
  return ss.str();
}