#ifndef NODE_H
#define NODE_H
#include <memory>

using namespace std;

class Node {
  public:
    weak_ptr<Node> next;
    ~Node();
};

#endif