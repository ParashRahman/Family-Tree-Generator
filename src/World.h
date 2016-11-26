//
// Created by parash on 25/11/16.
//

#ifndef GS_WORLD_H
#define GS_WORLD_H

#include "Person.h"

class World {
private:
  int generation_count = 0;
  std::

public:
  void birth_person(Person *to_add);
  void kill_person(Person *to_kill);
};


#endif //GS_WORLD_H
