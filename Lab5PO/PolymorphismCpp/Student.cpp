#include "Student.h"

using namespace std;

Student::Student() : Person(), grades(nullptr)
{
  this->grades = new map<string, float>();
}

Student::Student(string firstName, string lastName, string dateOfBirth, string city, string country, string postcode, string state, string streetName, string streetNumber) : Person(firstName, lastName, dateOfBirth, city, country, postcode, state, streetName, streetNumber), grades(nullptr)
{
  if (this->grades == nullptr)
    this->grades = new map<string, float>();
  else
    *(this->grades) = map<string, float>();
}

Student::~Student()
{
  if (this->grades != nullptr)
    delete this->grades;
}

Student::Student(string firstName) : Person(firstName), grades(nullptr)
{
}

Student::Student(const Student &student) : Person(student)
{
  this->grades = student.grades == nullptr ? nullptr : new map<string, float>(*student.grades);
}

Student::Student(Student &&student) : Person(student)
{
  this->grades = move(student.grades);
  student.grades = nullptr;
}

bool Student::checkGrade(string subject)
{
  return this->grades->find(subject) != this->grades->end();
}

void Student::addGrade(string subject, float grade)
{
  if (grade >= 1 && grade <= 5)
  {
    if (!(this->checkGrade(subject)))
      this->grades->insert({subject, grade});
    else
      cout << "Grade already exists" << endl;
  }
  else
  {
    cout << "Invalid grade, must be between 1 and 5." << endl;
  }
}

float Student::getGrade(string subject)
{
  return this->grades->find(subject)->second;
}

map<string, float> &Student::getGrades()
{
  return *(this->grades);
}

void Student::introduce()
{
  // Person::introduce();
  cout << "Personal information: " << endl;
  cout << "First name: " << this->getFirstName() << endl;
  cout << "Last name: " << this->getLastName() << endl;
  cout << "Date of birth: " << this->getDateOfBirth() << endl;
  cout << this->getAddress();
  if (this->grades->size())
  {
    cout << "Grades:" << endl;
    for (auto const &[subject, grade] : *(this->grades))
    {
      cout << subject << ": " << grade << endl;
    }
  }
  else
  {
    cout << "No grades available." << endl;
  }
}