#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <sstream>

/**
 * @class Unit
 * @brief Represents a course unit with its name, ID, and credits
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
class Unit {
public:

  /**
   * @brief Default constructor that initializes an empty Unit object
   * @return void
   */
  Unit();

  /**
   * @brief Paremeterized constructor that initializes a Unit with input values
   * @param nam Const pointer to an array of characters that represent the unit name
   * @param idp Const pointer to an array of characters that represent the unit id
   * @param cred Number of credits for the unit
   * @return void
   */
  Unit(const std::string& nam, const std::string& idp, int cred );  // nam is a pointer to char, revise ict159

  /**
   * @brief Getter function for name
   * @param charptr The pointer to the input char array
   * @return void
   */
  void GetName(std::string& nName) const;

  /**
   * @brief Setter function for name
   * @param charptr Const pointer to the input char array
   * @return void
   */
  void SetName(const std::string& nName);

  /**
   * @brief Getter function for id
   * @param charptr The pointer to the input char array
   * @return void
   */
  void GetId(std::string& nId) const;

  /**
   * @brief Setter function for id
   * @param charptr Const pointer to the input char array
   * @return void
   */
  void SetId(const std::string& nId);

  /**
   * @brief Getter function for credits
   * @param cred The variable to be stored with credits
   * @return void
   */
  void GetCredits(int& cred) const;
  // Get the number of credits.

  /**
   * @brief Setter function for credits
   * @param cred The variable to assign to credits
   * @return void
   */
  void SetCredits(int cred);
  // Set the number of credits.

private:
  std::string name;  /**< The name char array to be stored with unit name characters*/
  std::string id; /**< The id char array to be stored with unit id characters*/
  int  credits;   /**< Number of credits*/
};


/**
 * @brief Overloads the output stream operator for Unit.
 * @param os Output stream.
 * @param U Unit object to output.
 * @return Reference to the output stream.
 */
std::ostream & operator <<( std::ostream & os, const Unit & U);


/**
 * @brief Overloads the input stream operator for Unit.
 * @param is Input stream.
 * @param U Unit object to be input.
 * @return Reference to the input stream.
 */
std::istream & operator >>( std::istream & is, Unit & U);


#endif
