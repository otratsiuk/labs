#include <cassert>
#include <functional>
#include <iostream>

struct Node {
  int num;
  struct Node *left;
  struct Node *right;
};

struct StackEntry {
  StackEntry *next;
  Node *data;
};

struct Stack {
  StackEntry *root;
};

void StackPush(Stack *stack, Node *data) {
  assert(stack);
  assert(data);

  auto entry = new StackEntry();
  entry->next = stack->root;
  entry->data = data;

  stack->root = entry;
}

Node *StackPop(Stack *stack) {
  assert(stack);

  if (stack->root == NULL) {
    return NULL;
  }

  auto root = stack->root;
  auto data = root->data;

  stack->root = root->next;

  delete root;

  return data;
}

void StackDisplay(Stack *stack) {
  auto entry = stack->root;

  while (entry != NULL) {
    std::cout << entry->data->num << " ";
    entry = entry->next;
  }
}

void TreeTraverse(Node *root, std::function<void(Node *)> callback) {
  assert(root);
  assert(callback);

  auto stack = new Stack();
  StackPush(stack, root);

  for (auto node = StackPop(stack); node != NULL; node = StackPop(stack)) {
    callback(node);

    if (node->right)
      StackPush(stack, node->right);
    if (node->left)
      StackPush(stack, node->left);
  }
}

void TreeSwapMinMaxNodes(Node *tree) {
  assert(tree);

  auto min = tree;
  auto max = tree;

  TreeTraverse(tree, [&](auto node) {
    if (node->num < min->num)
      min = node;
    else if (node->num > max->num)
      max = node;
  });

  std::swap(min->num, max->num);
}

void TreeDisplay(Node *node, int depth = 0) {
  assert(node);

  for (auto offset = depth; offset != 0; offset -= 1)
    std::cout << " ";

  std::cout << "(" << node->num << ")\n";

  if (node->left)
    TreeDisplay(node->left, depth + 2);
  if (node->right)
    TreeDisplay(node->right, depth + 2);
}

int main() {
  auto tree =
      new Node{1, new Node{2000, new Node{7}, new Node{42}},
               new Node{3, new Node{16, new Node{25, new Node{-9000}}}}};

  std::cout << "Original tree:\n";
  TreeDisplay(tree);

  TreeSwapMinMaxNodes(tree);

  std::cout << "Updated tree:\n";
  TreeDisplay(tree);

  return 0;
}
