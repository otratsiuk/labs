#pragma once
#include "Tree.h"
#include <iostream>
#include <vector>

class Forest{
private:    
    int num;
    int genNum = 0;
public:
    Forest(){}

    void displayTree(Tree::Node* node, int depth){
        for (auto offset = depth; offset != 0; offset -= 1)
            std::cout << " ";

        std::cout << "(" << node->value << ")\n";
        if (node->left)
            displayTree(node->left, depth + 2);
        if (node->right)
            displayTree(node->right, depth + 2);    
    }

    void preorder(Tree::Node *root){
        if (root != NULL){
            std::cout << root->value<< " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    bool isIsomorphic(Tree::Node *root1, Tree::Node *root2){
    // Both roots are null, trees isomorphic by definition
        if (root1 == nullptr && root2 == nullptr)
            return true;
    // Exactly one of the root1 and root2 is null, trees not isomorphic
        if (root1 == nullptr || root2 == nullptr){
            return false;
        }
        if (root1->value != root2->value){
            return false;
        }   
        return (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))||
        (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
}

    bool hasIsomorphicTrees(std::vector<Tree::Node*> vec){
        bool has = false;
        for(auto i : vec){
            for(int j = 0; j < vec.size(); j++){
                if(isIsomorphic(i, vec[j]) == true){
                    has == true;
                }
            }
        }
        return has;
    }

    std::vector<Tree::Node*> generateTrees(int start, int end){
        std::vector<Tree::Node*> list;

        if(start > end){
            list.push_back(nullptr);
            return list;
        }

        for(int i = start; i <= end; i++){
           std::vector<Tree::Node* > leftSubtree = generateTrees(start, i - 1);
           std::vector<Tree::Node* > rightSubtree = generateTrees(i + 1, end);

           for(int j = 0; j < leftSubtree.size(); j++){
               Tree::Node* left = leftSubtree[j];
               for(int k = 0; k < rightSubtree.size(); k++){
                   Tree::Node* right = rightSubtree[k];
                   Tree::Node* root = Tree::addNode(i);
                   root->left = left;
                   root->right = right;
                   list.push_back(root);
                   genNum++;
               }
           }
        }
        return list;
    }
};
