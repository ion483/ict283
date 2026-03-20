#include "Time_1.h"

Time_1::Time_1(){ // The defualt value is set to -1 unlike 0 in date, because 0 is valid in Time_1 and not in Date
    m_hour = -1;
    m_minute = -1;
    m_second = -1;
    m_isValid = false;
}

Time_1::Time_1(int hour, int minute, int second){
    if(!checkTime(hour, minute, second)){
        m_hour = -1;
        m_minute = -1;
        m_second = -1;
        m_isValid = false;
        return;
    }
    m_hour = hour;
    m_minute = minute;
    m_second = second;
    m_isValid = true;
}

void Time_1::getHour(int& hour) const{
    hour = m_hour;
}

void Time_1::setHour(int newHour){
    if(newHour >= 0 && newHour <= 23) m_hour = newHour;
    m_isValid = checkTime(m_hour, m_minute, m_second); // update the m_isValid flag after setting a new hour
}

void Time_1::getMinute(int& minute) const{
    minute = m_minute;
}

void Time_1::setMinute(int newMinute){
    if(newMinute >= 0 && newMinute <= 59) m_minute = newMinute;
    m_isValid = checkTime(m_hour, m_minute, m_second); // update the m_isValid flag after setting a new minute
}

void Time_1::getSecond(int& second) const{
    second = m_second;
}

void Time_1::setSecond(int newSecond){
    if(newSecond >= 0 && newSecond <= 59) m_second = newSecond;
    m_isValid = checkTime(m_hour, m_minute, m_second); // update the m_isValid flag after setting a new second
}

bool Time_1::checkTime(int hour, int minute, int second) const{
    if(hour < 0 || hour > 23) return false;
    if(minute < 0 || minute > 59) return false;
    if(second < 0 || second > 59) return false;
    return true;
}

bool Time_1::isValid() const{
    return m_isValid;
}

bool Time_1::operator==(const Time_1& other) const{
    return m_hour == other.m_hour && m_minute == other.m_minute && m_second == other.m_second;
}

bool Time_1::operator>(const Time_1& other) const{
    if(m_hour != other.m_hour) return m_hour > other.m_hour;
    if(m_minute != other.m_minute) return m_minute > other.m_minute;
    return m_second > other.m_second;
}

bool Time_1::operator<(const Time_1& other) const{
    return other > *this;
}