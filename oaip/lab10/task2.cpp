#include <iostream>

using namespace std;

int count_number_length(int dec) {
  int num_length = 1;
  int num = dec;
  while ((num /= 10) > 0) {
    num_length++;
  }
  return (num_length);
}

char *dec_to_hex(int dec) {
  static char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  int num_length = count_number_length(dec);
  char *temp = new char[num_length];
  char *hex = new char[num_length];
  int num = dec;
  int rest;
  int hex_length = 0;
  if (dec != 0) {
    for (int i = 0; num != 0 && i < num_length; i++) {
      rest = num % 16;
      num /= 16;
      temp[i] = digits[rest];
      hex_length++;
    }
  } else if (dec == 0) {
    hex[0] = '0';
  }
  for (int i = 0; i < hex_length; i++) {
    hex[hex_length - 1 - i] = temp[i];
  }
  return (hex);
}

main() {
  int dec[5];
  for (int i = 0; i < 5; i++) {
    cout << "enter dec: ";
    cin >> dec[i];
    cout << "      hex: ";
    cout << dec_to_hex(dec[i]) << "\n\n";
  }
}