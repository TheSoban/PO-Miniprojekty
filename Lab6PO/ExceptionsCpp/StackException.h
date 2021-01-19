#ifndef STACK_EXCEPTION_H
#define STACK_EXCEPTION_H

#include <exception>

using namespace std;

class StackException : public exception
{
public:
  StackException() {}
  virtual const char *what() const noexcept override
  {
    return "Invalid_stack_operation!";
  }
};

#endif