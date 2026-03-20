#ifndef READ_H
#define READ_H

#include "Vector.h"
#include "WindRecType.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

/**
 * @class Read
 * @brief Read class reads the file data into a vector given a specified file path
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
class Read{
    public:

        /**
         * @brief Paremeterized constructor initializes Read class to input values
         * @param fileN The file name to read from in string
         * @param v The vector to be stored with data from the files
         * @return void
         */
        Read(const std::string& fileN, Vector<WindRecType>& v);

        /**
         * @brief Reads the files into the vector
         * @return void
         */
        void readCSV();
    private:
        std::string fileName; /**< The file name in std::string*/
        Vector<WindRecType>& dataVector; /**< The Reference to the input vector for storing data*/
};

#endif