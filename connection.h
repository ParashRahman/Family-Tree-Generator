#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include "person.h"

/* a connection is between two people 
   and its strength is determined by the power
   attribute */
class Connection {
 public:
  Connection(Person *p1, Person *p2, double pow);
  double get_power();
  Person *get_person1();
  Person *get_person2();
 private:
  double power; /* the strength of the connection */
  Person *person1;
  Person *person2;
};

#endif
