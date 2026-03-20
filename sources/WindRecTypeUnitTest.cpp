#include "WindRecType.h"
#include <iostream>
#include <cassert>

int main(){
    WindRecType w1;
    w1.setDate(2023, 4, 24); // test id 1
    w1.setTime(12, 3, 0); // test id 1
    w1.setSpeed(10.5); // test id 2
    w1.setAirT(20.0); // test id 2
    w1.setSr(0.5); // test id 2

    Date d; 
    Time_1 t;
    w1.getDate(d); // test id 1
    w1.getTime(t); // test id 1
    int year, month, day;
    int hour, minute, second;
    d.getYear(year);
    d.getMonth(month);
    d.getDay(day);
    t.getHour(hour);
    t.getMinute(minute);
    t.getSecond(second);
    std::cout << "w1 Date: " << "2023/4/24\n";
    std::cout << "w1 Time: " << "12:03.00\n";
    std::cout << "w1 Date year: " << year << " w1 Date month: " << month << " w1 Date day: " << day << '\n'; // test id 1
    std::cout << "w1 Time hour: " << hour << " w1 Time minute: " << minute << " w1 Time second: " << second << '\n'; // test id 1

    double speed, airT, sr; 
    w1.getSpeed(speed);// test id 2
    w1.getAirT(airT);// test id 2
    w1.getSr(sr);// test id 2

    std::cout << "w1 speed: " << speed << " w1 airT: " << airT << " w1 sr: " << sr << '\n';
    assert(speed == 10.5);
    assert(airT == 20.0);
    assert(sr == 0.5);

    WindRecType w2;
    w2.setDate(2023, 4, 24);
    w2.setTime(12, 3, 0);
    w2.setSpeed(11.5);
    w2.setAirT(30.0);
    w2.setSr(0.8);

    std::cout << "Is w1 == w2? " << (w1 == w2 ? "Yes" : "No") << '\n';
    assert((w1 == w2)); // test id 3



    w2.setDate(2025, 4, 20); // test id 4

    std::cout << "Is w1 < w2 (future date)? " << (w1 < w2 ? "Yes" : "No") << '\n';
    assert((w1 < w2)); // test id 4

    w2.setDate(2021, 4, 20); // test id 5

    std::cout << "Is w1 > w2 (past date)? " << (w1 > w2 ? "Yes" : "No") << '\n';
    assert((w1 > w2)); // test id 5

    w2.setDate(2023, 4, 24);
    w2.setTime(20, 10, 0); // test id 6

    std::cout << "Is w1 < w2 (later time)? " << (w1 < w2 ? "Yes" : "No") << '\n';
    assert((w1 < w2)); // test id 6

    w2.setTime(9, 10, 0); // test id 7

    std::cout << "Is w1 > w2 (earlier time)? " << (w1 > w2 ? "Yes" : "No") << '\n';
    assert((w1 > w2)); // test id 7

    
    std::cout << "WindRecType class passes all tests" << std::endl;

    return 0;
}