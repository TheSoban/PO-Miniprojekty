#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <vector>
#include <algorithm>
#include "Person.h"

using namespace std;

class Employee : public Person
{
protected:
  vector<string> *subjects;

public:
  Employee();
  Employee(string firstName, string lastName, string dateOfBirth, string city, string country, string postcode, string state, string streetName, string streetNumber);
  ~Employee();
  Employee(string firstName);
  Employee(const Employee &employee);
  Employee(Employee &&employee);
  vector<string> &getSubjects();
  void addSubject(string subject);
  void removeSubject(string subject);
  bool checkSubject(string subject);
  void introduce();
};

#endif