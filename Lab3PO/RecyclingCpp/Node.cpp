#include "Node.h"
#include <memory>
#include <iostream>

using namespace std;

Node::~Node() {
  cout << "Object Destruction" << endl;
}
