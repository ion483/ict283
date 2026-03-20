#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Unit.h"
#include "Result.h"
#include "Date.h"

#include <iostream>
#include <sstream>

const unsigned MaxResults = 10;


/**
 * @class Registration
 * @brief Represents a student's registration details including ID, semester, course count, and results.
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
class Registration {
public:

  /**
   * @brief Default constructor
   * @return void
   */
  Registration();

  /**
   * @brief Getter function for student id
   * @param id The variable to be stored with student id
   * @return void
   */
  void GetStudentId(long& id) const;

  /**
   * @brief Setter function for student id
   * @param id The variable to assign to student id
   * @return void
   */
  void SetStudentId(long id);

  /**
   * @brief Getter function for semester
   * @param nSemester The variable to be stored with semester
   * @return void
   */
  void GetSemester(int& nSemester) const;

  /**
   * @brief Setter function for semester
   * @param nSemester The variable to assign to semester
   * @return void
   */
  void SetSemester(int nSemester);

  /**
   * @brief Getter function for count
   * @param nCount The variable to be stored with count
   * @return void
   */
  void GetCount(int& nCount) const;

  /**
   * @brief Setter function for count
   * @param nCount The variable to assign to count
   * @return void
   */
  void SetCount(int nCount);

  /**
   * @brief Getter function for results items
   * @param r The variable to be stored with the results item
   * @param index The position of the item
   * @return void
   */
  void GetResult(Result& r, int index) const;

  /**
   * @brief Setter function for results items
   * @param r The variable to assign to the results item
   * @param index The position of the item
   * @return void
   */
  void SetResult(const Result& r, int index);

  /**
   * @brief Getter function for sum of credits in results
   * @return The sum of credits in results as int
   */
  void GetCredits(int& credSum) const;


private:
  long studentId;             /**< student ID number*/
  int semester;          /**< semester year, number*/
  int count;             /**< number of results*/
  Result results[MaxResults];  /**< Array of Result*/
};


/**
 * @brief Overloads the output stream operator for Registration.
 * @param os Output stream.
 * @param R Registration object to output.
 * @return Reference to the output stream.
 */
std::ostream & operator <<( std::ostream & os, const Registration& R);

/**
 * @brief Overloads the input stream operator for Registration.
 * @param input Input stream.
 * @param R Registration object to be input.
 * @return Reference to the input stream.
 */
std::istream & operator >>( std::istream & input, Registration& R );

#endif

