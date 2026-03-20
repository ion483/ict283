#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdexcept>

float calculateMean(const float* arr, int size);
float calculateStdDev(const float* arr, int size, float mean);

int main(){
    std::ifstream ifs("floatData.txt");
    std::string inputStr;
    std::getline(ifs, inputStr);
    const char delimiter = ',';
    
    std::istringstream iss(inputStr);

    std::string countStr;
    int count;
    std::string floatCell;

    float* floatArray = nullptr;

    std::getline(iss, countStr, delimiter);
    try{
        count = std::stoi(countStr);
        if(count > 0) floatArray = new float[count];
        else count = 0;
    }catch(const std::exception& e){
        count = 0;
    }

    for(int i = 0; i < count; i++){
        std::getline(iss, floatCell, delimiter);
        try{
            float floatNumber = std::stof(floatCell);
            floatArray[i] = floatNumber;
        }catch(const std::exception& e){
            floatArray[i] = 0.0;
        }
    }

    float mean = calculateMean(floatArray, count);
    float stdDev = calculateStdDev(floatArray, count, mean);

    int decimalPlace = 2;
    float factor = std::pow(10, decimalPlace);

    float meanR = std::round(mean*factor)/factor;
    float stdDevR = std::round(stdDev*factor)/factor;

    std::cout << "The number of floating point values (N): " << count << '\n';
    std::cout << "The mean of the floating point values: " << meanR << '\n';
    std::cout << "The sample standard deviation (s): " << stdDevR << '\n';

    delete[] floatArray;

    return 0;
}

float calculateMean(const float* arr, int size){
    if(arr == nullptr || size <= 0) return NAN;

    float sum = 0.0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum/size;
}

float calculateStdDev(const float* arr, int size, float mean){
    if(arr == nullptr || size <= 1 || std::isnan(mean)) return NAN;

    float diffSquareSum = 0.0;
    for(int i = 0; i < size; i++){
        diffSquareSum += std::pow((arr[0]-mean), 2);
    }

    return std::sqrt(diffSquareSum/(size-1));
}