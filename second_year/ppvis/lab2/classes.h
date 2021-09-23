#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <string>

class Symbol {
private:
  char symbol;

public:
  Symbol();

  Symbol(const Symbol &s);

  Symbol(char s);

  ~Symbol();

  char get();

  void set(char s);

  // r - times to print symbol in a row
  void print(int r);

  // r - times to print symbols in a row, c - number of columns
  void print(int r, int c);

  // r - times to print symbols in a row, c - number of columns, d - symbol to
  // divide
  void print(int r, int c, char d);
};

class Date {
private:
  int day;
  int month;
  int year;

public:
  Date();

  Date(const Date &d);

  Date(int d, int m, int y);

  ~Date();

  void show();

  void set(std::string);

  void set(int d, int m, int y);

  void set(int d, int m);
};

class Journey {
private:
  int days;
  float hours_in_road;
  std::string country;

public:
  Journey();

  Journey(const Journey &journey);

  Journey(int d, float hours_in_road, std::string c);

  ~Journey();

  void show();

  float hours();

  float hours(float extra_hours);

  float hours(Journey journey);
};

#endif