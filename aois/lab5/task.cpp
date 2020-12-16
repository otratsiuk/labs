#include <chrono>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <semaphore.h>
#include <string>
#include <thread>
#include <vector>

const int NUMBER = 10000;
const int POINTS = 4;

sem_t semaphore1;
sem_t semaphore2;

using vec_pairs = std::vector<std::vector<float>>;
using pair = std::vector<float>;

int distance(pair &a, pair &b) {
  auto d = sqrt(pow(abs(a[0] - b[0]), 2) + pow(abs(a[1] - b[1]), 2));

  return d;
}

int perimeter(pair &a, pair &b, pair &c) {
  int perimeter = distance(a, b) + distance(b, c) + distance(c, a);

  return perimeter;
}

int distances_sum(pair &a, pair &b, pair &c, pair &d) {
  int sum = distance(a, d) + distance(b, d) + distance(c, d);

  return sum;
}

bool in_triangle(pair &a, pair &b, pair &c, pair &d) {
  if (distances_sum(a, b, c, d) < perimeter(a, b, c))
    return true;
  else
    return false;
}

void generate_points(vec_pairs &pairs) {
  std::default_random_engine generator;
  std::uniform_real_distribution<float> distribution(20, 50);

  int counter = 0;

  for (auto &pair : pairs) {
    for (auto &crdnt : pair) {
      crdnt = distribution(generator);
    }

    counter += 1;

    if (counter == 4) {
      std::cout << std::left << std::setw(20)
                << "generate thread: " << std::this_thread::get_id() << "\n";
      sem_post(&semaphore1);
      counter = 0;
    }
  }
}

void check_result(vec_pairs &pairs, bool *result) {
  int i = 0;

  for (int i = 0, j = 0; i < POINTS * NUMBER; i += 4, j += 1) {

    sem_wait(&semaphore1);
    std::cout << std::left << std::setw(20)
              << "check thread: " << std::this_thread::get_id() << "\n";

    result[j] = in_triangle(pairs[i], pairs[i + 1], pairs[i + 2], pairs[i + 3]);
    sem_post(&semaphore2);
  }
}

void output(std::string &file_name, vec_pairs &pairs, bool *result) {
  std::ofstream file(file_name, std::ios::trunc);
  file << std::left << std::setw(20) << "x1" << std::setw(20) << "y1"
       << std::setw(20) << "x2" << std::setw(20) << "y2" << std::setw(20)
       << "x3" << std::setw(20) << "y3" << std::setw(20) << "x4"
       << std::setw(20) << "y4" << std::setw(25) << "result"
       << "\n";

  for (int i = 0, j = 0; i < POINTS * NUMBER; i += 4, j++) {
    sem_wait(&semaphore2);

    std::cout << std::left << std::setw(20)
              << "output thread: " << std::this_thread::get_id() << "\n";

    file << std::left << std::setw(20) << pairs[i][0] << std::setw(20)
         << pairs[i][1] << std::setw(20) << pairs[i + 1][0] << std::setw(20)
         << pairs[i + 1][1] << std::setw(20) << pairs[i + 2][0] << std::setw(20)
         << pairs[i + 2][1] << std::setw(20) << pairs[i + 3][0] << std::setw(20)
         << pairs[i + 3][1] << std::setw(25) << result[j] << "\n";
  }
}

int main() {
  vec_pairs pairs(NUMBER * POINTS, std::vector<float>(2));

  bool result[NUMBER];

  std::string file_name("file.txt");

  sem_init(&semaphore1, 1, 0);
  sem_init(&semaphore2, 1, 0);

  std::thread generate(generate_points,
                       std::reference_wrapper<vec_pairs>(pairs));

  std::thread check(check_result, std::reference_wrapper<vec_pairs>(pairs),
                    std::ref(result));

  std::thread console(output, std::ref(file_name),
                      std::reference_wrapper<vec_pairs>(pairs),
                      std::ref(result));

  generate.join();
  check.join();
  console.join();

  return 0;
}