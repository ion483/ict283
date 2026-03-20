#include "WindRecType.h"

WindRecType::WindRecType(): speed(NAN), airT(NAN), sr(NAN) {};

void WindRecType::getDate(Date& date) const{
    date = d;
}

void WindRecType::setDate(const int& year, const int& month, const int& day){
    d.setYear(year);
    d.setMonth(month);
    d.setDay(day);
}

void WindRecType::getTime(Time_1& time) const{
    time = t;
}

void WindRecType::setTime(const int& hour, const int& minute, const int& second){
    t.setHour(hour);
    t.setMinute(minute);
    t.setSecond(second);
}

void WindRecType::getSpeed(double& nSpeed) const{
    nSpeed = speed;
}

void WindRecType::setSpeed(const double& nSpeed){
    speed = nSpeed;
}

void WindRecType::getAirT(double& nAirT) const{
    nAirT = airT;
}

void WindRecType::setAirT(const double& nAirT){
    airT = nAirT;
}

void WindRecType::getSr(double& nSr) const{
    nSr = sr;
}

void WindRecType::setSr(const double& nSr){
    sr = nSr;
}

bool WindRecType::operator==(const WindRecType& other) const{
    return d == other.d && t == other.t;
}

bool WindRecType::operator>(const WindRecType& other) const{
    if(!(d == other.d)) return d > other.d;
    return t > other.t;
}

bool WindRecType::operator<(const WindRecType& other) const{
    return other > *this;
}


