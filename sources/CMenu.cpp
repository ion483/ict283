#include "CMenu.h"

CMenu::CMenu(const std::vector<Person>& data) : persons(data){}

void CMenu::run(){
            int choice;
            do{
                std::cout << "1. Find person\n";
                std::cout << "2. Print data\n";
                std::cout << "3. Exit\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice; 
                std::string name;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                switch(choice){
                    case 1 :
                        std::cout << "Enter the name: ";
                        std::cin >> name;
                        function1(name);
                        break;
                    case 2 :
                        name = "";
                        function2();
                        break;
                    case 3 :
                        name = "";
                        std::cout << "Exiting..." << std::endl;
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                }
            }while(choice != 3);
            std::cout << "Program ended." << std::endl;
}

void CMenu::function1(std::string name){
            bool isFound = false;
            auto pit = std::find_if(persons.begin(), persons.end(), [&name, &isFound](const Person& p){
                std::string lowerName1 = name;
                std::string lowerName2 = p.getName();
                std::transform(lowerName1.begin(), lowerName1.end(), lowerName1.begin(), [&](char& c){
                    return std::tolower(c);
                });
                std::transform(lowerName2.begin(), lowerName2.end(), lowerName2.begin(), [&](char& c){
                    return std::tolower(c);
                });
                if(lowerName1 == lowerName2){
                    isFound = true;
                    return true;
                }else{
                    return false;
                }
            });
            if(!isFound){
                std::cout << "Person doesnt exists\n";
                return;
            }
            if(pit != persons.end()){
                std::string pname = pit -> getName();
                std::map<Currency, int, CurrencyComparison> aMap = pit -> getMap();
                std::cout << '\n' << pname;
                for(auto it = aMap.begin(); it != aMap.end(); ++it){
                    std::cout << '\n';
                    Currency curr = it -> first;
                    int amount = it -> second;
                    std::cout << ctos(curr) << ": " << amount << " cents\n";
                    printCurrency(curr, amount);
                }
                std::cout << '\n';
            }
}

void CMenu::function2(){
            std::string source = "outputPerson.txt";
            std::ofstream ofs(source);

            for(auto it = persons.begin(); it != persons.end(); ++it){
                std::string name = it -> getName();
                auto amountMap = it -> getMap();
                ofs << name << ",";
                for(auto i = amountMap.begin(); i != amountMap.end(); ++i){
                    bool isLast = (std::next(i) == amountMap.end());
                    Currency curr = i -> first;
                    int amount = i -> second;
                    ofs << ctos(curr) << ",";
                    if(!isLast){
                        ofs << amount << ",";
                    }else{
                        ofs << amount << '\n';
                    }
                }
            }
            std::cout << "Output to the output file." << std::endl;
}

void CMenu::printCurrency(const Currency& curr, const int& amount){
            int remainingAmount = amount;
            std::map<std::string, int, CustomComparison> currMap;
            switch(curr){
                case AU$ :
                   currMap = AUMap;
                   break;
                case US$ :
                    currMap = USMap;
                    break;
                case EUR :
                    currMap = EURMap;
                    break; 
                default :
                    return;
            }

            coinCounts = {0, 0, 0, 0, 0, 0};

            std::map<std::string, int*, CustomComparison> coinMap = {
                {"50", &coinCounts.c50},
                {"25", &coinCounts.c25},
                {"20", &coinCounts.c20},
                {"10", &coinCounts.c10},
                {"5", &coinCounts.c5},
                {"1", &coinCounts.c1}
            };

            for(auto it = currMap.begin(); it != currMap.end(); ++it){
                std::string coinCountstr = it -> first;
                int coinCount = std::stoi(coinCountstr);
                if((coinMap.find(coinCountstr)) != coinMap.end()){
                    int numOfCoins = remainingAmount / coinCount;
                    remainingAmount %= coinCount;
                    int* ptr = coinMap[coinCountstr];
                    *ptr += numOfCoins;
                }
            }
            
            if(coinCounts.c50 != 0){
                std::cout << "50 cents counts: " << coinCounts.c50 << '\n';
            }
            if(coinCounts.c25 != 0){
                std::cout << "25 cents counts: " << coinCounts.c25 << '\n';
            }
            if(coinCounts.c20 != 0){
                std::cout << "20 cents counts: " << coinCounts.c20 << '\n';
            }
            if(coinCounts.c10 != 0){
                std::cout << "10 cents counts: " << coinCounts.c10 << '\n';
            }
            if(coinCounts.c5 != 0){
                std::cout << "5 cents counts: " << coinCounts.c5 << '\n';
            }
            if(coinCounts.c1 != 0){
                std::cout << "1 cent counts: " << coinCounts.c1 << '\n';
            }

            if(remainingAmount != 0){
                std::cout << "Remaining: " << remainingAmount << " cents\n";
            }
}

std::string CMenu::ctos(const Currency& curr){
    bool isFound = false;
    for(auto it = currMap.begin(); it != currMap.end(); ++it){
        if(it -> second == curr){
            return it -> first;
            isFound = true;
        }
    }
    if(!isFound){
        return "";
    }
}