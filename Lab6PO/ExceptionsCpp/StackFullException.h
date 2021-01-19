#ifndef STACK_FULL_EXCEPTION_H
#define STACK_FULL_EXCEPTION_H

#include "StackException.h"
#include <cstring>
#include <string>

using namespace std;

class StackFullException : public StackException
{
  int element = 0;
  int maxStackSize = 0;
  string message;

public:
  StackFullException() {}
  StackFullException(string p, int e, int s) : element(e), maxStackSize(s), message(p) {}
  virtual const char *what() const noexcept override
  {
    string returnValue = "Error: " + this->message + ", Overflowing element: " + to_string(this->element) + ", Max stack size: " + to_string(this->maxStackSize);
    const char *arr = strdup(returnValue.c_str());
    return arr;
  }
};

#endif