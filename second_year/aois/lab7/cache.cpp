#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

const int CACHE_STRINGS = 16;
const int CACHE_BLOCKS = 2;

const int MEMORY_STRINGS = 512;

const int CACHE_INDEX = 30;
const int BLOCK_OFFSET = 1;
const int CACHE_TAG = 480;

const int n = 8;

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0, MEMORY_STRINGS);

void binary(int n) {
  if (n)
    (binary(n >> 1), std::cout << (n & 1));
}

class Block {
private:
  char data[8] = {'_', '_', '_', '_', '_', '_', '_', '_'};
  int adress = 0;

public:
  Block(){};

  Block(std::string word) {
    for (int i = 0; i < n && i < word.length(); i++) {
      data[i] = word[i];
    }
  }

  void set_adress(int _adress) { adress = _adress; }

  int get_adress() { return adress; }

  friend std::ostream &operator<<(std::ostream &stream, Block block);
};

std::ostream &operator<<(std::ostream &stream, Block block) {
  for (int i = 0; i < n; i++) {
    std::cout << block.data[i];
  }
  return stream;
}

int generate_adress() {
  int num = distribution(generator);

  return num;
}

class Cache {
private:
  Block memory[CACHE_STRINGS][CACHE_BLOCKS];
  int TAG[CACHE_STRINGS][CACHE_BLOCKS] = {};

public:
  void add(Block block) {
    int offset = block.get_adress() & BLOCK_OFFSET;

    int index = block.get_adress() & CACHE_INDEX;
    index = index >> BLOCK_OFFSET;

    int tag = block.get_adress() & CACHE_TAG;
    tag = tag >> 5;

    memory[index][offset] = block;
    TAG[index][offset] = tag;
  };

  int get_tag(Block block) {
    int offset = block.get_adress() & BLOCK_OFFSET;

    int index = block.get_adress() & CACHE_INDEX;
    index = index >> BLOCK_OFFSET;

    return TAG[index][offset];
  }

  void display() {
    for (int i = 0; i < CACHE_STRINGS; i++) {
      if (i == 0)
        std::cout << "0";
      binary(i);
      std::cout << "\t\t";
      for (int j = 0; j < CACHE_BLOCKS; j++) {
        std::cout << std::right << std::setw(4) << "(";
        if (memory[i][j].get_adress() == 0) {
          std::cout << "________";
        }
        binary(memory[i][j].get_adress());
        std::cout << ")\t" << memory[i][j] << "\tTAG\t"
                  << "(";
        if (TAG[i][j] == 0) {
          std::cout << "____";
        }
        binary(TAG[i][j]);
        std::cout << ")\t\t";
      }
      std::cout << "\n";
    }
  }
};

int main() {
  Cache cache;
  Block blocks[10] = {Block("may"),    Block("summer"),  Block("winter"),
                      Block("spring"), Block("autumn"),  Block("january"),
                      Block("june"),   Block("october"), Block("july"),
                      Block("march")};

  for (int i = 0; i < 10; i++) {
    blocks[i].set_adress(generate_adress());
    cache.add(blocks[i]);
  }

  std::cout << "summer adress: ";
  binary(blocks[1].get_adress());
  std::cout << "\n";

  std::cout << "october adress: ";
  binary(blocks[7].get_adress());
  std::cout << "\n";

  cache.display();

  return 0;
}