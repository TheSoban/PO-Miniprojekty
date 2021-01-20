#include "EmployeeFactory.h"

Employee *EmployeeFactory::create()
{
  return new Employee();
}