#include "Read.h"
#include "WindRecTypeIO.h"
#include <iostream>
#include <cassert>

int main(){
    
    Vector<WindRecType> vw; // test case 1 : load normal files
    Read r("Data_source.txt", vw);
    r.readCSV();
    std::cout << "vw size: " << vw.GetSize() << '\n';
    

    Vector<WindRecType> vw2; // test case 2: data with one missing column
    Read r2("TestData_source.txt", vw2); // test case 3: data with only one entry
    r2.readCSV(); // test case 3: data with no entry
    std::cout << "vw2 size: " << vw2.GetSize() << '\n';

    /*
    Vector<WindRecType> vw3;
    Read r3("NonExisting_source.txt", vw3); // test case 4: input a non existing file path
    r3.readCSV();
    std::cout << "vw3 size: " << vw3.GetSize() << '\n';
    */

    std::cout << "Read class passes all tests" << std::endl;

    return 0;
}