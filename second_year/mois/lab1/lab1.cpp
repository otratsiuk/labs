#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <vector>

int find_components_num_in_width(
    std::vector<std::vector<bool>> &adjacency_table) {
  int components_number = 0;
  std::vector<int> state(
      adjacency_table.size()); // -1 if passed, 1 if available, 0 if free

  int chosen = 0;

  while (std::find(state.begin(), state.end(), 0) != state.end()) {

    state[chosen] = -1;

    for (int i = 0; i < state.size(); i++) {
      if (adjacency_table[chosen][i] == 1 && state[i] == 0) {
        state[i] = 1;
      }
    }

    for (int available = 0; available < state.size(); available++) {
      if (state[available] == 1) {
        state[available] = -1;

        for (int i = 0; i < state.size(); i++) {
          if (adjacency_table[available][i] == 1 && state[i] == 0) {
            state[i] = 1;
          }
        }
      }
    }

    if (std::find(state.begin(), state.end(), 1) == state.end()) {
      components_number++;

      for (int i = 0; i < state.size(); i++) {
        if (state[i] == 0) {
          chosen = i;
          break;
        }
      }
    }
  }

  return components_number;
}

int main() {
  std::vector<std::vector<bool>> adjacency{
      {0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0},
      {0, 0, 1, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 0}};

  std::cout << find_components_num_in_width(adjacency) << "\n";

  return 0;
}