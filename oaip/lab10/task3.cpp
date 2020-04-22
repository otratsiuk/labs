#include <iostream>

using namespace std;

int fuction_call_counter = 0;

int combin1(int n, int k) {
  int c;
  if (k == 0 || n == k) {
    return 1;
    fuction_call_counter = 1;
  }
  fuction_call_counter += 2;
  c = combin1(n - 1, k) + combin1(n - 1, k - 1);
  return (c);
}

main() {
  int n;
  int k[5];
  int c;
  cout << "enter n: ";
  cin >> n;
  for (int i = 0; i < 5; i++) {
    cout << "enter k: ";
    cin >> k[i];
    c = combin1(n, k[i]);
    cout << "      c: " << c << "\n";
    cout << "function call counter: " << fuction_call_counter << "\n";
    fuction_call_counter = 0;
  }
}