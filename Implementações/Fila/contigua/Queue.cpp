#include "Queue.h"
#include <stdexcept>

Queue::Queue() {
    this->count = 0;
    this->head = 1;
    this->tail = 0;
}

Queue::~Queue() {}

bool Queue::Empty() {
    return this->count == 0;
}

bool Queue::Full() {
    return this->count == MaxQueue;
}

void Queue::Append(int entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    tail = (tail % MaxQueue) + 1;
    Entry[tail] = entry;
    count++;
}

void Queue::Serve(int& entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    entry = Entry[head];
    head = (head % MaxQueue) + 1;
    count--;
}

void Queue::Front(int& entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    entry = Entry[head];
}

void Queue::Rear(int& entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    entry = Entry[tail];
}

void Queue::ClearSE() {
    int entry;
    while (!Empty())
        Serve(entry);
}

void Queue::ClearCO() {
    this->count = 0;
    this->head = 1;
    this->tail = 0;
}

int Queue::Size() {
    return this->count;
}