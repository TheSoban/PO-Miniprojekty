#ifndef EMPLOYEE_FACTORY_H
#define EMPLOYEE_FACTORY_H

#include "Employee.h"
#include "PersonFactory.h"

class EmployeeFactory : public PersonFactory
{
public:
  Employee *create();
};

#endif