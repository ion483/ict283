#include "WindRecTypeIO.h"

// WindRecType output operator
std::ostream& operator<<(std::ostream& os, const WindRecType& w){
    os << "{" << '\n';
    Date d;
    Time_1 t;
    double speed;
    double airT;
    double sr;
    w.getDate(d);
    w.getTime(t);
    w.getSpeed(speed);
    w.getAirT(airT);
    w.getSr(sr);
    os << " " << d;
    os << " " << t;

    if(!std::isnan(speed)){
        os << " " << "Speed: " << speed << " m/s";
    }else{
        os << " " << "Speed: " << speed;
    }
    if(!std::isnan(airT)){
        os << ", Air Temparature: " << airT << " degrees C";
    }else{
        os << ", Air Temparature: " << airT;
    }
    if(!std::isnan(sr)){
        os << ", Solar Radiation: " << sr  << " W/m^2" << '\n';
    }else{
        os << ", Solar Radiation: " << sr << '\n';
    }
      
    os << "}";
    os << '\n';
    return os;
}