#ifndef STACK_H
#define STACK_H

#include <vector>

using namespace std;

class Stack
{
private:
  int maxStackSize;
  vector<int> dfs;
  int top;

public:
  Stack();
  Stack(int max);
  void push(int newItem);
  int pop();
};

#endif