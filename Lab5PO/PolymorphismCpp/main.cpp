#include <iostream>
#include <map>
#include <vector>
#include "Employee.h"
#include "Student.h"
#include "StudentFactory.h"
#include "EmployeeFactory.h"
#include "PersonFactory.h"

using namespace std;

void foo(Person &person)
{
  person.introduce();
  cout << endl;
}

void bar(Person *person)
{
  person->introduce();
  cout << endl;
}

int main()
{
  // Person person("Natalia", "Nowak", "1986-04-14", "Poznań", "Polska", "62-081", "Wielkopolska", "Polwiejska", "12");
  // foo(person);
  // bar(&person);

  // Employee employee("Karolina", "Kapusta", "1992-12-26", "Kraków", "Polska", "33-332", "Malopolska", "Wielicka", "72");
  // employee.addSubject("PO");
  // employee.addSubject("PTC");
  // employee.removeSubject("PTC");
  // employee.addSubject("SO");
  // foo(employee);
  // bar(&employee);

  // Student student("Tomek", "Nowicki", "1995-08-07", "Katowice", "Polska", "40-951", "Slaskie", "Al. Korfantego", "35");
  // student.addGrade("PTC", 5);
  // student.addGrade("SO", 4);
  // foo(student);
  // bar(&student);

  // Zadanie 12
  // Obie funkcje na wszystkich trzech klasach wykonują metodę Person::introduce();

  // Zadanie 14
  // Po dodaniu specyfikatora virtual funkcje foo i bar wykonują odpowiednie metody dla każdej z podklas (wymusza dynamiczne linkowanie).

  // Employee *e1 = new Employee;
  // Person *p1 = static_cast<Person *>(e1);
  // Person *p2 = static_cast<Employee *>(p1);

  // Person *p3 = new Person;
  // Employee *e2 = static_cast<Employee *>(p3);

  // Zadanie 15
  // Klasa Employee po rzutowanie na typ Person traci pozycje nie zawarte w klasie Person niezależnie od podejścia.
  // Rzutowanie nie jest tu potrzebne (wystarczy napisac: Person *p1 = e1;)
  // Klasa Person po rzutowaniu na typ Employee zyskuje dodatkowe pozycje, o które rozszerza klasa Employee.
  // Rzutowanie jest tu niezbędne.
  // Jak widać rzutowanie jest wykonywane automatyczne gdy próbujemy przypisać do nadklasy obiekt
  // podklasy ale nie odwrotnie. Wszystkie rzutowania są mimo wszystko poprawne mimo, że niektóre nadmiarowe.

  // Employee *e3 = new Employee;
  // Person *p4 = dynamic_cast<Person *>(e3);
  // Employee *e4 = dynamic_cast<Person *>(p4);

  // Zadanie 16
  // Klase nadrzędną można inicjować klasą podrzędną ale nie odwrotnie,
  // Employee nie może powstać z Person.

  // Person *p5 = new Person;
  // Employee *e5 = dynamic_cast<Employee *>(p5);
  // if (e5 == nullptr)
  //   cout << "Blad rzutowania" << endl;
  // else
  //   e5->getSubjects();

  // Zadanie 17
  // Dynamic cast zwraca nullptr zadanego typu, aby porownac wartosc nullptr danego typu z wartoscia samej wartosci
  // nullptr wymagana jest konwersja typow.

  // Zadanie 19
  // Nie mozna teraz skompilowac projektu
  // Nie jest teraz mozliwe utworzenie nowej instancji klasy Person gdyz posiada ona metody czysto abstrakcyjne.
  // Aby naprawic ten problem nalezy albo przywrocic klasie Person implementacje metody introduce albo zdecydowac
  // sie na traktowanie jej jako metody abstrakcyjnej i nie tworzyc dla niej instancji.

  // Zadanie 22
  // Pamiec zostala prawidlowo zaalokowana oraz zwolniona.

  // Zadanie 23
  // Po dodaniu specyfikatora virtual wykonanie destruktorow pozostaje takie same.

  // StudentFactory sFactory = StudentFactory();
  // EmployeeFactory eFactory = EmployeeFactory();

  // Student *s1 = sFactory.create();
  // Student *s2 = sFactory.create();
  // Employee *e1 = eFactory.create();
  // Employee *e2 = eFactory.create();

  // Zadanie 30
  // Kontener moze przechowywac, moze przechowywac instancje klas dziedziczacych z PersonFactory

  map<string, PersonFactory *> m;
  m["employee"] = new EmployeeFactory();
  m["student"] = new StudentFactory();
  vector<Person *> peopleArray;
  string decision = "";
  while (decision != "exit")
  {
    cout << "Choose what to do:" << endl;
    cout << "employee <- add employee" << endl;
    cout << "student <- add student" << endl;
    cout << "display <- display person data" << endl;
    cout << "exit <- stop adding" << endl;
    cin >> decision;
    if (decision == "employee" || decision == "student")
      peopleArray.push_back(m[decision]->create());
    if (decision == "display")
      for (Person *person : peopleArray)
      {
        cout << endl;
        person->introduce();
        cout << endl;
      }
  };

  // Zadanie 33
  // Kod dziala zgodnie z oczekiwaniami, jedyna niewygoda to informacja o nieprawidlowym adresie dla osob bez danych osobowych

  return 0;
}