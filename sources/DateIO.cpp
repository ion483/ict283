#include "DateIO.h"

// date input operator
/*so in the input operator, we designed a two layer filtering for setting year, month, and day,
  the first layer is parsing, we ensured there is no error during parsing for day and year,
  the second layer is constraint checking, after parsing, we check if the day is withing the constraint,
  and the month string should also fit the constraint, and after these two layers, if there is no error, 
  then we can set year, month, and day of the Date object, eles it will be all 0.
 */
std::istream& operator>>(std::istream& is, Date& d){
    std::string inputStr;
    std::getline(is, inputStr);

    Utility u;

    std::istringstream iss(inputStr);
    const char delimiter = '/';
    std::string cell;
    int day, month, year;
    std::string monthStr;
    try{ // if any of the day, month, and year has problem with conversion, the whole date remains unchanged
        std::getline(iss, cell, delimiter);
        day = std::stoi(cell);
        std::getline(iss, cell, delimiter);
        monthStr = cell;
        month = u.monthStrToInt(monthStr);
        std::getline(iss, cell, delimiter);
        year = std::stoi(cell);

        if(!d.checkDate(year, month, day)) throw std::invalid_argument("Invalid Date");

        d.setYear(year);
        d.setMonth(month);
        d.setDay(day);
    }catch(const std::exception& e){
        std::cout << "Input operator failed for Date" << std::endl;
    }
    return is;
}

// date output operator
std::ostream& operator<<(std::ostream& os, const Date& d){
    int year, monthInt, day;
    d.getYear(year);
    d.getMonth(monthInt);
    d.getDay(day);

    Utility u;

    const std::string* monthptr = u.monthToStr(monthInt);
    std::string month;
    if(monthptr != nullptr){
        month = *monthptr;
    }else{
        month = "Unknown-Month";
    }
    

    os << "Date:      ";
    if(day >= 32 || day <= 0){
        os << "Unknown-Day" << ' ';
    }else{
        if(day < 10){
            os << "0" << day << ' ';
        }else{
            os << day << ' ';
        }
    }
    os << month << ' ';
    if(year < 0){
        os << "Unknown-Year";
    }else{
        os << year;
    }
    
    os << '\n';
    return os;
}