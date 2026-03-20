#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <queue>
#include <deque>
#include <stdexcept>

template <class Q>
class Queue : public std::queue<Q, std::deque<Q>>{
    private:
        struct Node{
            Q data;
            Node* nextNode;

            Node(Q data);
        };

        Node* first;
        Node* last;
        int count;

    public:
        Queue();
        ~Queue();

        void enqueue(Q value);

        void dequeue();

        Q front() const;

        int size() const;

        bool isEmpty() const;

        const std::deque<Q>& getContainer() const;
};

template <class Q>
Queue<Q>::Node::Node(Q data): data(data), nextNode(nullptr){}

template <class Q>
Queue<Q>::Queue(): first(nullptr), last(nullptr), count(0){}

template <class Q>
Queue<Q>::~Queue(){
    while(!isEmpty()){
        dequeue();
    }
}

template <class Q>
void Queue<Q>::enqueue(Q value){
    if(count == 0){
        Node* newNode = new Node(value);
        last = newNode;
        first = last;
        count++;

        (this -> c).push_back(value);
    }else{
        Node* newNode = new Node(value);
        last -> nextNode = newNode;
        last = newNode;
        count++;

        (this -> c).push_back(value);
    }
}

template <class Q>
void Queue<Q>::dequeue(){
    if(isEmpty()){
        throw std::underflow_error("Queue is empty");
    }
    Node* tempNode = first;
    first = first -> nextNode;
    delete tempNode;
    count--;
    if(count == 0){
        last = nullptr;
    }

    (this -> c).pop_front();
}

template <class Q>
Q Queue<Q>::front() const{
    if(isEmpty()){
        throw std::underflow_error("Queue is empty");
    }
    return first -> data;
}

template <class Q>
int Queue<Q>::size() const{
    return count;
}

template <class Q>
bool Queue<Q>::isEmpty() const{
    return first == nullptr && count == 0;
}

template <class Q>
const std::deque<Q>& Queue<Q>::getContainer() const{
    return this -> c;
}



#endif