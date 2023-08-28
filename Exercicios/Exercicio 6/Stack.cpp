#include "Stack.h"
#include <iostream>

Stack::Stack() {
    this->topNode = NULL;
}

bool Stack::empty() {
    return topNode == NULL;
}

bool Stack::full() {
    return false;
}

void Stack::push(int entry) {
    StackNode* stackNode = new StackNode;
    if (stackNode == NULL) {
        std::cout << "Pilha cheia!" << std::endl;
        return;
    }
    stackNode->entry = entry;
    stackNode->nextNode = topNode;
    topNode = stackNode;
}

void Stack::top(int& entry) {
    entry = topNode->entry;
}

void Stack::pop(int& entry) {
    if (this->empty()) {
        std::cout << "Pilha vazia!" << std::endl;
        return;
    }
    entry = topNode->entry;
    StackNode* tempNode = topNode;
    topNode = topNode->nextNode;
    delete tempNode;
}