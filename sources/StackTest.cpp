#include "Stack.h"
#include <cassert>

int main(){
    Stack<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    assert(s.top() == 3);
    assert(s.size() == 3);

    s.pop_back();

    assert(s.top() == 2);
    assert(s.size() == 2);

    s.pop_back();
    s.pop_back();

    assert(s.isEmpty());

    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    const auto& container = s.getContainer();

    for(const int& item : container){
        std::cout << item << " ";
    }

    std::cout << "\n Stack class passes all tests" << std::endl;


    return 0;
}