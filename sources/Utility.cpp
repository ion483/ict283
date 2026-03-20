#include "Utility.h"


const std::string* Utility::monthToStr(int monthNumber){
    static const std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    if(monthNumber <= 0 || monthNumber >= 13) return nullptr;
    return &months[monthNumber-1];
}

int Utility::monthStrToInt(const std::string& monthStr){
    static const std::string months[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    std::string lowerMonthStr = monthStr;
    
    for(int i = 0; i < lowerMonthStr.length(); i++){
        lowerMonthStr[i] = std::tolower(lowerMonthStr[i]);
    }

    std::regex pattern(" ");
    std::string formattedLowerMonthStr = std::regex_replace(lowerMonthStr, pattern, "");

    for(int i = 0; i < 12; i++){
        if(months[i] == formattedLowerMonthStr){
            return i + 1;
        }
    }
    return -1;
}