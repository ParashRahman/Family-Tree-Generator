//
// Created by parash on 28/10/16.
//
#include <iostream>
#include "groups/Marriage.h"
#include "Helpers.h"

int main() {
  Helpers::init_generator();



  Person *p1 = new Person(0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5);
  Person *p2 = new Person(0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6);

  Marriage *marriage = new Marriage();

  marriage->add_person(p1);
  marriage->add_person(p2);

  std::cout << p1->toString() << std::endl;
  std::cout << p2->toString() << std::endl;
}