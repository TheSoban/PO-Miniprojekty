#include <iostream>
#include "Stack.h"
#include "StackException.h"
#include "StackEmptyException.h"
#include "StackFullException.h"

using namespace std;

void foo(Stack &s)
{
  try
  {
    int i = 10;
    while (true)
      s.push(i++);
  }
  catch (StackException e)
  {
    cout << e.what() << endl;
  }
}

void bar(Stack &s)
{
  try
  {
    int i = 10;
    while (true)
      s.push(i++);
  }
  catch (StackException &e)
  {
    cout << e.what() << endl;
  }
}

int main()
{
  // Zadanie 3
  // Operator noexcept oznacza, ze funkcja nie wyrzuca wyjatkow.
  // Operator override oznacza, ze funkcja jest wirtualna i nadpisuje wirtualna funkcje klasy nadrzednej.
  // W przeciwienstwie do java'y gdzie oznacza jedynie nadpisanie funkcji klasy nadrzednej.

  // Zadanie 4
  // C++ nie obsluguje egzekwowanej specyfikacji wymiany wyjatkow ktore moga byc wyrzucone przez funkcje.

  // Stack stack = Stack(10);
  // foo(stack);

  // Zadanie 5
  // zmienna nie bedaca zmienna wskaznikowa lub referencyjna wykonuje metode what dla podanego typu (StackException)

  // Stack stack = Stack(10);
  // bar(stack);

  // Zadanie 6
  // zmienna bedaca zmienna wskaznikowa lub referencyjna wykonuje metode what dla oryginalnego typu (StackFullException)

  Stack stack = Stack(10);
  int decision = 4;
  int num = 0;
  while (decision != 3)
  {
    try
    {
      cout << "Choose:" << endl;
      cout << "1 <- add to stack" << endl;
      cout << "2 <- remove from stack" << endl;
      cout << "3 <- exit" << endl;
      cin >> decision;
      if (decision == 1)
      {
        cout << "Number to add:" << endl;
        cin >> num;
        stack.push(num);
      }
      if (decision == 2)
        stack.pop();
    }
    catch (StackFullException &e)
    {
      cout << e.what() << endl;
    }
    catch (StackEmptyException &e)
    {
      cout << e.what() << endl;
    }
  }

  return 0;
}