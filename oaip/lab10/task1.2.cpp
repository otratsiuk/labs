#include <ctime>
#include <iostream>

void ArrayToMatrix(float *A, int k, int m, int n, float **B) {
  int count = 0;
  {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        {
          B[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n && count < k; j++) {
        B[i][j] = A[count];
        count++;
      }
    }
  }
}

main() {
  int k, m, n;
  srand(time(0));
  m = 1 + rand() % 10;
  n = 1 + rand() % 10;
  k = 1 + rand() % 10;
  float *A = new float[k];
  float **B = new float *[m];
  for (int i = 0; i < m; i++) {
    B[i] = new float[n];
  }
  std ::cout << "k = " << k << "\n";
  std ::cout << "m = " << m << "\n";
  std ::cout << "n = " << n << "\n";
  std ::cout << "A array: "
             << "\n";
  for (int i = 0; i < k; i++) {
    A[i] = rand() % 1000 * 0.01;
    std ::cout << A[i] << " ";
  }

  std ::cout << "\n";
  ArrayToMatrix(A, k, m, n, B);
  std ::cout << "Matrix: "
             << "\n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std ::cout << B[i][j] << "\t";
    }
    std ::cout << "\n";
  }
  std ::cout << "\n";
}