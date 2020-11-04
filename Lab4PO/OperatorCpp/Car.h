#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>

using namespace std;

class Car {
  private:
    float tank_capacity;
    float fuel_level;
    unsigned int mileage;
    string model;
  public:
    Car();
    Car(float tank_capacity, string model);
    void refuel();
    void drive(int kilometers);
    float getTankCapacity();
    float getTankCapacity() const;
    float getMileage();
    operator bool() const;
    bool operator !() const;
    friend ostream &operator <<(ostream &os, const Car &car);
    bool operator <(const Car &car) const;
    Car &operator ++(int i);
    Car &operator |=(int i);
    Car &operator ,(Car &car);
};

#endif