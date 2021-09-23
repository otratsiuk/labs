#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <iostream>

class String {
private:
  char *str;
  std::size_t length;

public:
  String(const char *const s);

  String(String &&other);

  String(const String &other);

  ~String();

  String &operator=(String &&other);

  String &operator=(const String &other);

  bool operator==(const String &other);

  friend void upper(String &string);

  friend void lower(String &string);

  friend void display(String &string);
};

#include "my_string.cpp"

#endif