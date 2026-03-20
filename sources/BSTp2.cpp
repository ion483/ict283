#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "BST.h"
#include "Date.h"
#include "DateIO.h"

void readCSV(std::string fileName, Vector<Date>& dateVector);

int main(){
    // testing template BST
    std::cout << "\n --- Template BST ---" << std::endl;
    Vector<Date> dateV;
    readCSV("Data_source.txt", dateV);
    BST<Date> dateBST = BST<Date>::buildBalancedBST(dateV); // using the static buildBalancedBST function
    std::cout << "is dateBST balanced: " << (dateBST.isBalanced()? "Yes" : "No") << std::endl;
    std::cout << "dateBST size: " << dateBST.size() << std::endl;
    std::cout << "dateBST height: " << dateBST.height() << std::endl;


    Date d1(2011, 1, 1); // search Date that exists
    dateBST.search(d1);

    Date d2(2099, 1, 1); // search Date that does not exist
    dateBST.search(d2);
    
    // delete existing node
    std::cout << "Deleting 01/01/2011..." << std::endl;
    if(dateBST.deleteNode(d1)){
        std::cout << "target deleted, new size: " << dateBST.size() << '\n';
    }else{
        std::cout << "target does not exist in bst" << '\n';
    }

    // delete non existing node
    std::cout << "Deleting 01/01/2099..." << std::endl;
    if(dateBST.deleteNode(d2)){
        std::cout << "target deleted, new size: " << dateBST.size() << '\n';
    }else{
        std::cout << "target does not exist in bst" << '\n';
    }


    // verify the deletion
    dateBST.search(d1);

    return 0;
}

void readCSV(std::string fileName, Vector<Date>& dateVector){
    int size = 0;
    std::ifstream ifs(fileName);
    if(!ifs){
        std::cout << "File not found\n";
        return;
    }
    std::string sourceFileName; // first extract the source file name 
    while(std::getline(ifs, sourceFileName)){
        if(fileName == "Data_source.txt"){
            sourceFileName.insert(0, "data_source/");
        }else if(fileName == "TestData_source.txt"){
            sourceFileName.insert(0, "test_source/");
        }//create ifs from source file name
        
        std::ifstream sifs(sourceFileName);
        std::string headerStr; // read in the header row
        Vector<std::string> headerV;
        std::getline(sifs, headerStr);
        std::istringstream headeriss(headerStr);
        const char delimiter = ',';
        std::string headerCell;
        while(std::getline(headeriss, headerCell, delimiter)){ // populate the header vector with header items
            headerV.Insert(headerCell, headerV.GetSize());
        }
        int dateIdx = -1;// locate the wanted columns indexes
        for(int i = 0; i < headerV.GetSize(); i++){
            if(headerV[i] == "WAST") dateIdx = i;
        }
        std::string entryStr;
        while(std::getline(sifs, entryStr)){
            std::istringstream entryiss(entryStr);
            std::string entryCell;
            Vector<std::string> entryV;
            while(std::getline(entryiss, entryCell, delimiter)){ // populate the entry vector with entry items
                entryV.Insert(entryCell, entryV.GetSize());
            }
            std::string dateStr; // extract the wanted entry items

            if (dateIdx != -1 && dateIdx < entryV.GetSize()) dateStr = entryV[dateIdx];
        
            Date dateObject;
            if(!dateStr.empty()){ 
                int year, month, day, hour, minute;
                int result = std::sscanf(dateStr.c_str(), "%d/%d/%d %d:%d", &day, &month, &year, &hour, &minute);
                if(result != 5){ // N/A or invalid format date string
                    continue;
                }
                dateObject.setYear(year);
                dateObject.setMonth(month);
                dateObject.setDay(day);
                if(!dateObject.isValid()) continue;
            }else{ // empty date entry item
                continue;
            }

            dateVector.Insert(dateObject, dateVector.GetSize());
            size++;
        }
    }
    std::cout << "Data successufully loaded with: " << size << " records\n";
}