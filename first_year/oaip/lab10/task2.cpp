#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string dec_to_hex(int dec) {
  static char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  int length = 1;
  string hex;
  int num = dec;
  int rest;
  while (num != 0) {
    length++;
    num /= 16;
  }
  if (dec != 0) {
    for (int i = length - 1; dec != 0 && i >= 0; i--) {
      rest = dec % 16;
      dec /= 16;
      hex.push_back(digits[rest]);
    }
  } else {
    hex.push_back('0');
  }

  // Reverse string
  reverse(hex.begin(), hex.end());
  return hex;
}

int main() {
  int dec[5];
  for (int &i : dec) {
    cout << "enter dec: ";
    cin >> i;
    cout << "      hex: ";
    cout << dec_to_hex(i) << "\n\n";
  }

  return 0;
}