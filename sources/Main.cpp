
#include "Unit.h"
#include "Date.h"
#include "Result.h"
#include "Registration.h"  // Registration class declaration/interface

// The library header files
#include <iostream>
#include <fstream>

int main()
{
  std::ifstream infile( "rinput.csv" ); //infile is an object on runtime stack
  if( !infile ) return -1;
  else std::cout << "input file opened successfully" << std::endl;

  Registration R;  

  infile >> R;   

  std::ofstream ofile( "routput.txt" );

  int count;
  int credSum;
  R.GetCount(count);
  R.GetCredits(credSum);
// Use a debugger and track down the calls made "behind the scene"
  ofile << R        // also a subroutine call. Can you guess what it means?
    << "Number of units = " << count << '\n'
    << "Total credits   = " << credSum << '\n';

  std::cout << "output file is written" << std::endl;


  return 0;
}

