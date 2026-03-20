#ifndef TIME_1_H
#define TIME_1_H

#include <iostream>
#include <cstring>
#include <regex>
#include <sstream>

/**
 * @class Time_1
 * @brief Represents a specific time with hour, minute, second
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */

class Time_1{
    public:

        /**
         * @brief Default constructor initializes Time_1 to default values
         * @return void
         */
        Time_1();

        /**
         * @brief Paremeterized constructor intialized Time_1 to input values
         * @param hour The hour value
         * @param minute The minute value
         * @param second The second value
         * @return void
         */
        Time_1(int hour, int minute, int second);

        /**
         * @brief Retrives the hour
         * @param hour Reference to an int where the hour wil be stored
         * @return void
         */
        void getHour(int& hour) const;

        /**
         * @brief Sets the hour
         * @param newHour The new hour value
         * @return void
         */
        void setHour(int newHour);

        /**
         * @brief Retrives the minute
         * @param minute Reference to an int where the minute wil be stored
         * @return void
         */
        void getMinute(int& minute) const;

        /**
         * @brief Sets the minute
         * @param newMinute The new minute value
         * @return void
         */
        void setMinute(int newMinute);

        /**
         * @brief Retrives the second
         * @param second Reference to an int where the second wil be stored
         * @return void
         */
        void getSecond(int& second) const;

        /**
         * @brief Sets the second
         * @param newSecond The new second value
         * @return void
         */
        void setSecond(int newSecond);

        /**
         * @brief Validating the time to make sure hour, minute, second are within constraints
         * @param hour The year
         * @param minute The month
         * @param second The dat
         * @return true if all three values pass the constraint check, false otherwise 
         */
        bool checkTime(int hour, int minute, int second) const;

        /**
         * @brief Retreiving the info about the validity of Time_1
         * @return True if the Time_1 is valid, false otherwise
         */
        bool isValid() const;

        /**
         * @brief Checks if two times are equal
         * @param other The other Time_1 objects to compare
         * @return True if two times are the same, false otherwise
         */
        bool operator==(const Time_1& other) const;

        /**
         * @brief Checks if this time is greater than the other
         * @param other The other Time_1 objects to compare
         * @return True if this time is later than the other
         */
        bool operator>(const Time_1& other) const;

        /**
         * @brief Checks if this time is less than the other
         * @param other The other Time_1 objects to compare
         * @return True if this time is earlier than the other
         */
        bool operator<(const Time_1& other) const;

    private:
        int m_hour; /**< The hour component */
        int m_minute; /**< The minute component */
        int m_second; /**< The second component */

        bool m_isValid; /**< The isValid bool flag */
};

#endif