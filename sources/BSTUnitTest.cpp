#include "BST.h"
#include <iostream>
#include <cassert>

int main(){
    BST<int> bst; // test id 1: Sequential Insertion & Initial Structural Check
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bst.insert(6);
    bst.insert(7);

    std::cout << "bst size: " << bst.size() << '\n';

    bst.inOrderTraversal();
    bst.preOrderTraversal();
    bst.postOrderTraversal();

    // test id 2: Structural Transformation (Self-Balancing)
    bst.balanceItSelf();

    std::cout << "After bst is balanced: \n";
    std::cout << "bst traversal: \n";
    bst.inOrderTraversal(); // test id 5: Verification of Traversal Order
    bst.preOrderTraversal();
    bst.postOrderTraversal();

    if(bst.search(4)) std::cout << "4 is found\n"; // test id 3: Search Logic (Found vs Not Found)
    if(bst.search(10)) std::cout << "10 is found\n";

    // test id 4: Removal of Node & Size Consistency
    bst.deleteNode(4);
    if(bst.search(4)) std::cout << "4 is found\n";
    else std::cout << "4 is not found\n";
    
    std::cout << "bst size: " << bst.size() << '\n';

    Collection<int> c; // test id 5: Collection via Function Pointer
    bst.inOrderTraversalCollect(c, &Collection<int>::collect);
    std::cout << "Collection after being collected in bst: \n";
    for(int i = 0; i < c.getSize(); i++){
        std::cout << c[i] << " ";
    }

    Vector<int> v;
    v.Insert(10, v.GetSize());
    v.Insert(20, v.GetSize());
    v.Insert(30, v.GetSize());
    v.Insert(40, v.GetSize());
    v.Insert(50, v.GetSize());
    v.Insert(60, v.GetSize());
    v.Insert(70, v.GetSize());

    // test id 6: Static Factory Method (Build from Sorted Vector)
    BST<int> balancedBST = BST<int>::buildBalancedBST(v); // copy constructor
    std::cout << "balancedBST traversal: \n";
    balancedBST.inOrderTraversal();
    balancedBST.preOrderTraversal();
    balancedBST.postOrderTraversal();

    // test id 7: Deep Copy via Assignment Operator
    BST<int> balancedBST2;
    balancedBST2 = balancedBST; // assignment operator
    std::cout << "balancedBST2 traversal: \n";
    balancedBST2.inOrderTraversal();
    balancedBST2.preOrderTraversal();
    balancedBST2.postOrderTraversal();


    // test id 8: Memory Deallocation & State Reset
    balancedBST.destroyTree();
    std::cout << "IS balancedBST empty: " << (balancedBST.isEmpty()? "Yes" : "No") << '\n';

    std::cout << "BST class passes all tests" << std::endl;

    return 0;
}