#include "Registration.h"
#include <cassert>
#include <sstream>

int main(){
    Registration defaultRegist;
    defaultRegist.SetStudentId(110110);
    defaultRegist.SetSemester(990);
    defaultRegist.SetCount(3);

    Result r1;
    Unit u1("ABC", "i201", 2);
    Date d1(2010, 1, 1);
    r1.SetUnit(u1);
    r1.SetMark(90.0);
    r1.SetDate(d1);

    Result r2;
    Unit u2("DEF", "i202", 3);
    Date d2(2011, 2, 2);
    r2.SetUnit(u2);
    r2.SetMark(91.0);
    r2.SetDate(d2);
    
    Result r3;
    Unit u3("GHI", "i203", 4);
    Date d3(2012, 3, 3);
    r3.SetUnit(u3);
    r3.SetMark(92.0);
    r3.SetDate(d3);

    defaultRegist.SetResult(r1, 0);
    defaultRegist.SetResult(r2, 1);
    defaultRegist.SetResult(r3, 2);

    long studentId;
    int semester;
    int count;

    defaultRegist.GetStudentId(studentId);
    defaultRegist.GetSemester(semester);
    defaultRegist.GetCount(count);

    assert((studentId == 110110) && (semester == 990) && (count == 3));

    for(int i = 0; i < count; i++){
        std::cout << "\nResult " << i+1 << ": \n";
        Result tempResult;
        defaultRegist.GetResult(tempResult, i);
        std::cout << tempResult << '\n';
    }

    int credSum;
    defaultRegist.GetCredits(credSum);
    assert(credSum == 9);

    Registration inputRegist;

    std::istringstream iss("111555,962,4\nCHM 1020,ict203,3,90,01/January/2011\nMUS 1100,ict201,1,97,02/February/2012\nBIO 1040,ict285,4,95,03/March/2013\nMTH 2400,ict333,3,85,04/April/2014");
    iss >> inputRegist;
    std::cout << "\ninputRegist: \n" << inputRegist << '\n';

    std::cout << "Registration class passes all tests" << std::endl;
    
    

    return 0;
}