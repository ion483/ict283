#include "Unit.h"

#include <cstring>

// default constructor
Unit::Unit()
{
  name = "";
  id = "";
  credits = 0;
}

// paremeterized constructor
Unit::Unit(const std::string& nam, const std::string& idp, int cred)
{
  name = nam;
  id = idp;
  credits = cred;
}

// unit name getter
void Unit::GetName(std::string& nName) const{
  nName = name;
}

// unit name setter
void Unit::SetName(const std::string& nName){
  name = nName;
}

// unit id getter
void Unit::GetId(std::string& nId) const{
  nId = id;
}

// unit id setter
void Unit::SetId(const std::string& nId){
  id = nId;
}

// unit credits getter
void Unit::GetCredits(int& cred) const
{
  cred = credits;
}

// unit credits setter
void Unit::SetCredits(int cred)
{
  credits = cred;
}

/*
std::istream& operator>>(std::istream& input, Unit& U)
{
  std::string inputStr;
  std::getline(input, inputStr);
  std::istringstream iss(inputStr);

  std::string nameStr, idStr;
  int cred = 0;

  iss >> nameStr >> idStr >> cred;

  std::regex pattern("_");
  std::string formattedNameStr = std::regex_replace(nameStr, pattern, " ");
  std::string formattedIdStr = std::regex_replace(idStr, pattern, " ");

  U.SetName(formattedNameStr.c_str());
  U.SetId(formattedIdStr.c_str());
  U.SetCredits(cred);

  return input;
}
*/

// unit input operator
std::istream& operator>>(std::istream& is, Unit& U){
  std::string name, id, creditsStr;
  int credits;
  const char delimiter = ',';
  
  std::getline(is, name, delimiter);
  std::getline(is, id, delimiter);

  std::getline(is, creditsStr, delimiter);
  try{
    credits = std::stoi(creditsStr);
  }catch(...){
    credits = 0;
  }

  U.SetName(name);
  U.SetId(id);
  U.SetCredits(credits);

  return is;
}

// unit output operator
std::ostream& operator<<(std::ostream& os, const Unit& U)
{
  std::string bufferName;
  std::string bufferId;
  int cred;

  U.GetName(bufferName);
  U.GetId(bufferId);
  U.GetCredits(cred);

  os << "  Unit Name: " << bufferName << '\n'
     << "  Unit ID:   " << bufferId << '\n'
     << "  Credits:   " << cred << '\n';
  
  return os;
}
