#include "Stack.h"
#include <stdexcept>

Stack::Stack():
    top_position(0)
{}

Stack::~Stack() {}

bool Stack::full() {
    return this->top_position == MAX_QUANTITY;
}

bool Stack::empty() {
    return this->top_position == 0;
}

void Stack::push(int entry) {
    if (this->full())
        throw std::out_of_range("Pilha cheia. Nao foi possivel inserir o elemento novo.");
    this->top_position++;
    this->entries[top_position] = entry;
}

void Stack::pop(int& entry) {
    if (this->empty()) 
        throw std::out_of_range("Pilha vazia. Nao foi possivel retirar o elemento.");
    entry = this->entries[top_position];
    top_position--;
}

void Stack::clearEP() {
    int x;
    while(!this->empty())
        this->pop(x);
}

void Stack::clearVT() {
    this->top_position = 0;
}

void Stack::topPPE(int& entry) {
    if (this->empty())
        throw std::out_of_range("Pilha vazia. Nao ha elementos no topo.");
    this->pop(entry);
    this->push(entry);
}

void Stack::topVT(int& entry) {
    if (this->top_position == 0)
        throw std::out_of_range("Pilha vazia. Nao ha elementos no topo.");
    entry = this->entries[top_position];
}

unsigned int Stack::size() {
    return this->top_position;
}