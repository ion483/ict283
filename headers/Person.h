#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

enum Currency {
    AU$,
    US$,
    EUR
};

struct CustomComparison {
    bool operator()(const std::string& a, const std::string& b) const;
};

struct CurrencyComparison {
    bool operator()(const Currency& a, const Currency& b) const;
};

extern std::map<std::string, Currency> currMap;
extern std::map<std::string, int, CustomComparison> AUMap;
extern std::map<std::string, int, CustomComparison> USMap;
extern std::map<std::string, int, CustomComparison> EURMap;

struct CoinCounts {
    int c50;
    int c25;
    int c20;
    int c10;
    int c5;
    int c1;
};

extern CoinCounts coinCounts;

class Person{
    private:
        std::string name;
        std::map<Currency, int, CurrencyComparison> amountMap;
    public:
        Person(const std::string& name);
        void addAmount(const Currency& curr, const int& amount);
        std::string getName() const;
        std::map<Currency, int, CurrencyComparison> getMap() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif
