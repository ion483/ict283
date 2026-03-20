#ifndef CQueue_H
#define CQueue_H

#include <vector>
#include <stdexcept>

template <class T>
class CQueue{
    private:
        std::vector<T> data;
        int front;
        int rear;
        int currentSize;
        int capacity;

    public:
        CQueue(int nCapacity);
        
        bool empty() const;

        bool full() const;

        bool enqueue(const T& item);

        bool dequeue();

        int size() const;

        std::vector<T> getContainer() const;
};

template <class T>
CQueue<T>::CQueue(int nCapacity): capacity(nCapacity), data(nCapacity), currentSize(0), front(0), rear(-1){}

template <class T>
bool CQueue<T>::empty() const{
    return currentSize == 0;
}

template <class T>
bool CQueue<T>::full() const{
    return currentSize == capacity;
}

template <class T>
bool CQueue<T>::enqueue(const T& item){
    if(full()) return false;

    rear = (rear+1) % capacity;
    data[rear] = item;
    currentSize++;
    return true;
}

template <class T>
bool CQueue<T>::dequeue(){
    if(empty()) return false;

    front = (front+1) % capacity;
    currentSize--;
    return true;
}

template <class T>
int CQueue<T>::size() const{
    return currentSize;
}

template <class T>
std::vector<T> CQueue<T>::getContainer() const{
    std::vector<T> container(currentSize);
    for(int i = 0; i < currentSize; i++){
        int dataIndex = (front+i) % capacity;
        container[i] = data[dataIndex];
    }
    return container;
}

#endif