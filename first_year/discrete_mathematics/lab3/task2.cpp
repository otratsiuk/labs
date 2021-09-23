#include <iostream>

using namespace std;

void merge(int array[], int left, int middle, int right) {
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int Ltemp[n1], Rtemp[n2];
  for (i = 0; i < n1; i++)
    Ltemp[i] = array[left + i];
  for (j = 0; j < n2; j++)
    Rtemp[j] = array[middle + 1 + j];
  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
    if (Ltemp[i] <= Rtemp[j]) {
      array[k] = Ltemp[i];
      i++;
    } else {
      array[k] = Rtemp[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    array[k] = Ltemp[i];
    i++;
    k++;
  }
  while (j < n2) {
    array[k] = Rtemp[j];
    j++;
    k++;
  }
}

void mergeSort(int array[], int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
  }
}

main() {
  int array[] = {4, 12, 8, 3, 88, 0, 55, 1, 182, 90, 444, 372};
  int size = sizeof(array) / sizeof(array[0]);
  mergeSort(array, 0, size - 1);
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << "\n";
}