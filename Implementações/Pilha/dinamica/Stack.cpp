#include "Stack.h"
#include <iostream>
#include <stdexcept>

Stack::Stack():
    topNode(NULL),
    elementCounter(0)
{}

Stack::~Stack() {
    int x;
    while(!this->empty())
        this->pop(x);
}

bool Stack::empty() {
    return this->topNode == NULL;
}

bool Stack::full() {
    return false;
}

void Stack::push(int entry) {
    StackNode* stackNode = new StackNode;
    if (stackNode == NULL)
        throw std::bad_alloc();
    stackNode->data = entry;
    stackNode->nextNode = topNode;
    topNode = stackNode;
    elementCounter++;
}

void Stack::pop(int& entry) {
    if (this->empty())
        throw std::out_of_range("Pilha vazia!");
    entry = topNode->data;
    StackNode* tempNode = topNode;
    topNode = topNode->nextNode;
    delete tempNode;
    elementCounter--;
}

void Stack::clearEP() {
    int x;
    while (!this->empty())
        this->pop(x);
}

void Stack::clearPt() {
    while (this->topNode != NULL) {
        StackNode* tempNode = topNode;
        topNode = topNode->nextNode;
        delete tempNode;
    }
    elementCounter = 0;
}

void Stack::topPPE(int& entry) {
    if (this->empty())
        throw std::out_of_range("Pilha vazia!");
    this->pop(entry);
    this->push(entry);
}

void Stack::topPt(int& entry) {
    if (this->empty())
        throw std::out_of_range("Pilha vazia!");
    entry = topNode->data;
}

int Stack::size() {
    int size = 0;
    StackNode* currentNode = topNode;
    while (currentNode != NULL) {
        size++;
        currentNode = currentNode->nextNode;
    }
    return size;
}

int Stack::sizeOpt() {
    return this->elementCounter;
}