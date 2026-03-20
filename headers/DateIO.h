#ifndef DATEIO_H
#define DATEIO_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Date.h"
#include "Utility.h"

/**
 * @brief Function input the data into a Date object from an input stream
 * @param is The input stream
 * @param d The Date object to be input
 * @return Reference to the input stream
 */
std::istream& operator>>(std::istream& is, Date& d);

/**
 * @brief Function to output a Date object to an output stream
 * @param os The output stream
 * @param d The Date object do be output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif