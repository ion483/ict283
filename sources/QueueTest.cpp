#include "Queue.h"
#include <cassert>

int main(){
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    assert(q.front() == 1);
    assert(q.size() == 5);
    
    q.dequeue();

    assert(q.front() == 2);
    assert(q.size() == 4);

    const std::deque<int>& c = q.getContainer();
    for(int i = 0; i < c.size(); i++){
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    assert(q.isEmpty());

    try{
        q.dequeue();
    }catch(const std::underflow_error& e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "Queue class passes all tests" << std::endl;

    return 0;
}