#ifndef CALCULATION_H
#define CALCULATION_H

#include "Vector.h"
#include "Utility.h"
#include <iostream>
#include <cmath>

/**
 * @class Calculation 
 * @brief An object for doing calculations on data
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
class Calculation{
    public:

        /**
         * @brief Calculates the mean of a vector of double values
         * @param values A vector of data points
         * @return The mean of the vector data points as a double
         */
        double calculateMean(const Vector<double>& values) const;

        /**
         * @brief Calculates the median of a vector of double values
         * @param values A vector of data points
         * @return The median of the data points as a double
         */
        double calculateMedian(const Vector<double>& values) const;

        /**
         * @brief Calculates the sample standard deviation of a vector of double values
         * @param values A vector of data points
         * @param mean The average of the vector data points
         * @return The sample standard deviation of the data points as a double
         */
        double calculateSampleStdDev(const Vector<double>& values, const double& mean) const;

        /**
         * @brief Calculates the Pearson correlation coefficient between two vectors of data points
         * @param x The first vector
         * @param y The second vector
         * @return The Pearson correlation coefficient as a double
         */
        double calculatesPCC(const Vector<double>& x, const Vector<double>& y) const;

        /**
         * @brief Calculates the Median Absolute Deviation of a vector of double values
         * @param v A vector of data points
         * @param median The median of the data points
         * @return The Median Absolute Deviation of the data points as a double
         */
        double calculateMAD(const Vector<double>& v, const double& median) const;
    private:
};

#endif