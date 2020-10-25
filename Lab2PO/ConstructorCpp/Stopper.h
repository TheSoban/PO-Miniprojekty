#ifndef STOPPER_H
#define STOPPER_H
#include <ctime>
#include <chrono>

class Stopper {
  private:
    std::chrono::steady_clock::time_point* starting_time;
    long summary; // in milliseconds
  public:
    Stopper();
    void start();
    void stop();
    void reset();
    void print();
};

#endif