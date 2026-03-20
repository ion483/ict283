// REGIST.CPP - Registration class implementation.

#include "Registration.h"

// default constructor
Registration::Registration()
{
  studentId = 0;
  semester = 0;
  count = 0;
}

// registration student id getter
void Registration::GetStudentId(long& id) const{
  id = studentId;
}

// registration student id setter
void Registration::SetStudentId(long id){
  studentId = id;
}

// registration semester getter
void Registration::GetSemester(int& nSemester) const{
  nSemester = semester;
}

// registration semester setter
void Registration::SetSemester(int nSemester){
  semester = nSemester;
}

// registration count getter
void Registration::GetCount(int& nCount) const{
  nCount = count;
}

// registration count setter
void Registration::SetCount(int nCount){
  count = nCount;
}

// registration result getter
void Registration::GetResult(Result& r, int index) const{
  r = results[index];
}

// registration result setter
void Registration::SetResult(const Result& r, int index){
  results[index] = r;
}

// registration results credits sum getter
void Registration::GetCredits(int& credSum) const
{
  int sum = 0;
  for(int i = 0; i < count; i++){
    int cred;
    results[i].GetCredits(cred); 
    sum += cred;
  }

  credSum = sum;
}


// registration input operator
std::istream & operator >>(std::istream& input, Registration& R)
{
  std::string registStr; // process input line by line
  std::getline(input, registStr); 
  std::istringstream iss(registStr);
  const char delimiter = ',';
  std::string studentIdStr, semesterStr, countStr;
  long studentId;
  int semester;
  int count;


  std::getline(iss, studentIdStr, delimiter);
  try{
    studentId = std::stol(studentIdStr);
  }catch(...){
    studentId = 0;
  }

  std::getline(iss, semesterStr, delimiter);
  try{
    semester = std::stoi(semesterStr);
  }catch(...){
    semester = 0;
  }

  std::getline(iss, countStr, delimiter);
  try{
    count = std::stoi(countStr);
  }catch(...){
    count = 0;
  }

  R.SetStudentId(studentId);
  R.SetSemester(semester);
  R.SetCount(count);

  for(int i = 0; i < count; i++){
    Result tempResult;
    input >> tempResult;
    R.SetResult(tempResult, i);
  }

  return input;
}

// registration output operator
std::ostream & operator <<(std::ostream& os, const Registration& R )
{
  long studentId;
  int semester;
  int count;

  R.GetStudentId(studentId);
  R.GetSemester(semester);
  R.GetCount(count);

  os << "Student ID:  " << studentId << '\n'
     << "Semester:    " << semester << '\n';

  for(int i = 0; i < count; i++){
    Result tempResult;
    R.GetResult(tempResult, i);
    os << tempResult << '\n';
  }

  return os;
}
