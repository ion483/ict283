#include "Menu2.h"

Menu2::Menu2(): dataMap(), calc(){
    Read2 r("Data_source.txt", dataMap);
    r.readCSV();
}

void Menu2::run() const{
    int choice = 0;
    do{
       displayMenu();
       std::cout << "Enter your choice: ";
       std::cin >> choice;

       if(std::cin.fail()){ /*handle invalid datatype*/
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choice = 0;
        std::cout << "Invalid data type for input\n";
        continue;
       }

       int year = -1, month = -1;
       switch(choice){
        case 1:
            std::cout << "Enter the year: ";
            std::cin >> year;
            std::cout << "Enter the month: ";
            std::cin >> month;
            option1(year, month);
            break;
        case 2:
            std::cout << "Enter the year: ";
            std::cin >> year;
            option2(year);
            break;
        case 3:
            std::cout << "Enter the month: ";
            std::cin >> month;
            option3(month);
            break;
        case 4:
            std::cout << "Enter the year: ";
            std::cin >> year;
            option4(year);
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default: /*handle out of range*/
            std::cout << "Out of range for input\n";
       }
    }while(choice != 5);
    std::cout << "Program ended." << std::endl;
}

void Menu2::displayMenu() const{
    std::cout << "\nMenu options:\n";
    std::cout << "1. Wind speed stats for a month and year\n";
    std::cout << "2. Monthly average air temp for a year\n";
    std::cout << "3. Sample Pearson Correlation Coefficient for a month\n";
    std::cout << "4. Summary report for a year (write to file)\n";
    std::cout << "5. Exit\n";
}

void Menu2::option1(int year, int month) const{
    if(month < 1 || month > 12){
        std::cout << month << " " << year << ": No Data\n";
        return;
    }
    Vector<double> speeds;
    const std::string* monthNames = getMonthNames();
    try{
        const Map<int, BST<WindRecType>>& monthMap = dataMap[year];
        try{
            const BST<WindRecType>& bst = monthMap[month];
            Collection<WindRecType> c;
            bst.inOrderTraversalCollect(c, &Collection<WindRecType>::collect);
            for(int i = 0; i < c.getSize(); i++){
                double speed;
                c[i].getSpeed(speed);
                if(!std::isnan(speed)) speeds.Insert(speed * 3.6, speeds.GetSize());
            }
            if(!speeds.IsEmpty()){
                double avg = calc.calculateMean(speeds);
                double stdev = calc.calculateSampleStdDev(speeds, avg);
                int decimalPlaces = 1;
                double factor = std::pow(10, decimalPlaces);
                double avgR = std::round(avg*factor)/factor;
                double stdevR = std::round(stdev*factor)/factor; 
                std::cout << monthNames[month-1] << " " << year << ":\n";
                std::cout << "Average speed: " << avgR << " km/h\n";
                std::cout << "Sample stdev: " << stdevR << '\n';
            }else{
                std::cout << monthNames[month-1] << " " << year << ": No Data\n";
            }
        }catch(const std::invalid_argument& e){
            std::cout << monthNames[month-1] << " " << year << ": No Data\n";
        }
    }catch(const std::invalid_argument& e){
        std::cout << monthNames[month-1] << " " << year << ": No Data\n";
    }
}

void Menu2::option2(int year) const{
    const std::string* monthNames = getMonthNames();
    std::cout << '\n' << year << '\n';
    try{
        const Map<int, BST<WindRecType>>& monthMap = dataMap[year];
        for(int i = 1; i < 13; i++){
            try{
                Vector<double> temps;
                const BST<WindRecType>& monthBST = monthMap[i];
                Collection<WindRecType> c;
                monthBST.inOrderTraversalCollect(c, &Collection<WindRecType>::collect);
                for(int j = 0; j < c.getSize(); j++){
                    double airT;
                    c[j].getAirT(airT);
                    if(!std::isnan(airT)) temps.Insert(airT, temps.GetSize());
                }
                if(temps.IsEmpty()){
                    std::cout << monthNames[i-1] << ": No Data\n";
                }else{
                    double avg = calc.calculateMean(temps);
                    double stdev = calc.calculateSampleStdDev(temps, avg);
                    int decimalPlaces = 1;
                    double factor = std::pow(10, decimalPlaces);
                    double avgR = std::round(avg*factor)/factor;
                    double stdevR = std::round(stdev*factor)/factor;
                    std::cout << monthNames[i-1] << ": average: " << avgR << " degrees C, stdev: " << stdevR << '\n'; 
                }
            }catch(const std::invalid_argument& e){
                std::cout << monthNames[i-1] << ": No Data\n";
            }
        }
    }catch(const std::invalid_argument& e){
        for(int j = 1; j < 13; j++){
            std::cout << monthNames[j-1] << ": No Data\n";
        }
    }
}

void Menu2::option3(int month) const{
    const std::string* monthNames = getMonthNames();
    if(month < 1 || month > 12){
        std::cout << "Sample Pearson Correlation Coefficient for " << month << '\n';
        std::cout << "S_T: " << "NAN" << '\n';
        std::cout << "S_R: " << "NAN" << '\n';
        std::cout << "T_R: " << "NAN" << '\n';
        return;
    }
    Vector<double> speeds;
    Vector<double> temps;
    Vector<double> srs;
    for(std::map<int, Map<int, BST<WindRecType>>>::const_iterator it = dataMap.begin(); it != dataMap.end(); ++it){
        const Map<int, BST<WindRecType>>& monthMap = it -> second;
        try{
            const BST<WindRecType>& monthBST = monthMap[month];
            Collection<WindRecType> c;
            monthBST.inOrderTraversalCollect(c, &Collection<WindRecType>::collect);
            for(int i = 0; i < c.getSize(); i++){
                double speed, airT, sr;
                c[i].getSpeed(speed);
                c[i].getAirT(airT);
                c[i].getSr(sr);
                if(!std::isnan(speed) && !std::isnan(airT) && !std::isnan(sr)){
                    speeds.Insert(speed*3.6, speeds.GetSize());
                    temps.Insert(airT, temps.GetSize());
                    srs.Insert(sr*600.0/3600000.0, srs.GetSize());
                }
            }
        }catch(const std::invalid_argument& e){
            continue;
        }
    }
    double S_T = calc.calculatesPCC(speeds, temps);
    double S_R = calc.calculatesPCC(speeds, srs);
    double T_R = calc.calculatesPCC(temps, srs);
    int decimalPlaces = 1;
    double factor = std::pow(10, decimalPlaces);
    double S_Tr = std::round(S_T*factor)/factor;
    double S_Rr = std::round(S_R*factor)/factor;
    double T_Rr = std::round(T_R*factor)/factor;
    std::cout << "Sample Pearson Correlation Coefficient for " << monthNames[month-1] << '\n';
    std::cout << "S_T: " << S_Tr << '\n';
    std::cout << "S_R: " << S_Rr << '\n';
    std::cout << "T_R: " << T_Rr << '\n';
}

void Menu2::option4(int year) const{
    std::ofstream ofs("WindTempSolar.csv");
    const std::string* monthNames = getMonthNames();
    std::cout << '\n' << year << '\n';
    ofs << year << '\n';
    try{
        const Map<int, BST<WindRecType>>& monthMap = dataMap[year];
        for(std::map<int, BST<WindRecType>>::const_iterator it = monthMap.begin(); it != monthMap.end(); ++it){
            const BST<WindRecType>& monthBST = it -> second;
            Vector<double> speeds, temps;
            double srSum = 0.0;
            
            Collection<WindRecType> c;
            monthBST.inOrderTraversalCollect(c, &Collection<WindRecType>::collect);
            for(int i = 0; i < c.getSize(); i++){
                double speed, airT, sr;
                c[i].getSpeed(speed);
                c[i].getAirT(airT);
                c[i].getSr(sr);

                if(!std::isnan(speed) && !std::isnan(airT) && !std::isnan(sr)){
                    speeds.Insert(speed*3.6, speeds.GetSize());
                    temps.Insert(airT, temps.GetSize());
                    srSum += sr*600.0/3600000.0;
                }
            }
            
            double avgSp = calc.calculateMean(speeds);
            double stdevSp = calc.calculateSampleStdDev(speeds, avgSp);
            double medianSp = calc.calculateMedian(speeds);
            double madSp = calc.calculateMAD(speeds, medianSp);

            double avgTp = calc.calculateMean(temps);
            double stdevTp = calc.calculateSampleStdDev(temps, avgTp);
            double medianTp = calc.calculateMedian(temps);
            double madTp = calc.calculateMAD(temps, medianTp);
            
            double decimalPlaces = 1;
            double factor = std::pow(10, decimalPlaces);
            
            double avgSpR = std::round(avgSp*factor)/factor;
            double stdevSpR = std::round(stdevSp*factor)/factor;
            double madSpR = std::round(madSp*factor)/factor;

            double avgTpR = std::round(avgTp*factor)/factor;
            double stdevTpR = std::round(stdevTp*factor)/factor;
            double madTpR = std::round(madTp*factor)/factor;

            double srSumR = std::round(srSum*factor)/factor;

            std::cout << monthNames[it->first - 1] << ',';
            ofs << monthNames[it->first - 1] << ',';

            /*if any data is NAN , dont display it, else display it*/
            if(!std::isnan(avgSpR)){
                std::cout << avgSpR << '(';
                ofs << avgSpR << '(';
                if(!std::isnan(stdevSpR)){
                    std::cout << stdevSpR << " ,";
                    ofs << stdevSpR << " ,";
                }else{
                    std::cout << " ,";
                    ofs << " ,";
                }
                if(!std::isnan(madSpR)){
                    std::cout << madSpR << "),";
                    ofs << madSpR << "),";
                }else{
                    std::cout << " ),";
                    ofs << " ),";
                }
            }else{
                std::cout << " ,";
                ofs << " ,";
            }

            if(!std::isnan(avgTpR)){
                std::cout << avgTpR << '(';
                ofs << avgTpR << '(';
                if(!std::isnan(stdevTpR)){
                    std::cout << stdevTpR << " ,";
                    ofs << stdevTpR << " ,";
                }else{
                    std::cout << " ,";
                    ofs << " ,";
                }
                if(!std::isnan(madTpR)){
                    std::cout << madTpR << "),";
                    ofs << madTpR << "),";
                }else{
                    std::cout << " ),";
                    ofs << " ),";
                }
            }else{
                std::cout << " ,";
                ofs << " ,";
            }

            if(srSumR != 0.0){
                std::cout << srSumR << '\n';
                ofs << srSumR << '\n';
            }else{
                std::cout << " \n";
                ofs << " \n";
            }
        }
    }catch(const std::invalid_argument& e){
        std::cout << "No Data\n";
        ofs << "No Data\n";
    }
}

const std::string* Menu2::getMonthNames() const{
    const static std::string monthNames[12] = {"January", "Fabruary", "March", "April", "May", "June", "July", "August", "September", "Octobor", "November", "December"};
    return monthNames;
}