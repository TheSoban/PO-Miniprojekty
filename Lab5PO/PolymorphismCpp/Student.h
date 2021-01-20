#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <map>
#include "Person.h"

using namespace std;

class Student : public Person
{
protected:
  map<string, float> *grades;

public:
  Student();
  ~Student();
  Student(string firstName);
  Student(const Student &student);
  Student(Student &&student);
  Student(string firstName, string lastName, string dateOfBirth, string city, string country, string postcode, string state, string streetName, string streetNumber);
  bool checkGrade(string subject);
  void addGrade(string subject, float grade);
  float getGrade(string subject);
  map<string, float> &getGrades();
  void introduce();
};

#endif