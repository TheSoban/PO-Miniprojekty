#include "Person.h"

using namespace std;

Person::Person() : firstName(nullptr),
                   lastName(nullptr),
                   dateOfBirth(nullptr),
                   address(nullptr)
{
  this->firstName = new string();
  this->lastName = new string();
  this->dateOfBirth = new string();
  this->address = new Address("", "", "", "", "", "");
}

Person::Person(string firstName, string lastName, string dateOfBirth, string city, string country, string postcode, string state, string streetName, string streetNumber) : firstName(nullptr),
                                                                                                                                                                            lastName(nullptr),
                                                                                                                                                                            dateOfBirth(nullptr),
                                                                                                                                                                            address(nullptr)
{
  this->setFirstName(firstName);
  this->setLastName(lastName);
  this->setDateOfBirth(dateOfBirth);
  this->setAddress(city, country, postcode, state, streetName, streetNumber);
}

Person::~Person()
{
  if (this->firstName != nullptr)
    delete this->firstName;
  if (this->lastName != nullptr)
    delete this->lastName;
  if (this->dateOfBirth != nullptr)
    delete this->dateOfBirth;
  if (this->address != nullptr)
    delete this->address;
}

Person::Person(string firstName) : firstName(nullptr),
                                   lastName(nullptr),
                                   dateOfBirth(nullptr),
                                   address(nullptr)
{
  if (this->firstName == nullptr)
    this->firstName = new string(firstName);
  else
    *(this->firstName) = firstName;
}

Person::Person(const Person &person)
{
  this->firstName = person.firstName == nullptr ? nullptr : new string(*person.firstName);
  this->lastName = person.lastName == nullptr ? nullptr : new string(*person.lastName);
  this->dateOfBirth = person.dateOfBirth == nullptr ? nullptr : new string(*person.dateOfBirth);
  this->address = person.address == nullptr ? nullptr : new Address(*person.address);
}

Person::Person(Person &&person)
{
  this->firstName = move(person.firstName);
  this->lastName = move(person.lastName);
  this->dateOfBirth = move(person.dateOfBirth);
  this->address = move(person.address);
  person.firstName = nullptr;
  person.lastName = nullptr;
  person.dateOfBirth = nullptr;
  person.address = nullptr;
}

string Person::getFirstName()
{
  return *(this->firstName);
}

void Person::setFirstName(string firstName)
{
  if (this->firstName == nullptr)
    this->firstName = new string(firstName);
  else
    *(this->firstName) = firstName;
}

string Person::getLastName()
{
  return *(this->lastName);
}

void Person::setLastName(string lastName)
{
  if (this->lastName == nullptr)
    this->lastName = new string(lastName);
  else
    *(this->lastName) = lastName;
}

string Person::getDateOfBirth()
{
  return *(this->dateOfBirth);
}

void Person::setDateOfBirth(string dateOfBirth)
{
  if (Person::validateDate(dateOfBirth))
  {
    if (this->dateOfBirth == nullptr)
      this->dateOfBirth = new string(dateOfBirth);
    else
      *(this->dateOfBirth) = dateOfBirth;
  }
}

string Person::getAddress()
{
  return this->address->getAddress();
}

void Person::setAddress(string city, string country, string postcode, string state, string streetName, string streetNumber)
{
  if (this->address == nullptr)
    this->address = new Address();
  this->address->setAddress(city, country, postcode, state, streetName, streetNumber);
}

// void Person::introduce()
// {
//   cout << "Personal information: " << endl;
//   cout << "First name: " << this->getFirstName() << endl;
//   cout << "Last name: " << this->getLastName() << endl;
//   cout << "Date of birth: " << this->getDateOfBirth() << endl;
//   cout << this->getAddress();
// }

bool Person::validateDate(string dateOfBirth)
{
  if (dateOfBirth.length() == 10)
  {
    int year = stoi(dateOfBirth.substr(0, 4));
    int month = stoi(dateOfBirth.substr(5, 2));
    int day = stoi(dateOfBirth.substr(8, 2));
    if (month < 1 || month > 12)
      return false;
    if (day < 1 || day > 31)
      return false;
    if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
      return false;
    if (day == 30 && month == 2)
      return false;
    if (month == 2 && day == 29 && year % 4)
      return false;
    if (month == 2 && day == 29 && year % 400)
      return true;
    if (month == 2 && day == 29 && year % 100)
      return false;
    return true;
  }
  return false;
}