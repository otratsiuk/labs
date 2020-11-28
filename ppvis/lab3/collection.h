#ifndef _Collection_H
#define _Collection_H

#include <cassert>
#include <initializer_list>
#include <iomanip>

template <class T> class Collection {
private:
  std::string name;
  int num_of_items;
  T *items;

public:
  Collection() : name("unknown"), num_of_items(0), items(NULL){};

  Collection(const std::string name_input, std::initializer_list<T> list)
      : name(name_input) {
    num_of_items = list.size();

    items = new T[num_of_items];

    int i = 0;
    for (auto &b : list) {
      items[i] = b;
      i++;
    }
  };

  Collection(const Collection &obj) {
    name = obj.name;
    num_of_items = obj.num_of_items;

    items = new T[num_of_items];

    for (int i = 0; i < num_of_items; i++) {
      items[i] = obj.items[i];
    }
  }

  void display() {
    std::cout << std::left << std::setw(30) << "collection: " << std::setw(30)
              << name << "\n";
    if (items != NULL) {
      for (int i = 0; i < num_of_items; i++) {
        items[i].display();
      }
    }
  };

  ~Collection() { delete[] items; };
};

#endif