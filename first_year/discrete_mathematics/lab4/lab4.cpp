#include <iostream>
#include <string>

using namespace std;

bool function(int x, int y, int z) { return ((!x & y) ^ z); }

string sdnf(int x[], int y[], int z[], int f[]) {
  string sdnf;
  for (int i = 0; i < 8; i++) {
    if (f[i] == 1) {
      if (x[i] == 1)
        sdnf.append(" x&");
      else
        sdnf.append(" !x&");
      if (y[i] == 1)
        sdnf.append("y&");
      else
        sdnf.append("!y&");
      if (z[i] == 1)
        sdnf.append("z |");
      else
        sdnf.append("!z |");
    }
  }
  sdnf.pop_back();
  return sdnf;
}

string sknf(int x[], int y[], int z[], int f[]) {
  string sdnf;
  for (int i = 0; i < 8; i++) {
    if (f[i] == 0) {
      if (x[i] == 0)
        sdnf.append(" x|");
      else
        sdnf.append(" !x|");
      if (y[i] == 0)
        sdnf.append("y|");
      else
        sdnf.append("!y|");
      if (z[i] == 0)
        sdnf.append("z &");
      else
        sdnf.append("!z &");
    }
  }
  sdnf.pop_back();
  return sdnf;
}

string ZhegalkinPolynomial(int x[], int y[], int z[], int f[]) {
  string polynomial;
  int triangle[8][8] = {0};
  int n = 7;
  for (int i = 0; i < 8; i++) {
    triangle[0][i] = f[i];
  }
  for (int i = 1; i < 8; i++) {
    for (int j = 0; j < n; j++) {
      triangle[i][j] = triangle[i - 1][j] ^ triangle[i - 1][j + 1];
    }
    n--;
  }
  int diagonal[8];
  for (int i = 0; i < 8; i++) {
    diagonal[i] = triangle[i][0];
  }
  for (int i = 0; i < 8; i++) {
    if (diagonal[i] == 1) {
      if (x[i] == 1)
        polynomial.push_back('x');
      if (y[i] == 1)
        polynomial.push_back('y');
      if (z[i] == 1)
        polynomial.push_back('z');
      if (x[i] == 0 && y[i] == 0 && z[i] == 0)
        polynomial.push_back('1');
      polynomial.append(" ^ ");
    }
  }
  polynomial.erase(polynomial.length() - 2, 2);
  return polynomial;
}

void PostClasses(int x[], int y[], int z[], int f[]) {
  if (f[0] == 0) {
    cout << "zero saving function\n";
  } else
    cout << "not zero saving function\n";
  if (f[7] == 1) {
    cout << "unit saving function\n";
  } else
    cout << "not unit saving function\n";
  string polynomial = ZhegalkinPolynomial(x, y, z, f);
  int count = 0;
  for (int i = 0; i < polynomial.length(); i++) {
    if (polynomial[i] == '^')
      count++;
  }
  string conjunctions[count + 1];
  for (int i = 0, j = 0; i < polynomial.length(), j < count + 1; i++) {
    if (polynomial[i] != '^')
      conjunctions[j].push_back(polynomial[i]);
    else
      j++;
  }
  bool linearity = 1;
  int power_count = 0;
  for (int i = 0; i < count + 1; i++) {
    power_count = 0;
    for (int j = 0; j < conjunctions[i].length(); j++) {
      if (conjunctions[i][j] == 'x' || conjunctions[i][j] == 'y' ||
          conjunctions[i][j] == 'z') {
        power_count++;
      }
      if (conjunctions[i][j] > 1)
        linearity = 0;
    }
    if (power_count > 1)
      linearity = 0;
  }
  if (linearity == 0) {
    cout << "not linear function\n";
  } else
    cout << "linear function\n";
  if (f[7] >= f[6] && f[6] >= f[2] && f[2] >= f[0] && f[7] >= f[5] &&
      f[5] >= f[4] && f[5] >= f[1] && f[4] >= f[0] && f[1] >= f[0] &&
      f[7] >= f[3] && f[3] >= f[2]) {
    cout << "monotonous function\n";
  } else
    cout << "not monotonous function\n";
  if (f[0] != f[7] && f[1] != f[6] && f[2] != f[5] && f[3] != f[4]) {
    cout << "self-dual function\n";
  } else
    cout << "not self-dual function\n\n";
}

void DualFunction(int x[], int y[], int z[], int f[]) {
  int f2[8];
  for (int i = 0; i < 8; i++) {
    f2[i] = !f[i];
  }
  cout << "\ntruth table for dual function: \n\n"
       << "x y z   f\n";
  for (int i = 0, j = 7; i < 8; i++, j--) {
    cout << x[i] << " " << y[i] << " " << z[i] << "   " << f2[j] << "\n";
  }
  cout << "\n";
}

int main() {
  int x[8] = {0, 0, 0, 0, 1, 1, 1, 1}, y[8] = {0, 0, 1, 1, 0, 0, 1, 1},
      z[8] = {0, 1, 0, 1, 0, 1, 0, 1}, f[8];
  for (int i = 0; i < 8; i++) {
    f[i] = function(x[i], y[i], z[i]);
  }
  cout << "\ntruth table: \n\n"
       << "x y z   f\n";
  for (int i = 0; i < 8; i++) {
    cout << x[i] << " " << y[i] << " " << z[i] << "   " << f[i] << "\n";
  }
  cout << "\nSDNF: \n";
  cout << sdnf(x, y, z, f) << "\n";
  cout << "\nSKNF: \n" << sknf(x, y, z, f) << "\n";
  cout << "\nZhegalkin polynomial: \n"
       << ZhegalkinPolynomial(x, y, z, f) << "\n";
  cout << "\n";
  PostClasses(x, y, z, f);
  DualFunction(x, y, z, f);
}