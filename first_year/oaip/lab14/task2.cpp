#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

struct QueueEntry {
  char data;
  QueueEntry *next;
  QueueEntry *prev;
};

struct Queue {
  QueueEntry *head;
  QueueEntry *tail;
};

bool QueueIsEmpty(Queue *queue) {
  assert(queue);

  return queue->tail == NULL;
}

void QueuePush(Queue *queue, char data) {
  assert(queue);
  assert(data);

  auto entry = new QueueEntry{data};

  if (queue->tail == NULL) {
    queue->tail = entry;
    queue->head = entry;
  } else {
    entry->next = queue->tail;
    queue->tail->prev = entry;
    queue->tail = entry;
  }
}

char QueuePop(Queue *queue) {
  assert(queue);
  assert(!QueueIsEmpty(queue));

  auto head = queue->head;
  auto data = head->data;

  queue->head = head->prev;

  if (queue->head == NULL)
    queue->tail = NULL;

  delete head;

  return data;
}

Queue *QueueCreate(std::vector<char> data) {
  auto queue = new Queue();

  for (auto c : data) {
    QueuePush(queue, c);
  }

  return queue;
}

void QueueDisplay(Queue *queue) {
  auto entry = queue->tail;

  while (entry != NULL) {
    std::cout << entry->data << " ";
    entry = entry->next;
  }
}

void WriteQueues(std::vector<Queue *> queues, std::ofstream &file) {
  assert(file);

  for (auto queue : queues) {
    while (!QueueIsEmpty(queue)) {
      file << QueuePop(queue);
    }

    file << "\n";
  }
}

int main() {
  auto queues =
      std::vector<Queue *>{QueueCreate(std::vector<char>{'b', 'a', 'b', 'y'}),
                           QueueCreate(std::vector<char>{'y', 'o', 'd', 'a'})};

  std::ofstream file("queue_out.txt");

  WriteQueues(queues, file);

  file.close();
  return 0;
}