#include "Date.h"
#include <cassert>
#include <fstream>

int main(){
    Date d;
    std::string isValid = (d.isValid())? "valid": "invalid";
    std::cout << "is d valid: " << isValid << '\n'; // test id 1

    d.setYear(2020);
    std::cout << "set the year\n";
    isValid = (d.isValid())? "valid": "invalid";
    std::cout << "is d valid: " << isValid << '\n'; // test id 2

    d.setMonth(5);
    std::cout << "set the month\n";
    isValid = (d.isValid())? "valid": "invalid";
    std::cout << "is d valid: " << isValid << '\n'; // test id 2

    d.setDay(10);
    std::cout << "set the day\n";
    isValid = (d.isValid())? "valid": "invalid";
    std::cout << "is d valid: " << isValid << '\n'; // test id 3

    int year, month, day;
    d.getYear(year);
    d.getMonth(month);
    d.getDay(day);

    std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day << '\n'; // test id 4

    Date d2(2018, 2, 5); // test id 5
    std::cout << "Successful object creation\n";
    
    std::cout << "d == d2? " << (d == d2? "Yes": "No") << '\n'; // test id 6
    std::cout << "d < d2? " << (d < d2? "Yes": "No") << '\n'; // test id 7
    std::cout << "d > d2? " << (d > d2? "Yes": "No") << '\n'; // test id 8

    std::cout << "Date class passes all tests" << std::endl;


    return 0;
}