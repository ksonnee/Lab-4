#include "Stack.h"

template <typename T>
Stack<T>::Stack() : topPtr(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    while (!IsEmpty()) {
        Pop();
    }
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return topPtr == nullptr;
}

template <typename T>
bool Stack<T>::IsFull() const {
    return false;
}

template <typename T>
void Stack<T>::Push(const T& item) {
    Node* newNode = new Node{ item, topPtr };
    topPtr = newNode;
}

template <typename T>
void Stack<T>::Pop() {
    if (!IsEmpty()) {
        Node* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
    else {
        std::cerr << "Error: Stack is empty. Cannot pop." << std::endl;
    }
}

template <typename T>
T Stack<T>::Top() const {
    if (!IsEmpty()) {
        return topPtr->data;
    }
    else {
        std::cerr << "Error: Stack is empty. Cannot get top item." << std::endl;
        return T{};
    }
}
