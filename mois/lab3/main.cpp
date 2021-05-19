#include "BinaryTree.h"

int main(int argc, char *argv[]){
    std::string file1(argv[1]);
    std::string file2(argv[2]);

    BinaryTree Tree1(file1);
    BinaryTree Tree2(file2);
    
    std::cout<<"Tree1:\n";
    Tree1.display(Tree1.getRoot(), 0);
    std::cout<<"Tree2:\n";
    Tree2.display(Tree1.getRoot(), 0);

    bool isomorphism = isIsomorphic(Tree1.getRoot(), Tree2.getRoot());

    std::cout<<"Isomorpic: "<<isomorphism<<"\n";
    
    std::cout<<"Tree1 Height: "<<Tree1.height(Tree1.getRoot())<<"\n";

    std::cout<<"Tree1 Is balanced:"<<Tree1.isBalanced(Tree1.getRoot())<<"\n";

    std::cout<<"Tree2 Height: "<<Tree2.height(Tree2.getRoot())<<"\n";

    std::cout<<"Tree2 Is balanced:"<<Tree2.isBalanced(Tree2.getRoot())<<"\n";

    
     
    return 0;
}
