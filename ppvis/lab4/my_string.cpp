#include "my_string.h"
#include <cctype>
#include <cstring>

String &String::operator=(String &&other) {
  std::cout << "move operator =(String &&other)\n"
            << "\n";
  if (this == &other) {
    return *this;
  }

  length = other.length;
  str = other.str;

  other.length = 0;
  other.str = nullptr;

  return *this;
}

String &String::operator=(const String &other) {
  length = other.length + 1;

  str = new char[length];
  std::strcpy(str, other.str);

  std::cout << "copy operator =(const String &other)\n";
}

String::String(const char *const s) {
  length = std::strlen(s) + 1;
  str = new char[length];
  std::strcpy(str, s);

  std::cout << "constructor String(const char *const s)\n";
}

String::String(String &&other) : length(other.length), str(other.str) {
  other.length = 0;
  other.str = nullptr;

  std::cout << "constructor String(String &&other)\n";
}

String ::String(const String &other) {
  length = other.length + 1;
  str = new char[length];
  std::strcpy(str, other.str);

  std::cout << "constructor String(const String &other)\n";
}

bool String::operator==(const String &other) {
  int max = length > other.length ? length : other.length;

  for (int i = 0; i < max; i++) {
    if (str[i] != other.str[i]) {
      return false;
    }
  }

  return true;
}

String::~String() {
  delete[] str;
  std::cout << "destructor ~String()\n";
}

void display(String &string) {
  for (int i = 0; i < string.length; i++) {
    std::cout << string.str[i];
  }
  std::cout << "\n";
}

void upper(String &string) {
  for (int i = 0; i < string.length; i++) {
    std::toupper(string.str[i]);
  }
}

void lower(String &string) {
  for (int i = 0; i < string.length; i++) {
    std::tolower(string.str[i]);
  }
}