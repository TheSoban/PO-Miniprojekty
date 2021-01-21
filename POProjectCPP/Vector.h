#ifndef VECTOR_H
#define VECTOR_H

using namespace std;

class Vector
{
private:
  int x;
  int y;

public:
  int getX();
  int getY();
  Vector &setX(int x);
  Vector &setY(int y);
  Vector &add(Vector &vector);
  Vector &multiplyScalar(int scalar);
  Vector copy();
  bool equals(Vector &vector);
  Vector();
  Vector(int x, int y);
};

#endif