#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Vector.h"
#include "Date.h"
#include "Time_1.h"
#include "WindRecType.h"

// Typedef as requested in the lab
typedef Vector<WindRecType> WindlogType;

/**
 * @brief Helper to parse the WAST string (DD/MM/YYYY HH:MM) 
 * and update a WindRecType object.
 */
void parseAndSetDateTime(std::string wast, WindRecType &record) {
    std::stringstream ss(wast);
    int day, month, year, hour, minute;
    char slash, colon;

    // Expected format: 31/03/2016 09:00
    if (ss >> day >> slash >> month >> slash >> year >> hour >> colon >> minute) {
        record.setDate(year, month, day);
        record.setTime(hour, minute, 0); // Seconds default to 0
    }
}

int main() {
    WindLogType wind_data;
    std::ifstream inFile("data/MetData-31-3.csv");

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open data/MetData-31-3.csv" << std::endl;
        return 1;
    }

    std::string line, header;
    std::getline(inFile, header); // Skip header row

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string wastField, speedField;

        // Column 1: WAST, Column 2: S (Speed)
        // Note: For assignment 1, you'll need logic to find these columns by name
        if (std::getline(ss, wastField, ',') && std::getline(ss, speedField, ',')) {
            
            if (speedField == "N/A" || speedField.empty()) continue;

            try {
                WindRecType record;
                parseAndSetDateTime(wastField, record);
                record.setSpeed(std::stod(speedField));
                
                // For now, airT and sr remain as initialized (NAN) 
                // unless you add logic to read those specific columns here.

                wind_data.push_back(record);
            } catch (...) {
                continue; // Skip lines with data conversion errors
            }
        }
    }
    inFile.close();

    if (wind_data.isEmpty()) {
        std::cout << "No valid data to process." << std::endl;
        return 0;
    }

    // --- Statistics Calculation ---
    double speedSum = 0;
    int n = wind_data.size();

    for (int i = 0; i < n; i++) {
        double tempSpeed;
        wind_data[i].getSpeed(tempSpeed);
        speedSum += tempSpeed;
    }

    double avgSpeedMS = speedSum / n;

    double sumSqDiff = 0;
    for (int i = 0; i < n; i++) {
        double tempSpeed;
        wind_data[i].getSpeed(tempSpeed);
        sumSqDiff += pow(tempSpeed - avgSpeedMS, 2);
    }
    double sdMS = sqrt(sumSqDiff / (n - 1));

    // --- Output Results ---
    // Conversion factor: 1 m/s = 3.6 km/h
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average wind speed: " << (avgSpeedMS * 3.6) << " km/h" << std::endl;
    std::cout << "Sample standard deviation: " << (sdMS * 3.6) << std::endl;

    std::cout << "\nObservations matching average speed (" << avgSpeedMS << " m/s):" << std::endl;

    // Use epsilon for floating point matching
    const double epsilon = 0.01;
    for (int i = 0; i < n; i++) {
        double currentSpeed;
        wind_data[i].getSpeed(currentSpeed);
        
        if (fabs(currentSpeed - avgSpeedMS) < epsilon) {
            // This will use your WindRecType overloaded << operator
            std::cout << wind_data[i];
        }
    }

    return 0;
}