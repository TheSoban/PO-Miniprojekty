#include "Logger.h"
#include "date.h"
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>


void Logger::log(std::string value) {
  if(this->debug) {
    std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
    std::time_t parsed = std::chrono::system_clock::to_time_t(time);
    std::string timeString = std::ctime(&parsed);
    timeString.pop_back();
    std::cout << "[" << timeString << "] " << value << std::endl;
  }
} 