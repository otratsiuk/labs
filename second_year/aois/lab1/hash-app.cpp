#include "hash.h"

void menu() {
  std::cout << "\n1 - load table from file\n2 - add item\n3 - delete item\n4 - "
               "modify item\n5 - show\n6 - load table to file\n7 - exit "
               "without saving\n";
}

int main() {
  std::string file_name = "data.txt";

  Hash hash(16);

  bool next = true;

  while (next) {
    menu();

    int key;
    std::cout << "Choose option: ";
    std::cin >> key;

    switch (key) {
    case 1: {
      hash.load_items_from_file(file_name);

      std::cout << "\ndata is loaded\n";
      break;
    }
    case 2: {
      Item item = hash.fill_item();
      hash.add_item(item);

      std::cout << "\nitem is added\n";
      break;
    }
    case 3: {
      std::string temp;
      std::cout << "Enter surname: ";
      std::cin >> temp;

      hash.delete_item(temp);

      std::cout << "\nItem is deleted\n";
      break;
    }
    case 4: {
      std::string temp;
      std::cout << "enter surname: ";
      std::cin >> temp;

      hash.modify_item(temp);
      break;
    }
    case 5: {
      hash.show();

      break;
    }
    case 6: {
      hash.load_items_to_file(file_name);

      std::cout << "\ntable is loaded\n";

      break;
    }
    case 7: {
      next = false;

      break;
    }
    default:
      std::cout << "\nno such option\n";

      break;
    }
  }
  return 0;
}