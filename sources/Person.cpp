#include "Person.h"

std::map<std::string, Currency> currMap{
    {"AU$", AU$},
    {"US$", US$},
    {"EUR", EUR}
};


bool CustomComparison::operator()(const std::string& a, const std::string& b) const{
        return std::stoi(a) > std::stoi(b);
};  

bool CurrencyComparison::operator()(const Currency& a, const Currency& b) const{
        static const std::map<Currency, int> order = {
            {AU$, 0},
            {US$, 1},
            {EUR, 2}
        };
        return order.at(a) < order.at(b);
};


std::map<std::string, int, CustomComparison> AUMap{
    {"50", 0},
    {"20", 0},
    {"10", 0},
    {"5", 0}
};

std::map<std::string, int, CustomComparison> USMap{
    {"50", 0},
    {"25", 0},
    {"10", 0},
    {"1", 0}
};

std::map<std::string, int, CustomComparison> EURMap{
    {"20", 0},
    {"10", 0},
    {"5", 0},
    {"1", 0}
};

CoinCounts coinCounts = {0, 0, 0, 0, 0, 0};

Person::Person(const std::string& name): name(name){}

void Person::addAmount(const Currency& curr, const int& amount){
    amountMap[curr] += amount;
}

std::string Person::getName() const{
    return name;
}

std::map<Currency, int, CurrencyComparison> Person::getMap() const{
    return amountMap;
}
        
std::ostream& operator<<(std::ostream& os, const Person& p){
            os << "person: " << p.getName() << '\n';
            os << "Amount: " << '\n';
            std::map<Currency, int, CurrencyComparison> aMap = p.getMap();
            for(auto it = aMap.begin(); it != aMap.end(); ++it){
               Currency curr = it -> first;
               std::string currstr;
               for(auto it = currMap.begin(); it != currMap.end(); ++it){
                    if(it -> second == curr){
                        currstr = it -> first;
                    }
                }
               os << currstr << ": " << it -> second << " cents\n";
            }
            return os;
}