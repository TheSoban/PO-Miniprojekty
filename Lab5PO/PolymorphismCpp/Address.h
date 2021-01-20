#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>

using namespace std;

class Address
{
private:
  string *city;
  string *country;
  string *postcode;
  string *state;
  string *streetName;
  string *streetNumber;

public:
  Address();
  ~Address();
  Address(string city);
  Address(const Address &address);
  Address(Address &&address);
  Address(string city, string country, string postcode, string state, string streetName, string streetNumber);
  static bool validateData(string city, string country, string postcode, string state, string streetName, string streetNumber);
  static void printErrors(string city, string country, string postcode, string state, string streetName, string streetNumber);
  string getAddress();
  void setAddress(string city, string country, string postcode, string state, string streetName, string streetNumber);
};

#endif