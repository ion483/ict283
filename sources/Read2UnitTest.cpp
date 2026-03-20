#include "Read2.h"
#include <iostream>
#include <cassert>

int main(){
    Map<int, Map<int, BST<WindRecType>>> m;
    Read2 r("Data_source.txt", m);
    r.readCSV();

    std::cout << "Read2 class passes all tests" << std::endl;

    return 0;
}