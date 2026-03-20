#ifndef WINDRECTYPE_H
#define WINDRECTYPE_H

#include "Date.h"
#include "Time_1.h"
#include <iostream>
#include <cmath>


/**
 * @class WindRecType
 * @brief A container unit stores Date, Time_1, wind speed, air temparature, solar radiation
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
class WindRecType{
    private:
        Date d; /**< Date objct*/
        Time_1 t; /**< Time_1 object*/
        double speed; /**< Wind speed*/
        double airT; /**< Air temparature*/
        double sr; /**< Solar radiation*/
    public:

        /**
         * @brief Default constructor
         * @return void
         */
        WindRecType();

        /**
         * @brief Retrieves the Date object
         * @param date The reference to the input Date object
         * @return void
         */
        void getDate(Date& date) const;

        /**
         * @brief Sets the Date object with input year, month, and day
         * @param year The new year
         * @param month The new month
         * @param day The new day
         * @return void
         */
        void setDate(const int& year, const int& month, const int& day);

        /**
         * @brief Retrieves the Time_1 object
         * @param time The reference to the input Time_1 object
         * @return void
         */
        void getTime(Time_1& time) const;

        /**
         * @brief Sets the Time_1 object with input hour, minute, and second
         * @param hour The new hour
         * @param minute The new minute
         * @param second The new second
         * @return void
         */
        void setTime(const int& hour, const int& minute, const int& second);

        /**
         * @brief Retrieves the speed
         * @param nSpeed The reference to the input speed
         * @return void
         */
        void getSpeed(double& nSpeed) const;

        /**
         * @brief Sets the speed to new speed
         * @param nSpeed The new speed
         * @return void
         */
        void setSpeed(const double& nSpeed);

        /**
         * @brief Retrieves the airT
         * @param nAirT The reference to the input airT
         * @return void
         */
        void getAirT(double& nAirT) const;

        /**
         * @brief Sets the airT to new airT
         * @param nAirT The new airT
         * @return void
         */
        void setAirT(const double& nAirT);

        /**
         * @brief Retrieves the sr
         * @param nSr The reference to the input sr
         * @return void
         */
        void getSr(double& nSr) const;

        /**
         * @brief Sets the sr to new sr
         * @param nSr The new sr
         * @return void
         */
        void setSr(const double& nSr);

        /**
         * @brief Checks if the other WindRecType is equal to this WindRecType
         * @param other The other WindRecType object
         * @return True if the this object is same as the other object, false otherwise
         */
        bool operator==(const WindRecType& other) const;

        /**
         * @brief Checks if the other WindRecType is less than this WindRecType
         * @param other The other WindRecType object
         * @return True if the this object is later than the other object, false otherwise
         */
        bool operator>(const WindRecType& other) const;

        /**
         * @brief Checks if the other WindRecType is greater than this WindRecType
         * @param other The other WindRecType object
         * @return True if the this object is earlier than the other object, false otherwise
         */
        bool operator<(const WindRecType& other) const;

};

#endif