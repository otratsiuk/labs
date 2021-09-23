#include "classes.h"
#include <iostream>
#include <string>

// class Symbol
Symbol::Symbol() : symbol('_') {}

Symbol::Symbol(const Symbol &s) : symbol(s.symbol) {}

Symbol::Symbol(char s) : symbol(s) {}

Symbol::~Symbol() {}

char Symbol::get() { return symbol; }

void Symbol::set(char s) { symbol = s; }

void Symbol::print(int r) {
  for (int i = 0; i < r; i++) {
    std::cout << symbol << " ";
  }
}

void Symbol::print(int r, int c) {
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      std::cout << symbol << " ";
    }
    std::cout << "\n";
  }
}

void Symbol::print(int r, int c, char d) {
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      std::cout << symbol << d;
    }
    std::cout << "\n";
  }
}

// class Date
Date::Date() : day(17), month(10), year(2020) {}

Date::Date(const Date &date)
    : day(date.day), month(date.month), year(date.year) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date::~Date() {}

void Date::show() { std::cout << day << "." << month << "." << year << "\n"; }

void Date::set(std::string date) {
  const int zero_code = 48;

  day = (static_cast<int>(date[0]) - zero_code) * 10 +
        (static_cast<int>(date[1]) - zero_code);

  month = (static_cast<int>(date[3]) - zero_code) * 10 +
          (static_cast<int>(date[4]) - zero_code);

  year = (static_cast<int>(date[6]) - zero_code) * 1000 +
         (static_cast<int>(date[7]) - zero_code) * 100 +
         (static_cast<int>(date[8]) - zero_code) * 10 +
         (static_cast<int>(date[9]) - zero_code);
}

void Date::set(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}

void Date::set(int d, int m) {
  day = d;
  month = m;
}

// class Journey
Journey::Journey() : days(0), hours_in_road(0), country("unknown") {}

Journey::Journey(const Journey &journey)
    : days(journey.days), hours_in_road(journey.hours_in_road),
      country(journey.country) {}

Journey::Journey(int d, float hours, std::string s)
    : days(d), hours_in_road(hours), country(s) {}

Journey::~Journey() {}

void Journey::show() {
  std::cout << "days:   \t" << days << "\nhours:  \t" << hours_in_road
            << "\ncountry:\t" << country << "\n";
}

float Journey::hours() { return (days * 24 + hours_in_road); }

float Journey::hours(float extra_hours) { return (days * 24 + extra_hours); }

float Journey::hours(Journey journey) {
  return (days * 24 + hours_in_road + journey.days * 24 +
          journey.hours_in_road);
}
