#include "Date.h"

// default constructor
Date::Date(){
    m_year = -1;
    m_month = -1;
    m_day = -1;
    m_isValid = false;
}

// paremeterized constructor
Date::Date(int year, int monthInt, int day){
    if(!checkDate(year, monthInt, day)){
        m_year = -1;
        m_month = -1;
        m_day = -1;
        m_isValid = false;
        return;
    }
    m_year = year;
    m_month = monthInt;
    m_day = day;
    m_isValid = true;
}

// m_year getter
void Date::getYear(int& year) const{
    year = m_year;
}

// m_year setter
void Date::setYear(int newYear){
    if(newYear >= 0) m_year = newYear;
    m_isValid = checkDate(m_year, m_month, m_day);
}

// m_month getter
void Date::getMonth(int& month) const{
    month = m_month;
}

// m_month setter
void Date::setMonth(int newMonth){
    if(newMonth > 0 && newMonth < 13) m_month = newMonth;
    m_isValid = checkDate(m_year, m_month, m_day);
}

// m_day getter
void Date::getDay(int& day) const{
    day = m_day;
}

// m_day setter
void Date::setDay(int newDay){
    if(newDay > 0 && newDay < 32) m_day = newDay;
    m_isValid = checkDate(m_year, m_month, m_day);
}

bool Date::checkDate(int year, int month, int day) const{
    if(year < 0) return false;
    if(month <= 0 || month >= 13) return false;
    if(day <= 0 || day >= 32) return false;
    return true;
}

bool Date::isValid() const{
    return m_isValid;
}

// date equality comparison operator
bool Date::operator==(const Date& other) const{
    return other.m_year == m_year && other.m_month == m_month && other.m_day == m_day;
}

// date inequality comparison operator
bool Date::operator!=(const Date& other) const{
    return !(*this == other);
}

// date greater comparison operator
bool Date::operator>(const Date& other) const{
    if(other.m_year != m_year) return m_year > other.m_year;
    if(other.m_month != m_month) return m_month > other.m_month;
    return m_day > other.m_day;
}

// date less comparison operator
bool Date::operator<(const Date& other) const{
    return other > *this;
}