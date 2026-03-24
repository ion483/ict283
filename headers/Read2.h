#ifndef READ2_H
#define READ2_H

#include "Vector.h"
#include "BST.h"
#include "Map.h"
#include "WindRecType.h"
#include "Date.h"
#include "Time_1.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

/**
 * @class Read2
 * @brief Read2 class reads the file data into a vector given a specified file path
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
class Read2{
    private:
        const std::string fileName; /**< The file name in string*/
        Map<int, Map<int, BST<WindRecType>>>& dataMap; /**< The reference to the input map*/
    public:

        /**
         * @brief Paremeterized constructor initializes Read2 class to input values
         * @param fName The file name to read from in string
         * @param dMap The map to be stored with data from the files
         * @return void
         */
        Read2(const std::string& fName, Map<int, Map<int, BST<WindRecType>>>& dMap);

        /**
         * @brief Reads the files into the map
         * @return void
         */
        void readCSV();
};

#endif