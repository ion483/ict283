#include <iostream>
#include "IntBST.h"


int main(){
    //testing the IntBST
    IntBST intBST;
    intBST.insert(50);
    intBST.insert(30);
    intBST.insert(70);
    intBST.insert(20);
    intBST.insert(40);
    intBST.insert(60);
    intBST.insert(80);
    
    std::cout << "\n--- IntBST ---" << std::endl;
    std::cout << "\n--- Traversals ---" << std::endl;
    std::cout << "In-order (should be sorted): ";
    intBST.inOrderTraversal();

    std::cout << "Pre-order: ";
    intBST.preOrderTraversal();

    std::cout << "Post-order: ";
    intBST.postOrderTraversal();

    intBST.search(50); // node that exists
    intBST.search(99); // node that does not exist

    std::cout << "Deleting leaf node 20" << std::endl;
    intBST.deleteNode(20);
    intBST.inOrderTraversal();

    IntBST copyTree = intBST; // Copy constructor
    std::cout << "Copy Tree In-order: ";
    copyTree.inOrderTraversal();

    return 0;
}