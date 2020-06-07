#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int MemberOfSequenceBySolution(int num) { return (4 * num - 3) * pow(1, num); }

int MemberOfSequenceByRecursion(int n, int num, int a0, int a1) {
  int an;
  an = 2 * a1 - a0;
  if (num == 0)
    return -3;
  if (num == 1)
    return 1;
  if (n == num)
    return an;
  else
    return MemberOfSequenceByRecursion(n + 1, num, a1, an);
}

void GeneratePermutations(vector<int> array) {
  for (int i = 0; i < array.size(); i++)
    cout << array[i] << " ";
  cout << "\n";
  bool next = 1;
  int i = array.size() - 1;
  while (i > 0 && array[i - 1] >= array[i])
    i--;
  if (i <= 0)
    next = 0;
  else {
    int j = array.size() - 1;
    while (array[j] <= array[i - 1])
      j--;
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;
    j = array.size() - 1;
    while (i < j) {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
  }
  if (next)
    GeneratePermutations(array);
}

void GenerateSubsets(int k, int n, vector<int> set, int count) {
  if (count == n - k || count == 0) {
    for (int i = 0; i < k; i++)
      cout << set[i] << " ";
    cout << "\n";
    count = 0;
  }
  count++;
  bool next = 1;
  int i = set.size() - 1;
  while (i > 0 && set[i - 1] >= set[i])
    i--;
  if (i <= 0)
    next = 0;
  else {
    int j = set.size() - 1;
    while (set[j] <= set[i - 1])
      j--;
    swap(set[i - 1], set[j]);
    j = set.size() - 1;
    while (i < j) {
      swap(set[i], set[j]);
      i++;
      j--;
    }
  }
  if (next)
    GenerateSubsets(k, n, set, count);
}

int main() {
  int num;
  cout << "Enter number of sequence to find: \n";
  cin >> num;
  cout << "By solution: " << MemberOfSequenceBySolution(num) << "\n";
  cout << "By recursion: " << MemberOfSequenceByRecursion(2, num, -3, 1)
       << "\n\n";

  vector<int> array = {1, 2, 3, 4};
  cout << "Permutations: \n";
  GeneratePermutations(array);
  cout << "\n";
  int k, n;
  cout << "Enter k, n: \n";
  cin >> k >> n;
  cout << "Generation of subsets: \n";
  vector<int> set;
  int count = 0;
  for (int i = 0; i < n; i++) {
    set.push_back(i + 1);
  }
  GenerateSubsets(k, n, set, count);
  return 0;
}