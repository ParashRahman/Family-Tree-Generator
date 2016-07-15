#include <iostream>
#include <string>
#include "person.h"
#include "helpers.h"

int main()  {
  Helpers::init_generator();
  
  std::cout << Person::generate_name(5) << std::endl;
}
