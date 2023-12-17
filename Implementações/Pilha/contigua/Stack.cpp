#include "Stack.h"
#include <stdexcept>

template <typename T, unsigned int capacity>
Stack<T, capacity>::Stack():
    MAX_QUANTITY(capacity),
    top_position(0)
{}

template <typename T, unsigned int capacity>
Stack<T, capacity>::~Stack() {}

template <typename T, unsigned int capacity>
bool Stack<T, capacity>::full() {
    return this->top_position == MAX_QUANTITY;
}

template <typename T, unsigned int capacity>
bool Stack<T, capacity>::empty() {
    return this->top_position == 0;
}

template <typename T, unsigned int capacity>
void Stack<T, capacity>::push(T entry) {
    if (this->full())
        throw std::out_of_range("Pilha cheia. Nao foi possivel inserir o elemento novo.");
    this->top_position++;
    this->entries[top_position] = entry;
}

template <typename T, unsigned int capacity>
void Stack<T, capacity>::pop(T& entry) {
    if (this->empty()) 
        throw std::out_of_range("Pilha vazia. Nao foi possivel retirar o elemento.");
    entry = this->entries[top_position];
    top_position--;
}

template <typename T, unsigned int capacity>
void Stack<T, capacity>::clearEP() {
    int x;
    while(!this->empty())
        this->pop(x);
}

template <typename T, unsigned int capacity>
void Stack<T, capacity>::clearVT() {
    this->top_position = 0;
}

template <typename T, unsigned int capacity>
void Stack<T, capacity>::topPPE(T& entry) {
    if (this->empty())
        throw std::out_of_range("Pilha vazia. Nao ha elementos no topo.");
    this->pop(entry);
    this->push(entry);
}

template <typename T, unsigned int capacity>
void Stack<T, capacity>::topVT(T& entry) {
    if (this->top_position == 0)
        throw std::out_of_range("Pilha vazia. Nao ha elementos no topo.");
    entry = this->entries[top_position];
}

template <typename T, unsigned int capacity>
unsigned int Stack<T, capacity>::size() {
    return this->top_position;
}