#include <cassert>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

struct ListEntry {
  int value;
  ListEntry *next;
};

struct List {
  ListEntry *head;
  ListEntry *tail;
};

void ListPush(List *list, int value) {
  assert(list);
  assert(value);

  auto entry = new ListEntry{value};

  if (list->tail == NULL) {
    list->tail = entry;
    list->head = entry;
  } else {
    list->tail->next = entry;
    list->tail = entry;
  }
}

List *ListCreate(std::vector<int> value) {
  auto list = new List{};

  for (auto c : value) {
    ListPush(list, c);
  }

  return list;
}

void ListForEach(List *list, std::function<void(ListEntry *)> callback) {
  assert(list);
  assert(callback);

  auto entry = list->head;

  while (entry != NULL) {
    callback(entry);
    entry = entry->next;
  }
}

void ListDisplay(List *list) {
  assert(list);

  ListForEach(list, [](auto entry) { std::cout << entry->value << " "; });
  std::cout << "\n";
}

void ListTransform(List *list, std::function<int(int, int, int)> callback) {
  assert(list);
  assert(callback);

  int prev = 0;

  ListForEach(list, [&](auto entry) {
    auto new_value =
        callback(entry->value, prev, entry->next ? entry->next->value : 0);

    prev = entry->value;
    entry->value = new_value;
  });
}

void ListAddPrevious(List *list) {
  assert(list);

  ListTransform(list,
                [](auto value, auto prev, auto _) { return value + prev; });
}

void ListWrite(List *list, std::ofstream &file) {
  assert(list);

  ListForEach(list, [&](auto entry) { file << entry->value << " "; });
}

List *ListRead(std::ifstream &file) {
  auto list = new List{};
  int number;

  while (file >> number) {
    ListPush(list, number);
  }

  return list;
}

void ListAddNeighbours(List *list) {
  assert(list);

  ListTransform(list, [](auto _, auto prev, auto next) { return prev + next; });
}

void ListDelete(List *list, ListEntry *prev, ListEntry *current) {
  if (current == list->head) {
    current->next = list->head;
    delete current;
  } else {
    prev->next = current->next;
    delete current;
  }
}

void ListDeleteNegative(List *list) {
  assert(list);
  auto current = list->head;
  ListEntry *prev = NULL;
  while (current != NULL) {
    if (current->value < 0) {
      ListDelete(list, prev, current);
    }
    prev = current;
    current = current->next;
  }
}

int main() {
  // task 3
  std::cout << "Task 3\n";

  auto list = ListCreate(std::vector<int>{1, 2, 3, 4, 5});

  std::cout << "Original list:\n";
  ListDisplay(list);

  ListAddPrevious(list);

  std::cout << "Updated list:\n";
  ListDisplay(list);

  // task 4
  std::cout << "\nTask 4\n";

  const auto file_name = "list_out.txt";

  std::ofstream file_write(file_name, std::fstream::trunc);
  ListWrite(ListCreate(std::vector<int>{10, 20, 30, 40, 50}), file_write);
  file_write.close();

  std::ifstream file_read(file_name);
  list = ListRead(file_read);
  file_read.close();

  std::cout << "Original list:\n";
  ListDisplay(list);

  ListAddNeighbours(list);

  std::cout << "Updated list:\n";
  ListDisplay(list);

  // task 5
  std::cout << "\nTask 5\n";

  auto list2 = ListCreate(std::vector<int>{10, -15, 98, -323, 182, -44});

  std::cout << "Original list:\n";
  ListDisplay(list2);

  ListDeleteNegative(list2);

  std::cout << "Updated list:\n";
  ListDisplay(list2);

  return 0;
}