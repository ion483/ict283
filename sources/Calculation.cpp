#include "Calculation.h"

double Calculation::calculateMean(const Vector<double>& values) const{
    if(values.GetSize() <= 0){
        return NAN;
    }
    double sum = 0.0;
    for(int i = 0; i < values.GetSize(); i++){
        sum += values[i];
    }
    double mean = sum / values.GetSize();
    return mean;
}

double Calculation::calculateMedian(const Vector<double>& values) const{
    if(values.GetSize() <= 0){
        return NAN;
    }
    double size = static_cast<double>(values.GetSize());
    bool isEven = false;
    if((size / 2) == std::floor((size / 2))){
        isEven = true;
    }else{
        isEven = false;
    }

    Utility u;
    Vector<double> sortedValues = u.getSortedData(values);

    if(isEven){
        size_t middleRightIndex = static_cast<size_t>((size/2));
        size_t middleLeftIndex = middleRightIndex - 1;
        double median = (sortedValues[middleLeftIndex] + sortedValues[middleRightIndex]) / 2;
        return median;
    }else{
        size_t middleIndex = static_cast<size_t>(std::floor((size/2)));
        double median = sortedValues[middleIndex];
        return median;
    }
}

double Calculation::calculateSampleStdDev(const Vector<double>& values, const double& mean) const{
    if(values.GetSize() <= 1 || std::isnan(mean)) return NAN;
    double diffSquareSum = 0.0;
    for(int i = 0; i < values.GetSize(); i++){
        double diff = values[i] - mean;
        diffSquareSum += diff * diff;
    }
    return std::sqrt(diffSquareSum / (values.GetSize() - 1));
}

double Calculation::calculatesPCC(const Vector<double>& x, const Vector<double>& y) const{ /*Requring two data to have same number of segements, and at least form a line, meaning in one data, at least two diffrent unique values*/
    int n = x.GetSize(); /*measure the similarity of trends for two lines, 0 means two lines have no linear relationship, like parallel and horozontal, or two volitile lines*/
    if(y.GetSize() != n || n < 2){
        return NAN;
    }
    double sumX = 0.0;
    double sumY = 0.0;
    for(int i = 0; i < n; i++){
        sumX += x[i];
        sumY += y[i];
    }
    double meanX = sumX / n;
    double meanY = sumY / n;
    
    double sumDiffX = 0.0;
    double sumDiffY = 0.0;
    double sumDiffXY = 0.0;
    for(int i = 0; i < n; i++){
        double diffX = x[i] - meanX;
        double diffY = y[i] - meanY;
        sumDiffX += diffX * diffX;
        sumDiffY += diffY * diffY;
        sumDiffXY += diffX * diffY; /*order of data matters because diffX * diffY cosiders pairing*/
    }
    if(sumDiffX == 0 || sumDiffY == 0){
        return NAN;
    }
    return sumDiffXY / std::sqrt(sumDiffX * sumDiffY);
}

double Calculation::calculateMAD(const Vector<double>& v, const double& median) const{
    if(v.GetSize() == 0 || std::isnan(median)){
        return NAN;
    }
    double diffSum = 0.0;
    for(int i = 0; i < v.GetSize(); i++){
        diffSum += std::abs(v[i]-median);
    }
    return diffSum / v.GetSize();
}



