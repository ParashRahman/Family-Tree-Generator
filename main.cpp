#include <iostream>
#include <string>
#include "person.h"
#include "helpers.h"

int main()  {
  Helpers::init_seed();
  /*
  std::string randomName1 = Person::generate_name(3);
  std::string randomName2 = Person::generate_name(4);
  unsigned int str8 = Person::sexual_orientations::straight;
  unsigned int male = Person::genders::male;
  unsigned int female = Person::genders::female;

  Person james(randomName1, str8, male, "YOKISM", 0.1, 0.1, 0.1, 0.1);
  Person jamie(randomName2, str8, female, "YOKISM", 0.1, 0.1, 0.1, 0.1);

  std::cout << jamie.toString() << std::endl;
  std::cout << james.toString() << std::endl;

  Person *child = Person::mate_people(&james, &jamie, Person::generate_name(2));
  
  if (child == NULL) {
    std::cout << "ABORTED" << std::endl;
    return 0;
  } 

  std::cout << child->toString() << std::endl;
  */
}
