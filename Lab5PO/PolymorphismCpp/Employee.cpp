#include "Employee.h"

using namespace std;

Employee::Employee() : Person(), subjects(nullptr)
{
  this->subjects = new vector<string>();
}

Employee::Employee(string firstName, string lastName, string dateOfBirth, string city, string country, string postcode, string state, string streetName, string streetNumber) : Person(firstName, lastName, dateOfBirth, city, country, postcode, state, streetName, streetNumber), subjects(nullptr)
{
  this->subjects = new vector<string>();
}

Employee::~Employee()
{
  if (this->subjects != nullptr)
    delete this->subjects;
}

Employee::Employee(string firstName) : Person(firstName), subjects(nullptr)
{
}

Employee::Employee(const Employee &employee) : Person(employee)
{
  this->subjects = employee.subjects == nullptr ? nullptr : new vector<string>(*employee.subjects);
}

Employee::Employee(Employee &&employee) : Person(employee)
{
  this->subjects = move(employee.subjects);
  employee.subjects = nullptr;
}

bool Employee::checkSubject(string subject)
{
  return find(this->subjects->begin(), this->subjects->end(), subject) != this->subjects->end();
}

void Employee::addSubject(string subject)
{
  if (!(this->checkSubject(subject)))
    this->subjects->push_back(subject);
}

void Employee::removeSubject(string subject)
{
  if (this->checkSubject(subject))
    this->subjects->erase(remove(this->subjects->begin(), this->subjects->end(), subject), this->subjects->end());
}

vector<string> &Employee::getSubjects()
{
  return *(this->subjects);
}

void Employee::introduce()
{
  // Person::introduce();
  cout << "Personal information: " << endl;
  cout << "First name: " << this->getFirstName() << endl;
  cout << "Last name: " << this->getLastName() << endl;
  cout << "Date of birth: " << this->getDateOfBirth() << endl;
  cout << this->getAddress();
  if (this->subjects->size())
  {
    cout << "Subjects:" << endl;
    for (string const &subject : *(this->subjects))
    {
      cout << subject << endl;
    }
  }
  else
  {
    cout << "No subjects available." << endl;
  }
}