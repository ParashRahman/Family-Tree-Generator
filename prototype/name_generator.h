#ifndef _NAME_GENERATOR_H_
#define _NAME_GENERATOR_H_

#include <string>
#include <vector>

class NameGenerator {
 private:
  static std::vector<std::string> syllables; 
  static const int num_syllables_min;
  static const int num_syllables_max;

 public:
  static std::string get_random_name();
  
};

#endif
