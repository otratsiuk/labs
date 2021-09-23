#include "book.h"

Book::Book() : name("unknown"), author("unknown"), pages(0) {}

Book::Book(const std::string &name_input, const std::string &author_input,
           int p)
    : name(name_input), author(author_input), pages(p) {}

void Book::set(const std::string &name_input, const std::string author_input,
               int p) {
  name = name_input;
  author = author_input;
  pages = p;
};

std::string &Book::get_name() { return name; }

std::string &Book::get_author() { return author; }

int Book::get_pages() { return pages; }

void Book::display() {
  std::cout << std::left << std::setw(30) << name << std::setw(30) << author
            << std::setw(15) << pages << "\n";
}

void Book::operator=(const Book &book) {
  name = book.name;
  author = book.author;
  pages = book.pages;
}