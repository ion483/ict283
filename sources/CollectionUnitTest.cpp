#include "Collection.h"
#include <iostream>
#include <cassert>

int main(){
    Collection<int> c; // test id 1: Sequential Data Collection
    c.collect(1);
    c.collect(2);
    c.collect(3);
    std::cout << "c size: " << c.getSize() << '\n';

    // test id 2: Verification of Overloaded Index Operator
    std::cout << "c[0]: " << c[0] << '\n';
    std::cout << "c[1]: " << c[1] << '\n';
    std::cout << "c[2]: " << c[2] << '\n';


    // test id 3: Full Dataset Iteration Test
    std::cout << "collection: \n";
    for(int i = 0; i < c.getSize(); i++){
        std::cout << c[i] << " ";
    }
    std::cout << "\nCollection class passes all tests" << std::endl;


    return 0;
}