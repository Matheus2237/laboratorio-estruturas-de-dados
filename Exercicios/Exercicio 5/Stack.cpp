#include "Stack.h"
#include <iostream>

Stack::Stack() {
    this->top_position = 0;
}

Stack::~Stack() {
    std::cout << "Pilha destruida!" << std::endl;
}

bool Stack::full() {
    return this->top_position == MAX_ELEMENTS;
}

bool Stack::empty() {
    return this->top_position == 0;
}

void Stack::push(int entry) {
    if (this->full()) {
        std::cout << "Pilha cheia. Nao foi possivel inserir o elemento novo." << std::endl;
        return;
    }
    this->top_position++;
    this->entries[top_position] = entry;
}

void Stack::pop(int& entry) {
    if (this->empty()) {
        std::cout << "Pilha vazia. Nao foi possivel retirar o elemento." << std::endl;
        return;
    }
    entry = this->entries[top_position];
    top_position--;
}

void Stack::top(int& entry) {
    if (this->empty()) {
        std::cout << "Pilha vazia. Nao ha elementos no topo." << std::endl;
        return;
    }
    entry = this->entries[top_position];
}

unsigned int Stack::size() {
    return this->top_position;
}