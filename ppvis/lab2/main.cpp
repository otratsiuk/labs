#include "classes.h"
#include <iostream>

int main() {
  std::cout << "\nclass Symbol: \n";
  Symbol star('*');

  std::cout << "function print 1st overload:\n";
  star.print(5);
  std::cout << "\nfunction print 2nd overload:\n";
  star.print(3, 5);
  std::cout << "function print 3rd overload:\n";
  star.print(2, 4, '|');

  std::cout << "\nclass Data: \n";
  Date day;

  day.set(22, 12, 2021);
  std::cout << "function set 1st overload:\n";
  day.show();

  day.set("22.12.2021");
  std::cout << "function set 2nd overload:\n";
  day.show();

  day.set(22, 12);
  std::cout << "function set 3rd overload:\n";
  day.show();

  std::cout << "\nclass Journey:\n";
  Journey summer(12, 11, "Germany");
  Journey winter(summer);

  std::cout << "summer and winter journey initialization:\n";
  summer.show();
  std::cout << "\n";
  winter.show();

  std::cout << "function set 1st overload(hours in summer):\n"
            << summer.hours() << "\n";

  std::cout << "function set 2nd overload:(hourse in summer + extra time)\n"
            << summer.hours(30) << "\n";

  std::cout << "function set 3rd overload:(hours in summer and winter\n"
            << summer.hours(winter) << "\n";

  return 0;
}