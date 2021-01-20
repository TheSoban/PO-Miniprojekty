#include "Address.h"

using namespace std;

Address::Address() : city(nullptr),
                     country(nullptr),
                     postcode(nullptr),
                     state(nullptr),
                     streetName(nullptr),
                     streetNumber(nullptr)
{
}

Address::Address(string city, string country, string postcode, string state, string streetName, string streetNumber) : city(nullptr),
                                                                                                                       country(nullptr),
                                                                                                                       postcode(nullptr),
                                                                                                                       state(nullptr),
                                                                                                                       streetName(nullptr),
                                                                                                                       streetNumber(nullptr)
{
  this->setAddress(city, country, postcode, state, streetName, streetNumber);
}

Address::~Address()
{
  if (this->city != nullptr)
    delete this->city;
  if (this->country != nullptr)
    delete this->country;
  if (this->postcode != nullptr)
    delete this->postcode;
  if (this->state != nullptr)
    delete this->state;
  if (this->streetName != nullptr)
    delete this->streetName;
  if (this->streetNumber != nullptr)
    delete this->streetNumber;
}
Address::Address(string city) : city(nullptr),
                                country(nullptr),
                                postcode(nullptr),
                                state(nullptr),
                                streetName(nullptr),
                                streetNumber(nullptr)
{
  if (this->city == nullptr)
    this->city = new string(city);
  else
    *(this->city) = city;
}

Address::Address(const Address &address)
{
  this->city = address.city == nullptr ? nullptr : new string(*address.city);
  this->country = address.country == nullptr ? nullptr : new string(*address.country);
  this->postcode = address.postcode == nullptr ? nullptr : new string(*address.postcode);
  this->state = address.state == nullptr ? nullptr : new string(*address.state);
  this->streetName = address.streetName == nullptr ? nullptr : new string(*address.streetName);
  this->streetNumber = address.streetNumber == nullptr ? nullptr : new string(*address.streetNumber);
}

Address::Address(Address &&address)
{
  this->city = move(address.city);
  this->country = move(address.country);
  this->postcode = move(address.postcode);
  this->state = move(address.state);
  this->streetName = move(address.streetName);
  this->streetNumber = move(address.streetNumber);
  address.city = nullptr;
  address.country = nullptr;
  address.postcode = nullptr;
  address.state = nullptr;
  address.streetName = nullptr;
  address.streetNumber = nullptr;
}

bool Address::validateData(string city, string country, string postcode, string state, string streetName, string streetNumber)
{
  if (city.find_first_of("0123456789") != string::npos)
    return false;
  if (city.length() == 0)
    return false;
  if (country.find_first_of("0123456789") != string::npos)
    return false;
  if (country.length() == 0)
    return false;
  if (postcode.find_first_not_of("0123456789-") != string::npos)
    return false;
  if (postcode.length() != 6)
    return false;
  if (state.find_first_of("0123456789") != string::npos)
    return false;
  if (state.length() == 0)
    return false;
  if (streetName.length() == 0)
    return false;
  if (streetNumber.length() == 0)
    return false;
  return true;
}

void Address::printErrors(string city, string country, string postcode, string state, string streetName, string streetNumber)
{
  cout << "-----------------------------------------------" << endl;
  if (city.find_first_of("0123456789") != string::npos)
    cout << "City name cannot contain numbers" << endl;
  if (city.length() == 0)
    cout << "City name cannot be empty" << endl;
  if (country.find_first_of("0123456789") != string::npos)
    cout << "Country name cannot contain numbers" << endl;
  if (country.length() == 0)
    cout << "Country name cannot be empty" << endl;
  if (postcode.find_first_not_of("0123456789-") != string::npos)
    cout << "Postcode can only contain numbers and '-' sign" << endl;
  if (postcode.length() != 6)
    cout << "Postcode can only be passed in format of xx-xxx" << endl;
  if (state.find_first_of("0123456789") != string::npos)
    cout << "State name cannot contain numbers" << endl;
  if (state.length() == 0)
    cout << "State name cannot be empty" << endl;
  if (streetName.length() == 0)
    cout << "Street name cannot be empty" << endl;
  if (streetNumber.length() == 0)
    cout << "Street number cannot be empty" << endl;
  cout << "Pass all the data again!" << endl;
  cout << "-----------------------------------------------" << endl;
}

void Address::setAddress(string city, string country, string postcode, string state, string streetName, string streetNumber)
{
  if (Address::validateData(city, country, postcode, state, streetName, streetNumber))
  {
    if (this->city == nullptr)
      this->city = new string(city);
    else
      *(this->city) = city;
    if (this->country == nullptr)
      this->country = new string(country);
    else
      *(this->country) = country;
    if (this->postcode == nullptr)
      this->postcode = new string(postcode);
    else
      *(this->postcode) = postcode;
    if (this->state == nullptr)
      this->state = new string(state);
    else
      *(this->state) = state;
    if (this->streetName == nullptr)
      this->streetName = new string(streetName);
    else
      *(this->streetName) = streetName;
    if (this->streetNumber == nullptr)
      this->streetNumber = new string(streetNumber);
    else
      *(this->streetNumber) = streetNumber;
  }
  else
  {
    Address::printErrors(city, country, postcode, state, streetName, streetNumber);
    if (this->city == nullptr)
      this->city = new string();
    else
      *(this->city) = "";
    if (this->country == nullptr)
      this->country = new string();
    else
      *(this->country) = "";
    if (this->postcode == nullptr)
      this->postcode = new string();
    else
      *(this->postcode) = "";
    if (this->state == nullptr)
      this->state = new string();
    else
      *(this->state) = "";
    if (this->streetName == nullptr)
      this->streetName = new string();
    else
      *(this->streetName) = "";
    if (this->streetNumber == nullptr)
      this->streetNumber = new string();
    else
      *(this->streetNumber) = "";
  }
}

string Address::getAddress()
{
  string res = "Adress:\n";
  res += "City: " + *(this->city) + "\n";
  res += "Country: " + *(this->country) + "\n";
  res += "Postcode: " + *(this->postcode) + "\n";
  res += "State: " + *(this->state) + "\n";
  res += "Street Name: " + *(this->streetName) + "\n";
  res += "Street Number: " + *(this->streetNumber) + "\n";
  return res;
}
