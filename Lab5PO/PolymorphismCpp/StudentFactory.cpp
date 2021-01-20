#include "StudentFactory.h"

Student *StudentFactory::create()
{
  return new Student();
}