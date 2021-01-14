#include <iomanip>
#include <iostream>
#include <list>

const int elements = 10;
const int blocks = 3;
const int max_word = 255;
const int mask = 31;

int binary(int n) {
  if (n)
    (binary(n >> 1), std::cout << (n & 1));
}

struct Index {
  int x;
  int y;
};

class Assotiayive_storage_device {
private:
  int assotiative_register = 0;
  static const int mask_register = mask;
  int comparison_element = 0;

  int storage_array[blocks][elements] = {};
  bool adress_indicator_register[blocks][elements] = {};
  bool free_indicator[blocks][elements] = {};

  std::list<Index> multiply_response_resolver;

public:
  void add(int word) {
    bool added = false;

    for (int i = 0; i < blocks; i++) {
      if (added == true) {
        break;
      }
      for (int j = 0; j < elements; j++) {
        if (free_indicator[i][j] == 0) {
          storage_array[i][j] = word;

          free_indicator[i][j] = 1;

          added = true;
          break;
        }
      }
    }
  };

  void search(int word) {
    multiply_response_resolver.clear();

    for (int i = 0; i < blocks; i++) {
      for (int j = 0; j < elements; j++) {
        adress_indicator_register[i][j] = 1;
      }
    }

    assotiative_register = word;
    comparison_element = assotiative_register & mask_register;
    for (int i = 0; i < blocks; i++) {
      for (int j = 0; j < elements; j++) {
        if (comparison_element == storage_array[i][j] & mask_register) {
          multiply_response_resolver.push_back(Index{i, j});
        } else {
          adress_indicator_register[i][j] = 0;
        }
      }
    }
  };

  void search_display() {
    for (auto &_ : multiply_response_resolver) {
      std::cout << storage_array[_.x][_.y] << " ";
    }
    if (multiply_response_resolver.size() == 0) {
      std::cout << "no such word in storage";
    }
    std::cout << "\n\n";
  };

  void delete_word(int word) {
    search(word);
    for (auto &_ : multiply_response_resolver) {
      storage_array[_.x][_.y] = 0;
      free_indicator[_.x][_.y] = 0;
    }
  };

  void display() {
    for (int i = 0; i < blocks; i++) {
      for (int j = 0; j < elements; j++) {
        if (storage_array[i][j] == 0) {
          std::cout << std::right << std::setw(8);
          std::cout << "00000000"
                    << " ";
        } else {
          binary(storage_array[i][j]);
          std::cout << std::right << std::setw(8);
        }
        std::cout << "\t";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
};

int main() {
  Assotiayive_storage_device storage;

  int arr[20] = {234, 148, 3,  18, 45, 39, 18,  238, 30, 18,
                 23,  4,   18, 45, 34, 80, 200, 43,  87, 23};

  for (int i = 0; i < 19; i++) {
    storage.add(arr[i]);
  }

  storage.display();

  storage.search(18);

  std::cout << "search for 18: \n";

  storage.search_display();

  storage.delete_word(18);

  storage.display();

  storage.search(18);

  std::cout << "search for 18 in storage after delete function:\n";

  storage.search_display();

  return 0;
}