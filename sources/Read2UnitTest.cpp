#include "Read2.h"
#include <iostream>
#include <cassert>

int main(){
    Map<int, Map<int, BST<WindRecType>>> m; // test case 1: load normal files
    Read2 r("Data_source.txt", m);
    r.readCSV();


    Map<int, Map<int, BST<WindRecType>>> m2; // test case 2: data with one missing column
    Read2 r2("TestData_source.txt", m2); // test case 3: data with only one entry and data with no entry
    r2.readCSV();


    Map<int, Map<int, BST<WindRecType>>> m3; // test case 4: input a non-exisiting file path
    Read2 r3("NonExisting_source.txt", m3);
    r3.readCSV();


    std::cout << "Read2 class passes all tests" << std::endl;

    return 0;
}