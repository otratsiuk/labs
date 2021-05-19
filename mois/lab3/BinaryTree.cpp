#include "BinaryTree.h"
#include <cassert>
#include <vector>
#include <queue>

BinaryTree::BinaryTree():root(nullptr){}

Tree::Node *addNode(char value){
    Tree::Node* node = new Tree::Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

Tree::Node* BinaryTree::getRoot(){
    return root;
}

Tree::Node *BinaryTree::findNode(Tree::Node *node, char value){
    if(node == nullptr){
        return nullptr;
    }
    if(node->value == value){
        return node;
    }

    Tree::Node *node1 = findNode(node->left, value);

    if(node1) return node1;

    Tree::Node *node2 = findNode(node->right, value);

    return node2;
}

BinaryTree::BinaryTree(std::string &fileName){
    std::fstream file(fileName);

    std::vector<Tree::Node*> nodes;
    char ch;
    while(!file.eof()){
          file >> ch;

          while(file.peek() != ',' && !file.eof()){
          if(ch != ',' && ch != '(' && ch!= ')' && file.peek() == ';'){
              nodes.push_back(addNode(ch));
          }
          else if(ch != ',' && ch != '(' && ch!= ')' && file.peek() == ')'){
              nodes.push_back(addNode(ch));
          }
          file>>ch;
          }
      }
    
    root = addNode(nodes[0]->value);

    for(auto i = 0; i < nodes.size() - 1; i++){
        Tree::Node *ptr = findNode(root, nodes[i]->value);
        if(ptr && ptr->left != nullptr && ptr->right == nullptr){
            ptr->right = addNode(nodes[++i]->value);
        }
        if(ptr && ptr->left == nullptr){
            ptr->left = addNode(nodes[++i]->value);
        }
    }
}

void BinaryTree::display(Tree::Node *node, int depth){
  for (auto offset = depth; offset != 0; offset -= 1)
    std::cout << " ";

  std::cout << "(" << node->value << ")\n";

  if (node->left)
    display(node->left, depth + 2);
  if (node->right)
    display(node->right, depth + 2);
}

bool isIsomorphic(Tree::Node *root1, Tree::Node *root2){
 // Both roots are null, trees isomorphic by definition
 if (root1 == nullptr && root2 == nullptr)
    return true;
  
 // Exactly one of the root1 and root2 is null, trees not isomorphic
 if (root1 == nullptr || root2 == nullptr)
    return false;
  
 if (root1->value != root2->value)
    return false;
  
    return 
 (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))||
 (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
}

int BinaryTree::height(Tree::Node *node){
    if (node == NULL)
        return 0;
 
    return 1 + std::max(height(node->left),
                   height(node->right));
}

bool BinaryTree::isBalanced(Tree::Node* root)
{
    int lh;
    int rh;
 
    if (root == NULL)
        return 1;
 
    lh = height(root->left);
    rh = height(root->right);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
 
    return 0;
}
