//
// Created by parash on 28/10/16.
//
#include <iostream>
#include "groups/Marriage.h"

int main() {
  std::cout << "Hello World" << std::endl;

  Person *p1 = new Person();
  Person *p2 = new Person();

  Marriage *marriage = new Marriage();

  marriage->add_person(p1);

}