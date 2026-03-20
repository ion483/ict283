#include "Result.h"
#include <cassert>
#include <sstream>

int main(){
    Result defaultResult;
    Unit u("Machine learning", "Ict202", 2);
    Date d(2015, 8, 24);
    defaultResult.SetUnit(u);
    defaultResult.SetMark(90.0);
    defaultResult.SetDate(d);

    Unit uni;
    float mark;
    int unitCredits;
    Date dat;
    defaultResult.GetUnit(uni);
    defaultResult.GetMark(mark);
    defaultResult.GetCredits(unitCredits);
    defaultResult.GetDate(dat);

    assert(unitCredits == 2);
    std::string bufferName;
    std::string bufferId;
    int credits;
    uni.GetName(bufferName);
    uni.GetId(bufferId);
    uni.GetCredits(credits);
    
    assert(bufferName == "Machine learning");
    assert(bufferId == "Ict202");
    assert(mark == 90.0);

    int year, month, day;
    dat.getYear(year);
    dat.getMonth(month);
    dat.getDay(day);

    assert(year == 2015);
    assert(month == 8);
    assert(day == 24);


    Result inputResult;
    std::istringstream iss("Database coding,Ict285,4,95,08/July/2019");
    iss >> inputResult;
    std::cout << "\ninputResult: \n" << inputResult << '\n';

    Unit u2("Data abstraction", "ICT283", 4);
    Date d2(2022, 5, 10);
    Result paramResult(u2, 90.0, d2);
    std::cout << "\nparamResult: \n" << paramResult << std::endl;

    std::cout << "Result class passes all tests" << std::endl;


    return 0;
}