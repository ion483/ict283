#include "Time_1.h"
#include <cassert>

int main(){
    Time_1 t;
    std::string isValid = (t.isValid())? "Valid" : "InValid";
    std::cout << "is t valid: " << isValid << '\n'; // test id 1

    t.setHour(1);
    std::cout << "\nSetting hour for t\n";
    isValid = (t.isValid())? "Valid" : "InValid";
    std::cout << "is t valid: " << isValid << '\n'; // test id 2

    t.setMinute(20);
    std::cout << "\nSetting minute for t\n";
    isValid = (t.isValid())? "Valid" : "InValid";
    std::cout << "is t valid: " << isValid << '\n'; // test id 2

    t.setSecond(10);
    std::cout << "\nSetting second for t\n";
    isValid = (t.isValid())? "Valid" : "InValid";
    std::cout << "is t valid: " << isValid << '\n'; // test id 3

    int hour, minute, second;
    t.getHour(hour);
    t.getMinute(minute);
    t.getSecond(second);

    std::cout << "Hour: " << hour << ", Minute: " << minute << ", Second: " << second << '\n'; // test id 4

    Time_1 t2(12, 30, 5); // test id 5
    std::cout << "Successful object creation\n";

    std::cout << "t == t2? " << (t == t2? "Yes": "No") << '\n'; // test id 6
    std::cout << "t > t2? " << (t > t2? "Yes": "No") << '\n'; // test id 7
    std::cout << "t < t2? " << (t < t2? "Yes": "No") << '\n'; // test id 8

    std::cout << "Time_1 class passes all tests" << std::endl;

    return 0;
}