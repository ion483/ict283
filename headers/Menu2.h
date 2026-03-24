#ifndef MENU2_H
#define MENU2_H

#include "Vector.h"
#include "Date.h"
#include "DateIO.h"
#include "Time_1.h"
#include "Time_1IO.h"
#include "WindRecType.h"
#include "WindRecTypeIO.h"
#include "BST.h"
#include "Map.h"
#include "Calculation.h"
#include "Collection.h"
#include "Read2.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <limits>

/**
 * @class Menu2
 * @brief A user interface with options to choose
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
class Menu2{
    private:

        /*Const reference to prevent large data copying*/
        Map<int, Map<int, BST<WindRecType>>> dataMap; /**< The dataMap with Key as int, value as a Map that has Key as int, value as a BST<WindRecType>*/
        const Calculation calc; /**< The Calculatiob object*/
    public:

        /**
         * @brief Constructs a Menu2 object that manages wind data and calculation utilities.
         * @return void
         */
        Menu2();
        
        /**
         * @brief Runs the menu interface, displaying options and handling user input.
         * @return void
         */
        void run() const;

    private:

        /**
         * @brief Displays the menu options to the user.
         * @return void
         */
        void displayMenu() const;

        /**
         * @brief Handles option 1: displays data for a specific month and year.
         * @param year The year to filter data
         * @param month The month to filter data
         * @return void
         */
        void option1(int year, int month) const;

        /**
         * @brief Handles option2: displays data for a specific year
         * @param year The year to filter data
         * @return void
         */
        void option2(int year) const;

        /**
         * @brief Handles option3: displays data for a specific month
         * @param month The year to filter data
         * @return void
         */
        void option3(int month) const;

        /**
         * @brief Handles option4: displays data for a specific year and write to an output file
         * @param year The year to filter data
         * @return void
         */
        void option4(int year) const;

        /**
         * @brief Retrieves a pointer to a string array representing months
         * @return A pointer to an array of months as strings
         */
        const std::string* getMonthNames() const;
};

#endif