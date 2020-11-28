#ifndef _HASH_H
#define _HASH_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

struct Item {
  std::string surname;
  std::string name;
  int bd_year;

  void operator=(Item &a);
};

class Hash {
private:
  int N;

  std::list<Item> *table;

public:
  Hash(int n);

  void clear();

  void load_items_from_file(const std::string &file_name);

  void load_items_to_file(const std::string &file_name);

  void add_item(const Item &item);

  Item &search_item(const std::string &surname);

  void delete_item(const std::string &surname);

  int function(const std::string &surname);

  Item fill_item();

  void modify_item(const std::string &surname);

  void show();
};

#endif