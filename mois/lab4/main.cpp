#include "forest.h"

int main(){
    Forest forest;
    int num;
    std::cout<<"Enter num of vertexes: ";
    std::cin>>num;

    std::vector<Tree::Node* > Trees = forest.generateTrees(1, num);

    for(auto tree : Trees){
        forest.displayTree(tree, 0);
        std::cout<<"\n";
    }


    std::cout<<"\nThere are isomorphic trees in forest: "
        << forest.hasIsomorphicTrees(Trees)<<"\n";

    std::cout<<"\nNumber of generated trees: "<<Trees.size()<<"\n";    

    return 0;
}
