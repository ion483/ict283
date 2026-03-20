#include "Collection.h"
#include <iostream>
#include <cassert>

int main(){
    Collection<int> c;
    c.collect(1);
    c.collect(2);
    c.collect(3);

    assert(c[0] == 1);
    assert(c[1] == 2);
    assert(c[2] == 3);

    assert(c.getSize() == 3);

    std::cout << "collection: \n";
    for(int i = 0; i < c.getSize(); i++){
        std::cout << c[i] << " ";
    }
    std::cout << "\nCollection class passes all tests" << std::endl;


    return 0;
}