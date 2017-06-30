#include <iostream>

#include "family_tree.h"
#include "person.h"

int main() {
  FamilyTree ft;
  std::cout << ft.toString() << std::endl;
  ft.visit_person(1);
  std::cout << "----------" << std::endl;
  std::cout << ft.toString() << std::endl;
}
