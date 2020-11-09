#include "Car.h"

using namespace std;

Car::Car() {
  this->tank_capacity = 0;
  this->fuel_level = 0;
  this->mileage = 0;
  this->model = "";
}

Car::Car(float tank_capacity, string model) {
  this->tank_capacity = tank_capacity;
  this->fuel_level = 0;
  this->mileage = 0;
  this->model = model;
}

void Car::refuel() {
  this->fuel_level = this->tank_capacity;
}

void Car::drive(int kilometers) {
  if(kilometers <= this->fuel_level) {
    this->fuel_level -= kilometers;
    this->mileage += kilometers;
  } else {
    cout << "You do not have enough fuel" << endl;
  }
}

float Car::getTankCapacity() {
  return this->tank_capacity;
}

float Car::getTankCapacity() const {
  return this->tank_capacity;
}

float Car::getMileage() {
  return this->mileage;
}

Car::operator bool() const {
  return !this->model.empty() && this->tank_capacity > 0;
}

bool Car::operator !() const {
  return !(bool)*this;
}

ostream &operator <<(ostream &os, const Car &car) {
  os << car.model << " " << car.fuel_level << "\n";
  return os;
}

bool Car::operator <(const Car &car) const {
  return this->model < car.model;
}

Car &Car::operator ++(int i) {
  Car *before = this;
  this->mileage = this->mileage + 1;
  return *before;
}

Car &Car::operator |=(int i) {
  // Głupi przykład ale nie wiem co innego można zrobić w samochodzie za pomocą bramki or
  this->mileage |= i;
  return *this;
}

Car &Car::operator ,(Car &car) {
  return car;
}
