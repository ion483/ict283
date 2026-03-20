#include "Time_1IO.h"

// output operator
std::ostream& operator<<(std::ostream& os, const Time_1& t){
    int hour, minute, second;
    t.getHour(hour);
    t.getMinute(minute);
    t.getSecond(second);

    os << "Time:      ";
    if(hour < 0 || hour > 23){
        os << "Unknown-Hour" << ":";
    }else{
        os << hour << ":";
    }

    if(minute < 0 || minute > 59){
        os << "Unknown-Minute" << ".";
    }else{
        if(minute < 10){
            os << "0" << minute << ".";
        }else{
            os << minute << ".";
        }
    }

    if(second < 0 || second > 59){
        os << "Unknown-Second";
    }else{
        if(second < 10){
            os << "0" << second;
        }else{
            os << second;
        }
    }
    os << "\n";
    return os;
}
