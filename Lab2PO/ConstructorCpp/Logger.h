#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include "Date.h"

class Logger {
  private:
    bool debug;
  public:
    Logger(): debug(true){};
    Logger(bool debug): debug(debug){};
    void log(std::string value);
};

#endif