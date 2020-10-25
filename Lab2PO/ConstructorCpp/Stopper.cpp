#include <iostream>
#include <ctime>
#include <chrono>
#include "Stopper.h"

Stopper::Stopper() {
  this->starting_time = nullptr;
  this->summary = 0;
}

void Stopper::start() {
  this->starting_time = new std::chrono::steady_clock::time_point(std::chrono::steady_clock::now());
}

void Stopper::stop() {
  if(this->starting_time != nullptr) {
    this->summary += std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - *(this->starting_time)).count();
    this->starting_time = nullptr;
  }
}

void Stopper::reset() {
  this->starting_time = nullptr;
  this->summary = 0;
} 

void Stopper::print() {
  std::cout << "Current time: " << this->summary << " ms." << std::endl; 
}