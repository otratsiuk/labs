#include "my_string.h"
#include <iostream>

int main() {
  String my_string("helloworld");
  display(my_string);
  std::cout << "\n";

  String to_move_to(std::move(my_string));
  display(to_move_to);
  std::cout << "\n";

  String to_copy_to(to_move_to);
  display(to_copy_to);
  std::cout << "\n";

  String hello("hello");
  String equal("helloworld");

  std::cout << "\n";

  equal = std::move(hello);
  display(equal);
  std::cout << "\n";
  return 0;
}