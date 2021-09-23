#ifndef _BOOK_H
#define _BOOK_H

#include <iomanip>
#include <iostream>
#include <string>

class Book {
private:
  std::string name;
  std::string author;
  int pages;

public:
  Book();

  Book(const std::string &name_input, const std::string &author_input, int p);

  void set(const std::string &name_input, const std::string author_input,
           int p);

  std::string &get_name();

  std::string &get_author();

  int get_pages();

  void display();

  void operator=(const Book &book);
};

#endif