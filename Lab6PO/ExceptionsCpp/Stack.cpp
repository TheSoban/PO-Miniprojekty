#include "Stack.h"
#include "StackFullException.h"
#include "StackEmptyException.h"

Stack::Stack()
{
  this->maxStackSize = 10;
  this->dfs = vector<int>(10);
  this->top = 0;
}

Stack::Stack(int max)
{
  this->maxStackSize = max;
  this->dfs = vector<int>(max);
  this->top = 0;
}

void Stack::push(int newItem)
{
  if (this->top <= this->maxStackSize)
  {
    this->dfs.push_back(newItem);
    this->top = this->top + 1;
  }
  else
  {
    throw StackFullException("Stack full", newItem, this->maxStackSize);
  }
}

int Stack::pop()
{
  if (this->top > 0)
  {
    int value = this->dfs.back();
    this->top = this->top - 1;
    this->dfs.pop_back();
    return value;
  }
  else
  {
    throw StackEmptyException("Stack empty");
  }
}