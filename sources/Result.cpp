#include "Result.h"

// default constructor
Result::Result(){
    m_mark = 0.0;
}

// paremeterized constructor
Result::Result(const Unit& u, float mark, const Date& d){
    m_unit = u;
    m_mark = mark;
    m_date = d;
}

// result mark getter
void Result::GetMark(float& mark) const{
    mark = m_mark;
}

// result mark setter
void Result::SetMark(float mark){
    m_mark = mark;
}

// result unit getter
void Result::GetUnit(Unit& unit) const{
    unit = m_unit;
}

// result unit setter
void Result::SetUnit(const Unit& unit){
    m_unit = unit;
}

// result date getter
void Result::GetDate(Date& date) const{
    date = m_date;
}

// result date setter
void Result::SetDate(const Date& date){
    m_date = date;
}

// result unit credits getter
void Result::GetCredits(int& cred) const{
    m_unit.GetCredits(cred);
}

// result input operator
std::istream& operator>>(std::istream& input, Result& r){
    std::string inputStr; // process the input line by line
    std::getline(input, inputStr);
    std::istringstream iss(inputStr);
    const char delimiter = ',';

    Unit tempUnit;
    std::string markStr;
    float mark;
    Date tempDate;

    iss >> tempUnit;

    std::getline(iss, markStr, delimiter);
    try{
        mark = std::stof(markStr);
    }catch(...){
        mark = 0.0;
    }

    iss >> tempDate;

    r.SetUnit(tempUnit);
    r.SetMark(mark);
    r.SetDate(tempDate);

    return input;
}

// result output operator
std::ostream& operator<<(std::ostream& output, const Result& r){
    Unit tempUnit;
    r.GetUnit(tempUnit);
    float mark;
    r.GetMark(mark);
    Date tempDate;
    r.GetDate(tempDate);

    output << tempUnit;
    output << "  Marks:     " << mark << '\n';
    output << tempDate;

    return output;
}