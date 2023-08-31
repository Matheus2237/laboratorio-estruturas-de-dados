#include "Queue.h"
#include <iostream>

Queue::Queue() {
    this->counter = 0;
    this->tail = 0;
    this->head = 1;
}

Queue::~Queue() {
    std::cout << "Fila destruida!" << std::endl;
}

bool Queue::empty() {
    return this->counter == 0;
}

bool Queue::full() {
    return this->counter == MaxQueue;
}

void Queue::append(int entry) {
    if (this->full()) {
        std::cout << "Fila cheia!" << std::endl;
        return;
    }
    this->counter++;
    this->tail = this->tail % MaxQueue + 1;
    this->entries[this->tail] = entry;
}

int Queue::size() { // Devemos ter cuidado com o uso do size podendo valer zero, pois se em algum momento dividirmos pelo size, estaríamos dividindo po zero.
    if (this->empty()) {
        std::cout << "Fila vazia." << std::endl;
        return -1;
    }
    return this->counter;
}

void Queue::serve(int& entry) {
    if (this->empty()) {
        std::cout << "Fila vazia." << std::endl;
        return;
    }
    entry = this->entries[this->head];
    this->counter--;
    this->head = this->head % MaxQueue + 1;
}

void Queue::rear(int& entry) {
    if (this->empty()) {
        std::cout << "Fila vazia! Nao ha elemento em tail." << std::endl;
        return;
    }
    entry = this->entries[this->tail];
}

void Queue::front(int& entry) {
    if (this->empty()) {
        std::cout << "Fila vazia! Nao ha elementos em head." << std::endl;
        return;
    }
    entry = this->entries[this->head];
}

void Queue::clear() {
    this->counter = 0;
    this->head = 1;
    this->tail = 0;
}