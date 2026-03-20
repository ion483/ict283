#include "Unit.h"
#include <cassert>
#include <sstream>

int main(){
    Unit defaultUnit;
    defaultUnit.SetName("Data abstraction");
    defaultUnit.SetId("Ict283");
    defaultUnit.SetCredits(3);

    std::cout << "default unit: \n" << defaultUnit;

    Unit inputUnit;
    std::istringstream iss("Database coding,Ict285,4");
    iss >> inputUnit;
    std::cout << "\n input unit: \n" << inputUnit;

    Unit paramUnit("Machine learning", "Ict202", 2);
    std::cout << "\n param unit: \n" << paramUnit;

    std::string bufferName;
    std::string bufferId;
    int credits;
    
    paramUnit.GetName(bufferName);
    paramUnit.GetId(bufferId);
    paramUnit.GetCredits(credits);


    assert(bufferName == "Machine learning");
    assert(bufferId == "Ict202");
    assert(credits == 2);

    Unit defaultUnit2;
    std::cout << "\ndefaultUnit2: \n" << defaultUnit2 << std::endl;

    Unit paramUnit2("Data abstraction", "ICT283", 4);
    std::cout << "paramUnit2: \n" << paramUnit2 << std::endl;


    std::cout << "\n Unit class passes all tests" << std::endl;

    return 0;
}