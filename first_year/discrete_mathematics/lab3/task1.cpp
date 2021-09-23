#include <iostream>

using std::cout;

main() {
  int m = 4;
  int n = 4;
  int B[n] = {1, 2, 3, 4};
  int C[m] = {5, 6, 7, 8};
  int r = 4;
  int S[r][2] = {{1, 8}, {2, 6}, {3, 5}, {4, 7}};
  int matrix[m][n];
  for (int i = 0, t = 0; t < r; i++) {
    for (int j = 0; j < m; j++) {
      if (B[i] == S[t][0] && C[j] == S[t][1]) {
        matrix[j][i] = 1;
        t++;
      } else
        matrix[j][i] = 0;
    }
  }
  bool function = 1;
  int functionality;
  bool surjection = 1;
  bool injection = 1;
  int type = 0;
  for (int i = 0; i < n; i++) {
    functionality = 0;
    for (int j = 0; j < m; j++) {
      if (matrix[j][i] == 1)
        functionality++;
    }
    if (functionality == 0 || functionality > 1)
      function = 0;
  }
  if (function == 1) {
    cout << "given relation is a function\n";
    for (int i = 0; i < m; i++) {
      type = 0;
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 1)
          type++;
      }
      if (type > 1) {
        injection = 0;
      }
      if (type == 0) {
        surjection = 0;
      }
    }
    if (surjection == 1) {
      cout << "this function is surjective\n";
    }
    if (surjection == 0) {
      cout << "this function is not surjective\n";
    }
    if (injection == 1) {
      cout << "this function is injective\n";
    }
    if (injection == 0) {
      cout << "this function is not injective\n";
    }
    if (surjection == 1 && injection == 1) {
      cout << "this function is bijective\n";
    }
  } else
    cout << "given relation is not a function\n";
}