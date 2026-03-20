#include "CQueue.h"
#include <iostream>

int main(){
    CQueue<int> cq(5);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    std::vector<int> c = cq.getContainer();
    for(int i = 0; i < c.size(); i++){
        std::cout << c[i] << " ";
    }
    std::cout << '\n';

    cq.dequeue();
    cq.dequeue();
    cq.dequeue();

    cq.enqueue(1);
    cq.enqueue(2);

    c = cq.getContainer();
    for(int i = 0; i < c.size(); i++){
        std::cout << c[i] << " ";
    }
    std::cout << '\n';


    return 0;
}