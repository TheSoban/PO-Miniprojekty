#include "Date.h"
#include <iostream>
#include <string>

Date::Date(int year, int month, int day):
    year(year),
    month(month),
    day(day) {};

Date Date::parseDate(std::string date){
  // format yyyy-mm-dd
  int year = stoi(date.substr(0, 4));
  int month = stoi(date.substr(5, 2));
  int day = stoi(date.substr(8, 2));
  return Date(year, month, day);
};

Date::Date(const Date &date) {
  this->year = date.year;
  this->month = date.month;
  this->day = date.day;
};

bool Date::isAfter(Date &other) {
  if(this->year - other.year) return this->year > other.year;
  if(this->month - other.month) return this->month > other.month;
  if(this->day - other.day) return this->day > other.day;
  return false;
};

std::string Date::toString() {
  return std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
}

bool Date::validate(std::string date) {
  if(date.length() == 10) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    return month > 0 && month <= 12 && day > 0 && day < 32;
  } else return false;
}