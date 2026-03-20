#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stack>
#include <stdexcept>

template <class S>
class Stack : public std::stack<S>{
    private:
        struct Node{
            S data;
            Node* lastNode;

            Node(S value, Node* node);
        };
        Node* topNode;
        int count;

    public:
        Stack();
        ~Stack();

        void push_back(S value);

        void pop_back();

        const S& top() const;

        bool isEmpty() const;

        int size() const;

        const auto& getContainer() const;

};

template <class S>
Stack<S>::Node::Node(S value, Node* node): data(value), lastNode(node){}

template <class S>
Stack<S>::Stack(): topNode(nullptr), count(0){}

template <class S>
Stack<S>::~Stack(){
    while(!isEmpty()){
        pop_back();
    }
}

template <class S>
void Stack<S>::push_back(S value){
    Node* newNode = new Node(value, topNode);
    topNode = newNode;
    count++;
    this -> push(value);
}

template <class S>
void Stack<S>::pop_back(){
    if(isEmpty()){
        throw std::underflow_error("Stack is empty");
    }
    Node* temp = topNode;
    topNode = topNode -> lastNode;
    delete temp;
    count--;
    this -> pop();
}

template <class S>
const S& Stack<S>::top() const{
    if(isEmpty()){
        throw std::underflow_error("Stack is empty");
    }
    return topNode -> data;
}

template <class S>
bool Stack<S>::isEmpty() const{
    return topNode == nullptr && count == 0;
}

template <class S>
int Stack<S>::size() const{
    return count;
}

template <class S>
const auto& Stack<S>::getContainer() const{
    return this -> c;
}

#endif