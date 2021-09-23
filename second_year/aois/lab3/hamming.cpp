#include <algorithm>
#include <cmath>
#include <iostream>

const int n = 15;
const int m = 4;
const double T = 7.5;
const double E = 0.1;
const double e = 0.4;

void display_set(double *set) {
  for (int i = 0; i < n; i++) {
    std::cout << set[i] << "  ";
  }
  std::cout << "\n";
}

double activation_function(double s) {
  if (s <= 0) {
    return 0;
  }
  if (s > 0 && s <= T) {
    return s;
  }
  if (s >= T) {
    return T;
  }
}

int main() {
  double noisy_set[n] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1};

  double vectors[m][n] = {
      {1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1},
      {-1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, 1},
      {1, 1, 1, -1, -1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1},
      {-1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1}};

  double w[m][n] = {};

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      w[i][j] = 0.5 * vectors[i][j];
    }
  }

  double prev_state[m] = {};
  double prev_output[m] = {};

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      prev_state[i] += w[i][j] * noisy_set[j];
    }
    prev_state[i] += T;
    prev_output[i] = activation_function(prev_state[i]);
  }

  double curr_E = E;

  double state[m] = {};
  double curr_output[m] = {};
  std::copy(std::begin(prev_output), std::end(prev_output),
            std::begin(curr_output));

  int best_class = 0;

  do {
    for (int i = 0; i < m; i++) {
      state[i] = 0;
      int counter = 0;
      for (int j = 0; j < m; j++) {
        if (i == j && j != m && j != 0) {
          state[i] += prev_output[j];
        } else if (j != m && j != 0) {
          state[i] += -e * prev_output[j];
        }
        curr_output[i] = activation_function(state[i]);
      }
    }

    curr_E = 0;
    for (int i = 0; i < m; i++) {
      curr_E += std::abs(curr_output[i] - prev_output[i]);
    }
    std::cout << "error: " << curr_E << "\n";
    for (int i = 0; i < m; i++) {
      std::cout << curr_output[i] << " ";
    }
    std::cout << "\n";

    std::copy(std::begin(curr_output), std::end(curr_output),
              std::begin(prev_output));
  } while (curr_E >= E);

  int counter = 0;
  for (int i = 0; i < m; i++) {
    if (curr_output[i] > 0)
      counter++;
  }

  if (counter == 1) {
    for (int i = 0; i < m; i++) {
      if (curr_output[i] > 0) {
        std::cout << i + 1 << " class suits noisy_set:\n";
        display_set(vectors[i]);
        display_set(noisy_set);
      }
    }
  }

  return 0;
}