#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Address.h"

using namespace std;

class Person
{
protected:
  string *firstName;
  string *lastName;
  string *dateOfBirth;
  Address *address;

public:
  Person();
  Person(string firstName, string lastName, string dateOfBirth, string city, string country, string postcode, string state, string streetName, string streetNumber);
  virtual ~Person();
  Person(string firstName);
  Person(const Person &person);
  Person(Person &&person);
  string getFirstName();
  void setFirstName(string firstName);
  string getLastName();
  void setLastName(string lastName);
  string getDateOfBirth();
  void setDateOfBirth(string dateOfBirth);
  string getAddress();
  void setAddress(string city, string country, string postcode, string state, string streetName, string streetNumber);
  virtual void introduce() = 0;
  // virtual void introduce();
  static bool validateDate(string dateOfBirth);
};

#endif