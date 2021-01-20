#ifndef STUDENT_FACTORY_H
#define STUDENT_FACTORY_H

#include "Student.h"
#include "PersonFactory.h"

class StudentFactory : public PersonFactory
{
public:
  Student *create();
};

#endif