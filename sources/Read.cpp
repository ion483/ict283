#include "Read.h"

Read::Read(const std::string& fileN, Vector<WindRecType>& v): fileName(fileN), dataVector(v){}

void Read::readCSV(){
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
        int dateIdx = -1, wsIdx = -1, tempIdx = -1, srIdx = -1; // locate the wanted columns indexes
        for(int i = 0; i < headerV.GetSize(); i++){
            if(headerV[i] == "WAST") dateIdx = i;
            else if(headerV[i] == "S") wsIdx = i;
            else if(headerV[i] == "T") tempIdx = i;
            else if(headerV[i] == "SR") srIdx = i;
        }
        std::string entryStr;
        while(std::getline(sifs, entryStr)){
            std::istringstream entryiss(entryStr);
            std::string entryCell;
            Vector<std::string> entryV;
            while(std::getline(entryiss, entryCell, delimiter)){ // populate the entry vector with entry items
                entryV.Insert(entryCell, entryV.GetSize());
            }
            std::string dateStr, wsStr, tempStr, srStr; // extract the wanted entry items

            if (dateIdx != -1 && dateIdx < entryV.GetSize()) dateStr = entryV[dateIdx];
            if (wsIdx != -1   && wsIdx < entryV.GetSize())   wsStr   = entryV[wsIdx];
            if (tempIdx != -1 && tempIdx < entryV.GetSize()) tempStr = entryV[tempIdx];
            if (srIdx != -1   && srIdx < entryV.GetSize())   srStr   = entryV[srIdx];

            WindRecType record;
            if(!dateStr.empty()){ 
                int year, month, day, hour, minute;
                int result = std::sscanf(dateStr.c_str(), "%d/%d/%d %d:%d", &day, &month, &year, &hour, &minute);
                if(result != 5){ // N/A or invalid format date string
                    continue;
                }
                record.setDate(year, month, day); 
                record.setTime(hour, minute, 0);
                Date d;
                Time_1 t;
                record.getDate(d);
                record.getTime(t);
                if(!d.isValid() || !t.isValid()){ // invalid Date or Time objects (not fit the constraints)
                    continue; 
                }
            }else{ // empty date entry item
                continue;
            }

            try{
                if(!wsStr.empty()){
                    double ws = std::stod(wsStr);
                    record.setSpeed(ws);
                }
            }catch(const std::invalid_argument& e){ // do nothing if conversion fails

            }

            try{
                if(!tempStr.empty()){
                    double airT = std::stod(tempStr);
                    record.setAirT(airT);
                }
            }catch(const std::invalid_argument& e){ // do nothing if conversion fails

            }

            try{
                if(!srStr.empty()){
                    double sr = std::stod(srStr);
                    record.setSr(sr);
                }
            }catch(const std::invalid_argument& e){ // do nothing if conversion fails

            }

            dataVector.Insert(record, dataVector.GetSize());
            size++;
        }
    }
    std::cout << "Data successufully loaded with: " << size << " records\n";
}