#include "Read2.h"

Read2::Read2(const std::string& fName, Map<int, Map<int, BST<WindRecType>>>& dMap): fileName(fName), dataMap(dMap){}

void Read2::readCSV(){
    int size = 0;
    std::ifstream ifs(fileName);
    std::cout << "input file name: " << fileName << '\n';
    if(!ifs){
        std::cout << "File not found\n";
        return;
    }
    std::string sourceFileName;
    while(std::getline(ifs, sourceFileName)){
        if(fileName == "Data_source.txt"){
            sourceFileName.insert(0, "data_source/");
        }else if(fileName == "TestData_source.txt"){
            sourceFileName.insert(0, "test_source/");
        }//create ifs from source file name
   
        std::ifstream sifs(sourceFileName);
        std::string headerStr;
        std::getline(sifs, headerStr);
        std::istringstream hiss(headerStr);
        const char delimiter = ',';
        Vector<std::string> headerV;
        std::string headerCell;
        while(std::getline(hiss, headerCell, delimiter)){
            headerV.Insert(headerCell, headerV.GetSize());
        }
        int dateIdx = -1, wsIdx = -1, tempIdx = -1, srIdx = -1;
        for(int i = 0; i < headerV.GetSize(); i++){
            if(headerV[i] == "WAST") dateIdx = i;
            else if(headerV[i] == "S") wsIdx = i;
            else if(headerV[i] == "T") tempIdx = i;
            else if(headerV[i] == "SR") srIdx = i;
        }
        
        std::string entryStr;
        while(std::getline(sifs, entryStr)){
            std::istringstream eiss(entryStr);
            Vector<std::string> entryV;
            std::string entryCell;
            while(std::getline(eiss, entryCell, delimiter)){
                entryV.Insert(entryCell, entryV.GetSize());
            }
            std::string dateStr, wsStr, tempStr, srStr;
            if (dateIdx != -1 && dateIdx < entryV.GetSize()) dateStr = entryV[dateIdx];
            if (wsIdx != -1   && wsIdx < entryV.GetSize())   wsStr   = entryV[wsIdx];
            if (tempIdx != -1 && tempIdx < entryV.GetSize()) tempStr = entryV[tempIdx];
            if (srIdx != -1   && srIdx < entryV.GetSize())   srStr   = entryV[srIdx];


            WindRecType w;

            if(!dateStr.empty()){
                int day, month, year, hour, minute;
                int result = std::sscanf(dateStr.c_str(), "%d/%d/%d %d:%d", &day, &month, &year, &hour, &minute);
                if(result != 5){ /*wrong format eg. "NAN" or wrong order format*/
                    continue;
                }
                w.setDate(year, month, day);
                w.setTime(hour, minute, 0);
                Date d;
                Time_1 t;
                w.getDate(d);
                w.getTime(t);
                if(!d.isValid() || !t.isValid()){ // invalid Date or Time objects (not fit the constraints)
                    continue; 
                }
            }else{
                continue; /*it is empty*/
            }

            try{
                if(!wsStr.empty()){
                    w.setSpeed(std::stod(wsStr));
                }
            }catch(const std::invalid_argument& e){

            }

            try{
                if(!tempStr.empty()){
                    w.setAirT(std::stod(tempStr));
                }
            }catch(const std::invalid_argument& e){

            }

            try{
                if(!srStr.empty()){
                    w.setSr(std::stod(srStr));
                }
            }catch(const std::invalid_argument& e){

            }

            int year, month;
            Date d;
            w.getDate(d);
            d.getYear(year);
            d.getMonth(month);

            dataMap[year][month].insert(w);
            size++;
        }
    }
    
    for(std::map<int, Map<int, BST<WindRecType>>>::iterator itYear = dataMap.begin(); itYear != dataMap.end(); ++itYear){
        Map<int, BST<WindRecType>>& monthMap = itYear -> second;
        for(std::map<int, BST<WindRecType>>::iterator itMonth = monthMap.begin(); itMonth != monthMap.end(); ++itMonth){
            BST<WindRecType>& monthBST = itMonth -> second;
            monthBST.balanceItSelf();
        }      
    }

    std::cout << "Data successfully loaded with: " << size << " data\n";
}