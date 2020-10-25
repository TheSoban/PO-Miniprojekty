#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>

class Date {
  private: 
    int year;
    int month;
    int day;
  public:
    Date(int year, int month, int day);
    Date(const Date &date);
    static Date parseDate(std::string date);  
    bool isAfter(Date &other);
    std::string toString();
    static bool validate(std::string date);
};

#endif