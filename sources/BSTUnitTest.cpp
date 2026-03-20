#include "BST.h"
#include <iostream>
#include <cassert>

int main(){
    BST<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bst.insert(6);
    bst.insert(7);

    assert(bst.size() == 7);

    std::cout << "bst height: " << bst.height() << '\n';

    std::cout << "is bst balanced? " << (bst.isBalanced()? "Yes": "No") << '\n';

    bst.inOrderTraversal();
    bst.preOrderTraversal();
    bst.postOrderTraversal();

    bst.balanceItSelf();

    std::cout << "After bst is balanced: \n";

    std::cout << "is bst balanced?" << (bst.isBalanced()? "Yes": "No") << '\n';
    bst.inOrderTraversal();
    bst.preOrderTraversal();
    bst.postOrderTraversal();

    if(bst.search(4)) std::cout << "4 is found\n";
    if(bst.search(10)) std::cout << "10 is found\n";

    bst.deleteNode(4);
    if(bst.search(4)) std::cout << "4 is found\n";
    else std::cout << "4 is not found\n";
    
    assert(bst.size() == 6);

    Collection<int> c;
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

    BST<int> balancedBST = BST<int>::buildBalancedBST(v); // copy constructor
    std::cout << "\nis balancedBST balanced? " << (balancedBST.isBalanced()? "Yes": "No") << '\n';
    balancedBST.inOrderTraversal();
    balancedBST.preOrderTraversal();
    balancedBST.postOrderTraversal();

    BST<int> balancedBST2;
    balancedBST2 = balancedBST; // assignment operator
    std::cout << "is balancedBST2 balanced? " << (balancedBST2.isBalanced()? "Yes": "No") << '\n';
    balancedBST2.inOrderTraversal();
    balancedBST2.preOrderTraversal();
    balancedBST2.postOrderTraversal();

    balancedBST.destroyTree();
    assert(balancedBST.isEmpty());

    std::cout << "BST class passes all tests" << std::endl;

    return 0;
}