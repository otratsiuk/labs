#include "hash.h"

void Item::operator=(Item &a) {
  surname = a.surname;
  name = a.name;
  bd_year = a.bd_year;
};

Item operator>>(std::ifstream &file, Item &item) {
  file >> item.surname >> item.name >> item.bd_year;

  return item;
}

std::ofstream &operator<<(std::ofstream &file, Item &item) {
  file << " " << item.surname << " " << item.name << " " << item.bd_year;

  return file;
}

Hash::Hash(int n) : N(n) { table = new std::list<Item>[N]; }

void Hash::clear() {
  for (int i = 0; i < N; i++) {
    table[i].clear();
  }
}

int Hash::function(const std::string &surname) {
  unsigned int key = 0;

  key = (key * key);

  for (auto &letter : surname) {
    key = key ^ static_cast<unsigned int>(letter);
  }

  return key % N;
}

void Hash::load_items_from_file(const std::string &file_name) {
  std::ifstream file(file_name);

  clear();

  if (!file.is_open()) {
    std::cout << "file error\n";
  } else {
    while (!file.eof()) {
      Item item;

      file >> item;

      add_item(item);
    }
    file.close();
  }
}
void Hash::load_items_to_file(const std::string &file_name) {
  std::ofstream file(file_name, std::ios::trunc);

  if (!file.is_open()) {
    std::cout << "file error\n";

  } else {
    for (int i = 0; i < N; i++) {
      for (auto &item : table[i]) {
        file << item;
      }
    }

    file.close();
  }
}

void Hash::add_item(const Item &item) {
  int key = function(item.surname);

  table[key].push_back(item);
}

Item Hash::fill_item() {
  Item temp;

  std::cout << "Enter surname: ";
  if (std::cin.peek() != 32)
    std::cin >> temp.surname;

  std::cout << "Enter name: ";
  if (std::cin.peek() != 32)
    std::cin >> temp.name;

  std::cout << "Birthday year: ";
  if (std::cin.peek() != 32)
    std::cin >> temp.bd_year;

  return temp;
}

void Hash::delete_item(const std::string &surname) {
  int key = function(surname);

  table[key].remove_if([&](Item &item) { return item.surname == surname; });
}

Item &Hash::search_item(const std::string &surname) {
  int key = function(surname);

  for (auto &item : table[key]) {
    if (item.surname == surname) {
      return item;
    }
  }
}

void Hash::modify_item(const std::string &surname) {
  Item temp = fill_item();

  search_item(surname) = temp;
}

void Hash::show() {
  for (int i = 0; i < N; i++) {
    for (auto &item : table[i]) {
      std::cout << std::setw(15) << std::left << function(item.surname)
                << std::setw(30) << item.surname << std::setw(30) << item.name
                << std::setw(10) << item.bd_year << "\n";
    }
  }
}