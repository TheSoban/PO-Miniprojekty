#include "Car.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Zadanie 12
struct cmp {
  bool operator() (const Car &a, const Car &b) const {
    return a.getTankCapacity() < b.getTankCapacity();
  }
};

int main() {
  Car c1(123, "audi");
  Car c2(0, "bmw");
  Car c3(200, "");

  // if( c1) cout << "c1" << endl; 
  // if(!c1) cout << "!c1" << endl; 
  // if( c2) cout << "c2" << endl; 
  // if(!c2) cout << "!c2" << endl; 
  // if( c3) cout << "c3" << endl; 
  // if(!c3) cout << "!c3" << endl; 

  // Zadanie 8
  // Słowo kluczowe friend umożliwia metodzie przeciążającej operator << dostęp do własności private oraz protected klasy Car.
  // Jest to konieczne ze względu na to, że metoda obciążająca ten operator nie jest członkiem klasy Car i nie ma domyślnego dostępu do jej pozycji.

  // Zadanie 10
  // Słowo kluczowe const zostało użyte za funkcją aby wyrzucać błąd przy próbie nadpisania instancji klasy, na której metoda ta została wykorzystana.
  // W skrócie jest to pewnego rodzaju modyfikator read only na instancji klasy.

  // Zadanie 11
  // vector<Car> v;
  // v.push_back(c1);
  // v.push_back(c2);
  // v.push_back(c3);
  // sort(v.begin(), v.end());
  // for (auto it = v.begin(); it != v.end(); ++it) {
  //   cout << *it << endl;
  // }

  // Zadanie 13
  // set<Car, cmp> c;
  // c.insert(c1);
  // c.insert(c2);
  // c.insert(c3);
  // for (auto it = c.begin(); it != c.end(); ++it) {
  //   cout << *it << endl;
  // }

  // Zadanie 15
  // cout << c1.getMileage() << endl;
  // c1++;
  // c1++;
  // c1++;
  // c1++;
  // c1++;
  // c1++;
  // c1++;
  // c1++;
  // cout << c1.getMileage() << endl;

  // c1|=5;
  // cout << c1.getMileage() << endl;

  Car newCar = (c1, c2, c3);
  cout << newCar << endl;
  return 0;
}