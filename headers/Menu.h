#ifndef MENU_H
#define MENU_H

#include "Read.h"
#include "Vector.h"
#include "Date.h"
#include "Time_1.h"
#include "WindRecType.h"
#include "Calculation.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>

/**
 * @class Menu
 * @brief A user interface with options to choose
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */

class Menu{
    public:
        /**
         * @brief Constructs a Menu object.
         * @return void
         */
        Menu();

        /**
         * @brief Runs the menu interface, displaying options and handling user input.
         * @return void
         */
        void run() const;

    private:
        Vector<WindRecType> dataVector; /**< A container holding the data*/
        const Calculation calc; /**< An object used for mathematical calculation*/

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
         * @brief Handles option3: displays data for a specific year
         * @param year The year to filter data
         * @return void
         */
        void option3(int year) const;

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
