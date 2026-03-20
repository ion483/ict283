#ifndef WINDRECTYPEIO_H
#define WINDRECTYPEIO_H

#include <iostream>
#include "WindRecType.h"
#include "DateIO.h"
#include "Time_1IO.h"

/**
 * @brief Friend function displays the WindRecType object in the output stream
 * @param os The output stream
 * @param w The WindRecType object to be output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const WindRecType& w);

#endif