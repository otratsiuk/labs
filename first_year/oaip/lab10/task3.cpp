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
  cout << "enter n(n > 0): ";
  cin >> n;
  while (n <= 0) {
    cout << "wrong input, enter n(n > 0) again\n";
    cin >> n;
  }
  for (int i = 0; i < 5; i++) {
    cout << "enter k(0 <= k <= n): ";
    cin >> k[i];
    while (k[i] < 0 || k[i] > n) {
      cout << "wrong input, enter n(n > 0) again\n";
      cin >> k[i];
    }
    c = combin1(n, k[i]);
    cout << "c: " << c << "\n";
    cout << "function call counter: " << fuction_call_counter << "\n";
    fuction_call_counter = 0;
  }
}
