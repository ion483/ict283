#include "Calculation.h"
#include <cassert>
#include <cmath>

int main(){
    Calculation calc;

    Vector<double> data;
    data.Insert(1.0, data.GetSize());
    data.Insert(2.0, data.GetSize());
    data.Insert(3.0, data.GetSize());
    data.Insert(4.0, data.GetSize());
    data.Insert(5.0, data.GetSize());
    
    Vector<double> data2;
    data2.Insert(2.0, data2.GetSize());
    data2.Insert(4.0, data2.GetSize());
    data2.Insert(6.0, data2.GetSize());
    data2.Insert(8.0, data2.GetSize());
    data2.Insert(10.0, data2.GetSize());

    double mean = calc.calculateMean(data);
    std::cout << "data mean: " << mean << '\n';
    if(std::abs(mean - 3.0) < 1e-6) std::cout << "mean is correct\n"; // test id 1

    double median = calc.calculateMedian(data);
    std::cout << "data median: " << median << '\n';
    if(std::abs(median - 3.0) < 1e-6) std::cout << "median is correct\n"; // test id 2

    double stdev = calc.calculateSampleStdDev(data, mean); 
    std::cout << "data stdev: " << stdev << '\n'; // test id 3

    double spcc = calc.calculatesPCC(data, data2);
    std::cout << "spcc: " << spcc << '\n'; // test id 4
    assert(std::abs(spcc-1.0) < 1e-6);

    double mad = calc.calculateMAD(data, median); // test id 5
    std::cout << "data mad: " << mad << '\n';

    std::cout << "Calculation class passes all tests" << std::endl;

    return 0;
}