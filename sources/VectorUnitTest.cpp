#include "Vector.h"
#include <cassert>

int main(){
    Vector<int> v;
    
    bool isEmpty = v.IsEmpty();
    std::cout << "is V empty: " << (isEmpty? "Yes": "No") << '\n'; // test id 1

    v.Insert(1, v.GetSize());
    v.Insert(2, v.GetSize());
    v.Insert(3, v.GetSize());

    /*<1,2,3>*/
    
    assert(v.GetSize() == 3);
    std::cout << "vector size after pushing 1,2,3: " << v.GetSize() << '\n'; // test id 2
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);


    v.Insert(7, 1); // test id 3

    /*<1,7,2,3>*/

    std::cout << "vector size after inserting 7 at index 1: " << v.GetSize() << '\n';
    std::cout << "vector index 1 item: " << v[1] << '\n';
    assert(v[1] == 7);
    assert(v.GetSize() == 4);

    v.DeleteAt(1); // test id 4

    /*<1,2,3>*/

    std::cout << "vector size after deleting at index 1: " << v.GetSize() << '\n';
    std::cout << "vector index 1 item: " << v[1] << '\n';
    assert(v[1] == 2);
    assert(v.GetSize() == 3);

    Vector<int> v2;
    v2.Insert(15, v2.GetSize());
    v2.Insert(20, v2.GetSize());
    std::cout << "v2[0]: " << v2[0] << " v2[1]: " << v2[1] << '\n';
    std::cout << "v2 size: "<< v2.GetSize() << '\n';


    Vector<int> v3; // test id 7
    v3 = v2;
    std::cout << "v3[0]: " << v3[0] << " v3[1]: " << v3[1] << '\n';
    std::cout << "v3 size: "<< v3.GetSize() << '\n';
    assert(v3[0] == 15);
    assert(v3[1] == 20);
    assert(v3.GetSize() == 2);


    Vector<int> v4(v2); // test id 8

    std::cout << "v4[0]: " << v4[0] << " v4[1]: " << v4[1] << '\n';
    std::cout << "v4 size: "<< v4.GetSize() << '\n';
    assert(v4[0] == 15);
    assert(v4[1] == 20);
    assert(v4.GetSize() == 2);

    std::cout << "Vector class has passed all tests" << std::endl;

    return 0;
}