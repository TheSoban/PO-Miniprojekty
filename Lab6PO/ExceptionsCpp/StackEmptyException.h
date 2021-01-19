#ifndef STACK_EMPTY_EXCEPTION_H
#define STACK_EMPTY_EXCEPTION_H

#include "StackException.h"
#include <string>

using namespace std;

class StackEmptyException : public StackException
{
  string message;

public:
  StackEmptyException() {}
  StackEmptyException(string p) : message(p) {}
  virtual const char *what() const noexcept override
  {
    return this->message.c_str();
  }
};

#endif