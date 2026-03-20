#ifndef TIME_1IO_H
#define TIME_1IO_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Time_1.h"

/**
 * @brief Friend function to output a Time_1 object to an output stream
 * @param os The output stream
 * @param t The Time_1 object do be output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Time_1& t);

#endif