#include <iostream>
#include <sstream>
#include <fstream>

#include "CMenu.h"

int main(){
    std::vector<Person> data;
    std::ifstream ifs("person.txt");
    int nameIdx, amountIdx, currIdx;
    std::string header;
    std::getline(ifs, header);
    const char delimiter = ',';

    std::istringstream ihss(header);

    std::string headerCell;
    std::vector<std::string> headerV;

    while(std::getline(ihss, headerCell, delimiter)){
        headerV.push_back(headerCell);
    }

    for(int i = 0; i < headerV.size(); i++){
        if(headerV[i] == "name"){
            nameIdx = i;
        }else if(headerV[i] == "amount"){
            amountIdx = i;
        }else if(headerV[i] == "currency"){
            currIdx = i;
        }
    }

    std::string entry;
    int count = 0;

    while(std::getline(ifs,entry)){
        std::istringstream iss(entry);
        std::string token;
        std::vector<std::string> tokens;
        while(std::getline(iss, token, delimiter)){
            tokens.push_back(token);
        }
        std::string namestr, amountstr, currstr;
        namestr = tokens[nameIdx];
        amountstr = tokens[amountIdx];
        currstr = tokens[currIdx];

        int amount;
        try{
            amount = std::stoi(amountstr);
        }catch(...){
            std::cout << "Failed to convert string to int" << std::endl;
        }
        
        auto it = currMap.find(currstr);
        if(it != currMap.end()){
            Currency curr = it -> second;

            auto pit = std::find_if(data.begin(), data.end(), [&namestr](const Person& p){
                std::string lowerName1 = namestr;
                std::string lowerName2 = p.getName();
                std::transform(lowerName1.begin(), lowerName1.end(), lowerName1.begin(), [&](char& c){
                    return std::tolower(c);
                });
                std::transform(lowerName2.begin(), lowerName2.end(), lowerName2.begin(), [&](char& c){
                    return std::tolower(c);
                });
                return lowerName1 == lowerName2;
            });

            if(pit != data.end()){
                pit -> addAmount(curr, amount);
            }else{
                Person newPerson = Person(namestr);
                newPerson.addAmount(curr, amount);
                data.push_back(newPerson);
                count++;
            }
        }else{
            std::cout << "no found currency" << std::endl;
        }
    }

    std::cout << "total entries: " << count << '\n';

    /*for(const Person& p : data){
        std::cout << p;
        std::cout << '\n';
    }*/

    CMenu menu(data);
    menu.run();

    return 0;
}