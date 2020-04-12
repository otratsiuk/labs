#include <ctime>
#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void ArrayToMatrix(float *A, int k, int m, int n, float **B) {
  int count = 0;
  A = (float *)realloc(A, (m * n) * sizeof(float));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      B[i][j] = A[count];
      count++;
    }
  }
}

main() {
  int k, m, n;
  srand(time(0));
  m = 1 + rand() % 10;
  n = 1 + rand() % 10;
  k = 1 + rand() % 10;
  float *A = (float *)malloc(k * sizeof(float));
  float **B = (float **)malloc(m * sizeof(float *));
  for (int i = 0; i < m; i++) {
    B[i] = (float *)malloc(n * sizeof(float));
  }
  cout << "k = " << k << "\n";
  cout << "m = " << m << "\n";
  cout << "n = " << n << "\n";
  cout << "A array: "
       << "\n";
  for (int i = 0; i < k; i++) {
    A[i] = rand() % 1000 * 0.01;
    cout << A[i] << " ";
  }
  cout << "\n";
  ArrayToMatrix(A, k, m, n, B);
  cout << "Matrix: "
       << "\n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << B[i][j] << "\t";
    }
    cout << "\n";
  }
  cout << "\n";
  free(A);
  free(B);
}