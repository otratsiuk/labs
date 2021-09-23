#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Matrix {
  vector<vector<int>> matrix;
  int sum;
};

void DisplayFile(string &file_name, int n, int m) {
  ifstream file(file_name);
  file.seekg(0, ios::beg);
  int matrix[n][m];
  while (file.read((char *)&matrix, n * m * sizeof(int))) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
  file.close();
}

void FromVectorToFile(vector<Matrix> &matrices, int n, int m,
                      string &file_name) {
  ofstream file(file_name);
  int static_matrix[n][m];
  for (int k = 0; k < matrices.size(); k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        static_matrix[i][j] = matrices[k].matrix[i][j];
      }
    }
    file.write((char *)&static_matrix, n * m * sizeof(int));
  }
}

void AddMatricesToVector(vector<Matrix> &matrices, int k, int n, int m) {
  Matrix matrix;
  for (int q = 0; q < k; q++) {
    for (int i = 0; i < n; i++) {
      matrix.matrix.push_back(vector<int>());
      for (int j = 0; j < m; j++) {
        matrix.matrix[i].push_back(0);
      }
    }
  }
  for (int q = 0; q < k; q++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix.matrix[i][j] = rand() % 1000;
      }
    }
    matrices.push_back(matrix);
  }
}

void CountSum(vector<Matrix> &matrices, int n, int m) {
  int sum = 0;
  for (int q = 0; q < matrices.size(); q++) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int term = matrices[q].matrix[i][j];
        if (term % 2 == 0) {
          sum = sum + term;
        }
      }
    }
    matrices[q].sum = sum;
  }
}

void FillNewFile(string &file_name, vector<Matrix> &matrices, int n, int m) {
  ofstream file(file_name);
  int static_matrix[n][m];
  CountSum(matrices, n, m);
  for (int i = 0; i < matrices.size(); i++) {
    if (matrices[i].sum % 2 == 0) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
          static_matrix[j][k] = matrices[i].matrix[j][k];
        }
      }
      file.write((char *)&static_matrix, n * m * sizeof(int));
    }
  }
  file.close();
}

void UpdateOriginalFile(string &file_name, vector<Matrix> &matrices, int n,
                        int m) {
  ofstream file(file_name);
  file.clear();
  int static_matrix[n][m];
  for (int i = 0; i < matrices.size(); i++) {
    if (matrices[i].sum % 2 == 0) {
      int unit_matrix[n][m];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i == j) {
            unit_matrix[i][j] = 1;
          } else
            unit_matrix[i][j] = 0;
        }
      }
      file.write((char *)&unit_matrix, n * m * sizeof(int));
    } else {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
          static_matrix[j][k] = matrices[i].matrix[j][k];
          file.write((char *)&static_matrix, n * m * sizeof(int));
        }
      }
    }
  }
  file.close();
}

int main() {
  string original_file_name = "matrices1.bin";
  string new_file_name = "matrices2.bin";
  fstream original_file(original_file_name, ios::in | ios::out | ios::trunc);
  fstream new_file(new_file_name, ios::in | ios::out | ios::trunc);

  int k;
  int n;
  int m;
  cout << "enter k: ";
  cin >> k;
  cout << "enter n: ";
  cin >> n;
  cout << "enter m: ";
  cin >> m;
  cout << "\n";

  vector<Matrix> matrices;

  srand(time(0));

  AddMatricesToVector(matrices, k, n, m);
  FromVectorToFile(matrices, n, m, original_file_name);
  cout << "Original file\n";
  DisplayFile(original_file_name, n, m);
  FillNewFile(new_file_name, matrices, n, m);
  cout << "New file\n";
  DisplayFile(new_file_name, n, m);
  UpdateOriginalFile(original_file_name, matrices, n, m);
  cout << "Modified original file\n";
  DisplayFile(original_file_name, n, m);

  return 0;
}