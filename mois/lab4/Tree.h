#pragma once

namespace Tree {
    struct Node{
        int value;
        struct Node *left;
        struct Node *right;
    };

    Tree::Node *addNode(int value){
        Tree::Node* node = new Tree::Node;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;

        return node;
    }
};  
