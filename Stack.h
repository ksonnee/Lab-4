#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* topPtr;

public:

    Stack();

    ~Stack();

    bool IsEmpty() const;

    bool IsFull() const;

    void Push(const T& item);

    void Pop();

    T Top() const;
};

#include "Stack.cpp"

#endif


