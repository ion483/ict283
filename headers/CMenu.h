#ifndef CMENU_H
#define CMENU_H

#include "Person.h"

class CMenu{
    public:
        CMenu(const std::vector<Person>& data);
        void run();
    private:
        const std::vector<Person>& persons;
        void function1(std::string name);
        void function2();
        void printCurrency(const Currency& curr, const int& amount);
        std::string ctos(const Currency& curr);
};

#endif