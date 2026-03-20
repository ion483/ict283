#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "BST.h"
#include "Date.h"
#include "DateIO.h"


int main(){
    // doing the ifstream loading to load the date object into a dateBST
    BST<Date> dateBST2;
    std::ifstream ifs("date.txt");
    std::string dateLine;
    int count = 0; // sucessfully inserted Date object count

    while(std::getline(ifs, dateLine)){
        int day, month, year;

        int result = std::sscanf(dateLine.c_str(), "%d/%d/%d", &day, &month, &year);
        if(result != 3){
            continue;
        }
        Date d(year, month, day);
        if(!d.isValid()){
            continue;
        }
        
        if(dateBST2.insert(d)){
            count++;
        }
    }

    std::cout << "Successfully loaded Date object count: " << count << std::endl;
    std::cout << "dateBST2 size: " << dateBST2.size() << std::endl;


    dateBST2.inOrderTraversal();
    dateBST2.preOrderTraversal();
    dateBST2.postOrderTraversal();

    return 0;
}
