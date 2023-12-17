#include "Stack.h"
#include <stdexcept>

template <typename T>
Stack<T>::Stack():
    topNode(nullptr),
    elementCounter(0)
{}

template <typename T>
Stack<T>::~Stack() {
    int x;
    while(!this->empty())
        this->pop(x);
}

template <typename T>
bool Stack<T>::empty() {
    return this->topNode == nullptr;
}

template <typename T>
bool Stack<T>::full() {
    return false;
}

template <typename T>
void Stack<T>::push(T entry) {
    StackNode* stackNode = new StackNode;
    if (stackNode == nullptr)
        throw std::bad_alloc();
    stackNode->data = entry;
    stackNode->nextNode = topNode;
    topNode = stackNode;
    elementCounter++;
}

template <typename T>
void Stack<T>::pop(T& entry) {
    if (this->empty())
        throw std::out_of_range("Pilha vazia!");
    entry = topNode->data;
    StackNode* tempNode = topNode;
    topNode = topNode->nextNode;
    delete tempNode;
    elementCounter--;
}

template <typename T>
void Stack<T>::clearEP() {
    int x;
    while (!this->empty())
        this->pop(x);
}

template <typename T>
void Stack<T>::clearPt() {
    while (this->topNode != nullptr) {
        StackNode* tempNode = topNode;
        topNode = topNode->nextNode;
        delete tempNode;
    }
    elementCounter = 0;
}

template <typename T>
void Stack<T>::topPPE(T& entry) {
    if (this->empty())
        throw std::out_of_range("Pilha vazia!");
    this->pop(entry);
    this->push(entry);
}

template <typename T>
void Stack<T>::topPt(T& entry) {
    if (this->empty())
        throw std::out_of_range("Pilha vazia!");
    entry = topNode->data;
}

template <typename T>
unsigned int Stack<T>::size() {
    int size = 0;
    StackNode* currentNode = topNode;
    while (currentNode != nullptr) {
        size++;
        currentNode = currentNode->nextNode;
    }
    return size;
}

template <typename T>
unsigned int Stack<T>::sizeOpt() {
    return this->elementCounter;
}