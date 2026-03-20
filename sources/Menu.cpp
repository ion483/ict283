#include "Menu.h"

Menu::Menu(): dataVector(), calc(){
    Read r("Data_source.txt", dataVector);
    r.readCSV();
}

void Menu::run() const{
    int choice = 0;
    do{
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0;
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
                std::cout << "Enter the year: ";
                std::cin >> year;
                option3(year);
                break;
            case 4:
                std::cout << "Enter the year: ";
                std::cin >> year;
                option4(year);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, enter again\n";
        }
    }while(choice != 5);
    std::cout << "Program ended." << std::endl;
}

void Menu::displayMenu() const{
    std::cout << "\nMenu options:\n";
    std::cout << "1. Wind speed stats for a month and year\n";
    std::cout << "2. Monthly average air temp for a year\n";
    std::cout << "3. Total solar radiation for each month of a year\n";
    std::cout << "4. Summary report for a year (write to file)\n";
    std::cout << "5. Exit\n";
}

void Menu::option1(int year, int month) const{
    Vector<double> speeds;
    
    int entryYear;
    int entryMonth;
    for(int i = 0; i < dataVector.GetSize(); i++){
        WindRecType w = dataVector[i];
        Date d;
        Time_1 t;
        w.getDate(d);
        w.getTime(t);
        d.getYear(entryYear);
        d.getMonth(entryMonth);

        double speed;
        w.getSpeed(speed);
        if(entryYear == year && entryMonth == month && !std::isnan(speed)){
            speeds.Insert(speed*3.6, speeds.GetSize());
        }
    }
    if(speeds.IsEmpty()){
        std::cout << getMonthNames()[month-1] << " " << year << ": " << "No Data\n";
    }else{
        int decimalPlaces = 1;
        double factor = std::pow(10, decimalPlaces);
        double avg = calc.calculateMean(speeds);
        double stdev = calc.calculateSampleStdDev(speeds, avg);
        double avgR = std::round(avg*factor) / factor;
        double stdevR = std::round(stdev*factor) / factor;
        std::cout << getMonthNames()[month-1] << " " << year << ": " << '\n';
        std::cout << "Average speed: " << avgR << " km/h\n";
        std::cout << "Sample stdev: " << stdevR << '\n';
    }
}

void Menu::option2(int year) const{
    const std::string* monthNames = getMonthNames();
    std::cout << '\n' << year << '\n';
    for(int i = 1; i < 13; i++){
        Vector<double> temps;
        for(int j = 0; j < dataVector.GetSize(); j++){
            int entryYear;
            int entryMonth;
            WindRecType w = dataVector[j];
            Date d;
            Time_1 t;
            w.getDate(d);
            w.getTime(t);
            d.getYear(entryYear);
            d.getMonth(entryMonth);

            double airT;
            w.getAirT(airT);
            if(entryYear == year && entryMonth == i && !std::isnan(airT)){
                temps.Insert(airT, temps.GetSize());
            }
        }
        if(temps.IsEmpty()) std::cout << monthNames[i-1] << ": No Data\n";
        else{
            int decimalPlaces = 1;
            double factor = std::pow(10, decimalPlaces);
            double avg = calc.calculateMean(temps);
            double avgR = std::round(avg*factor)/factor;
            double stdev = calc.calculateSampleStdDev(temps, avg);
            double stdevR = std::round(stdev*factor)/factor;
            std::cout << monthNames[i-1] << ": Average: " << avgR << " degrees C, stdev: " << stdevR << '\n';
        }
    }
}

void Menu::option3(int year) const{
    const std::string* monthNames = getMonthNames();
    std::cout << '\n' << year << '\n';
    for(int i = 1; i < 13; i++){
        double srSum = 0.0;
        bool hasData = false;
        for(int j = 0; j < dataVector.GetSize(); j++){
            int entryYear;
            int entryMonth;
            WindRecType w = dataVector[j];
            Date d;
            Time_1 t;
            w.getDate(d);
            w.getTime(t);
            d.getYear(entryYear);
            d.getMonth(entryMonth);
            
            double sr;
            w.getSr(sr);
            if(entryYear == year && entryMonth == i && !std::isnan(sr)){
                srSum += sr * 600.0/3600000.0;
                hasData = true;
            }
        }
        if(!hasData){
            std::cout << monthNames[i-1] << ": No Data\n";
        }else{
            int decimalPlaces = 1;
            double factor = std::pow(10, decimalPlaces);
            double srSumR = std::round(srSum*factor)/factor;
            std::cout << monthNames[i-1] << ": " << srSumR << " kWh/m^2\n";
        }
    }
}

void Menu::option4(int year) const{
    const std::string* monthNames = getMonthNames();
    std::cout << '\n' << year << '\n';
    std::ofstream ofs("WindTempSolar.csv");
    ofs << year << '\n';

    Vector<Vector<WindRecType>> monthlyData(13, Vector<WindRecType>());
    bool isYearEmpty = true;
    
    for(int j = 0; j < dataVector.GetSize(); j++){
        WindRecType w = dataVector[j];
        int entryYear;
        int entryMonth;
        Date d;
        w.getDate(d);
        d.getYear(entryYear);
        d.getMonth(entryMonth);

        double speed, airT, sr;
        w.getSpeed(speed);
        w.getAirT(airT);
        w.getSr(sr);
        if(entryYear == year && !std::isnan(speed) && !std::isnan(airT) && !std::isnan(sr)){
            monthlyData[entryMonth].Insert(w, monthlyData[entryMonth].GetSize());
            isYearEmpty = false;
        }
    }

    if(isYearEmpty){
        std::cout << "No Data\n";
        ofs << "No Data\n";
        return;
    }

    for(int i = 1; i < 13; i++){
        Vector<WindRecType>& vw = monthlyData[i];
        if(!vw.IsEmpty()){
            Vector<double> speeds, temps;
            double srSum = 0.0;
            for(int j = 0; j < vw.GetSize(); j++){
                WindRecType w = vw[j];
                double speed, airT, sr;
                w.getSpeed(speed);
                w.getAirT(airT);
                w.getSr(sr);

                if(!std::isnan(speed)) speeds.Insert(speed * 3.6, speeds.GetSize());
                if(!std::isnan(airT)) temps.Insert(airT, temps.GetSize());
                if(!std::isnan(sr)) srSum += sr * 600.0/3600000.0;
            }
            int decimalPlaces = 1;
            double factor = std::pow(10, decimalPlaces);

            double avgSp = calc.calculateMean(speeds);
            double avgSpR = std::round(avgSp*factor)/factor;
            double stdevSp = calc.calculateSampleStdDev(speeds, avgSp);
            double stdevSpR = std::round(stdevSp*factor)/factor;

            double avgT = calc.calculateMean(temps);
            double avgTR = std::round(avgT*factor)/factor;
            double stdevT = calc.calculateSampleStdDev(temps, avgT);
            double stdevTR = std::round(stdevT*factor)/factor;

            double srSumR = std::round(srSum*factor)/factor;
            
            std::cout << monthNames[i-1] << ",";
            ofs << monthNames[i-1] << ",";
            if(!std::isnan(avgSpR)){
                std::cout << avgSpR << "(";
                ofs << avgSpR << "(";
            }else{
                std::cout << " ,";
                ofs << " ,";
            }
            if(!std::isnan(stdevSpR)){
                std::cout << stdevSpR << "),";
                ofs << stdevSpR << "),";
            }else{
                std::cout << " ),";
                ofs << " ),";
            }
            if(!std::isnan(avgTR)){
                std::cout << avgTR << "(";
                ofs << avgTR << "(";
            }else{
                std::cout << " ,";
                ofs << " ,";
            }
            if(!std::isnan(stdevTR)){
                std::cout << stdevTR << "),";
                ofs << stdevTR << "),";
            }else{
                std::cout << " ,";
                ofs << " ,";
            }
            if(!std::isnan(srSumR)){
                std::cout << srSumR << '\n';
                ofs << srSumR << '\n';
            }else{
                std::cout << " \n";
                ofs << " \n";
            }
        }
    }
    
    std::cout << "Data written to output file\n";
}

const std::string* Menu::getMonthNames() const{
    const static std::string months[12] = {"January", "Fabruary", "March", "April", "May", "June", "July", "August", "September", "Octobor", "November", "December"};
    return months;
}
