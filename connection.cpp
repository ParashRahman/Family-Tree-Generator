#include "connection.h"
#include "person.h"

/* TODO: Consider sort by power */

Connection::Connection(Person *p1, Person *p2, double pow) {
  person1 = p1;
  person2 = p2;
  power = pow;
}

Person *Connection::get_person1() {
  return person1;
}

Person *Connection::get_person2() {
  return person2;
}

double Connection::get_power() {
  return power;
}
