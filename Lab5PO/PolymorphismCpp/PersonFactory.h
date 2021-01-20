#ifndef PERSON_FACTORY_H
#define PERSON_FACTORY_H

#include "Person.h"

class PersonFactory
{
public:
  virtual Person *create() = 0;
};

#endif