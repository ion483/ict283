#include "Map.h"
#include <cassert>

int main(){
    Map<std::string, int> m;
    m["apple"] = 1;
    m["banana"] = 2;
    m["orange"] = 3;

    assert((m["apple"] == 1) && (m["banana"] == 2) && (m["orange"] == 3));

    for(auto it = m.begin(); it != m.end(); ++it){
        std::cout << it -> first << " -> " << it -> second << '\n';
    }

    int value = m["nonexsitingkey"];
    assert(value == 0);

    try{
        const Map<std::string, int> constM = m;
        int value = constM["keyNotFound"];
    }catch(const std::invalid_argument& e){
        std::cout << "const map extraction error with non existent key\n";
    }

    std::cout << "Map class passes all tests" << std::endl;

    return 0;
}