#include <iostream>
#include <string>

using namespace std;

// Zadanie 1

template <typename T>
T maximum(T const &a, T const &b)
{
  return a > b ? a : b;
}

// Zadanie 3

// class X {
//   private:
//     int x;
//   public:
//     X() {}
//     X(int _x) {
//       this->x = _x;
//     }

//     int getX() const {
//       return x;
//     }

//     friend ostream& operator << (ostream& os, X const& x) {
//       os << x.x;
//       return os;
//     }

//     // Zadanie 5

//     bool operator > (const X &x) const {
//       return this->x > x.x;
//     }
// };

// Zadanie 6

template <typename T>
class X
{
private:
  T x;

public:
  X() {}
  X(T _x)
  {
    this->x = _x;
  }

  T getX() const
  {
    return x;
  }

  friend ostream &operator<<(ostream &os, X const &x)
  {
    os << x.x;
    return os;
  }
};

template <typename T>
bool operator>(X<T> const &a, X<T> const &b)
{
  return a.getX() > b.getX();
}

// Zadanie 8

template <>
bool operator>(X<string> const &a, X<string> const &b)
{
  return a.getX().size() > b.getX().size();
}

// Zadanie 9

template <typename T, typename C = X<T>>
class Y
{
  T variable;
  C classX;
};

// Zadanie 10

template <typename T>
class A
{
  typename T::id i;

public:
  void f() { i.g(); }
};

class B
{
public:
  class id
  {
  public:
    void g() {}
  };
};

// Zadanie 11

auto maxLambda = [](auto a, auto b) {
  return a > b ? a : b;
};

int main()
{
  // Zadanie 2

  // cout << maximum(6, 7) << endl;
  // cout << maximum(6.3, 7.3) << endl;
  // cout << maximum(6.5, 7) << endl;
  // cout << maximum<double>(4, 5) << endl;
  // cout << maximum<double>(4.1, 5.7) << endl;
  // cout << maximum<int>(4.6, 3) << endl;
  // cout << maximum<double>(4.6, 3) << endl;
  // cout << maximum<bool>(4.6, 3) << endl;
  // cout << maximum<string>(4.6, 3) << endl;
  // cout << maximum<string>("aaa", "bb") << endl;

  // Przy dedukcji typu oba argumenty muszą być tego samego typu
  // Przy podaniu typu oba argumenty muszą być podanego typu lub język musi umieć castować wartość na docelowy typ

  // Zadanie 4

  // cout << maximum(X(4), X(3)) << endl;

  // Klasa X nie obsługuje operacji porównania

  // Zadnanie 7

  // cout << maximum(X<int>(4), X<int>(3)) << endl;

  // funkcja maximum działa zgodnie z oczekiwaniami

  // Zadanie 8

  // cout << maximum(X<string>("aaa"), X<string>("bb")) << endl;

  // Zadanie 10

  // A<B> ab;
  // ab.f();

  // Zadanie 11

  bool b = maxLambda(3, 3.14); // true
  auto c = maxLambda(3, 3.14); // 3.14
  return 0;
}