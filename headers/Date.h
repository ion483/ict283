#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstring> //strncpy
#include <sstream>
#include <stdexcept>

/**
 * @class Date
 * @brief Represents a calendar date with year, month, day
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */

class Date{
    public:
        /**
         * @brief Default constructor initializes the date to default values.
         * @return void
         */
        Date();

        /**
         * @brief  Parameterized constructor initializes the date to input values.
         * @param year A year
         * @param monthInt The month (1-12)
         * @param day A day 
         * @return void
         */
        Date(int year, int monthInt, int day);

        /**
         * @brief Retrieves The year
         * @param year Reference to an int where the year will be stored
         * @return void
         */
        void getYear(int& year) const;

        /**
         * @brief Sets The year
         * @param newYear The new year value
         * @return void
         */
        void setYear(int newYear);

        /**
         * @brief Retrieves The month
         * @param month Reference to an int where the month will be stored
         * @return void
         */
        void getMonth(int& month) const;

        /**
         * @brief Sets The month
         * @param newMonth The new month value
         * @return void
         */
        void setMonth(int newMonth);

        /**
         * @brief Retrieves The day
         * @param day Reference to an int where the day will be stored
         * @return void
         */
        void getDay(int& day) const;

        /**
         * @brief Sets The day
         * @param newDay The new day value
         * @return void
         */
        void setDay(int newDay);

        /**
         * @brief Validating the date to make sure year, month, day are within constraints
         * @param year The year
         * @param month The month
         * @param day The dat
         * @return true if all three values pass the constraint check, false otherwise 
         */
        bool checkDate(int year, int month, int day) const;

        /**
         * @brief Retreiving the info about the validity of Date
         * @return True if the Date is valid, false otherwise
         */
        bool isValid() const;

        /**
         * @brief Checks if two dates are equal
         * @param other The other date objects to compare
         * @return True if two dates are the same, false otherwise
         */
        bool operator==(const Date& other) const;

        /**
         * @brief Checks if two dates are not equal
         * @param other The other date objects to compare
         * @return True if two dates are not the same, false otherwise
         */
        bool operator!=(const Date& other) const;

        /**
         * @brief Checks if this date is greater than the other
         * @param other The other date objects to compare
         * @return True if this date is later than the other, false otherwise
         */
        bool operator>(const Date& other) const;

        /**
         * @brief Checks if this date is less than the other
         * @param other The other date objects to compare
         * @return True if this date is earlier than the other, false otherwise
         */
        bool operator<(const Date& other) const;

    private:
        int m_year; /**< The year component*/
        int m_month; /**< The month component*/
        int m_day; /**< The day component */

        bool m_isValid; /**< The isValid boolean flag */
};

#endif