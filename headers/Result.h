#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include <sstream>
#include "Unit.h"
#include "Date.h"

/**
 * @class Result
 * @brief Represents a course result including the unit and the mark achieved.
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
class Result{
    public:

        /**
         * @brief Default constructor
         * @return void
         */
        Result();

        /**
         * @brief Paremeterized constructor
         * @param u Unit object
         * @param mark m_mark value
         * @param d Date object
         * @return void
         */
        Result(const Unit& u, float mark, const Date& d);

        /**
         * @brief Getter function for m_mark
         * @param mark The variable to be stored with m_mark
         * @return void
         */
        void GetMark(float& mark) const;

        /**
         * @brief Setter function for m_mark
         * @param mark The variable to assign to m_mark
         * @return void
         */
        void SetMark(float mark);

        /**
         * @brief Getter function for m_unit
         * @param unit The variable to be stored with m_unit
         * @return void
         */
        void GetUnit(Unit& unit) const;

        /**
         * @brief Setter function for m_unit
         * @param unit The variable to assign to m_unit
         * @return void
         */
        void SetUnit(const Unit& unit);

        /**
         * @brief Getter function for m_date
         * @param date The variable to be stored with m_date
         * @return void
         */
        void GetDate(Date& date) const;

        /**
         * @brief Setter function for m_date
         * @param date The variable to assign to m_date
         * @return void
         */
        void SetDate(const Date& date);

        /**
         * @brief Getter function for credits in m_unit
         * @param cred The variable to be stored with credits
         * @return void
         */
        void GetCredits(int& cred) const;
    private:
        Unit m_unit; /**< m_unit represents the wrapped Unit object*/
        float m_mark; /**< The mark of the course*/
        Date m_date; /**< m_date represents the date on which the unit mark is given */
};


/**
 * @brief Overloads the input stream operator for Result.
 * @param input Input stream.
 * @param r Result object to be input.
 * @return Reference to the input stream.
 */
std::istream& operator>>(std::istream& input, Result& r);

/**
 * @brief Overloads the output stream operator for Result.
 * @param output Output stream.
 * @param r Result object to output.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& output, const Result& r);

#endif