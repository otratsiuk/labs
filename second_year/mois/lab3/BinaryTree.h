#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Tree.h"
#include <cmath>
#include <algorithm>



class BinaryTree{
    Tree::Node *root;
public:
    BinaryTree();
    BinaryTree(std::string &fileName);
    Tree::Node* getRoot();
    void display(Tree::Node *node, int depth );
    Tree::Node* findNode(Tree::Node *root, char value);
    bool isBalanced(Tree::Node *root);
    int height(Tree::Node *node);
    friend Tree::Node *addNode(char value);
};

bool isIsomorphic(Tree::Node *root1, Tree::Node *root2);
