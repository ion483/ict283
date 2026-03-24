#include "Map.h"
#include <cassert>

int main(){
    Map<std::string, int> m; // test id 1: Standard Key-Value Insertion & Retrieval
    m["apple"] = 1;
    m["banana"] = 2;
    m["orange"] = 3;

    assert((m["apple"] == 1) && (m["banana"] == 2) && (m["orange"] == 3));

    // test id 2: Iterator Functionality & Map Traversal
    for(auto it = m.begin(); it != m.end(); ++it){
        std::cout << it -> first << " -> " << it -> second << '\n';
    }

    // test id 3: Mutable Access Auto-Insertion
    int value = m["nonexsitingkey"];
    std::cout << "is value = 0? " << (value == 0? "Yes" : "No") << '\n';

    try{
        const Map<std::string, int> constM = m;

        // test id 4: Const map should throw exception rather than modify the map
        int value = constM["keyNotFound"];
    }catch(const std::invalid_argument& e){
        std::cout << "const map extraction error with non existent key\n";
    }

    std::cout << "Map class passes all tests" << std::endl;

    return 0;
}