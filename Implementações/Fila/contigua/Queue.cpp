#include "Queue.h"
#include <stdexcept>

template <typename T, unsigned int capacity>
Queue<T, capacity>::Queue():
    MAX_QUEUE(capacity),
    count(0),
    head(1),
    tail(0)
{}

template <typename T, unsigned int capacity>
Queue<T, capacity>::~Queue() {}

template <typename T, unsigned int capacity>
bool Queue<T, capacity>::Empty() {
    return this->count == 0;
}

template <typename T, unsigned int capacity>
bool Queue<T, capacity>::Full() {
    return this->count == MAX_QUEUE;
}

template <typename T, unsigned int capacity>
void Queue<T, capacity>::Append(T entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    tail = (tail % MaxQueue) + 1;
    Entry[tail] = entry;
    count++;
}

template <typename T, unsigned int capacity>
void Queue<T, capacity>::Serve(T& entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    entry = Entry[head];
    head = (head % MaxQueue) + 1;
    count--;
}

template <typename T, unsigned int capacity>
void Queue<T, capacity>::Front(T& entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    entry = Entry[head];
}

template <typename T, unsigned int capacity>
void Queue<T, capacity>::Rear(T& entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    entry = Entry[tail];
}

template <typename T, unsigned int capacity>
void Queue<T, capacity>::ClearSE() {
    int entry;
    while (!Empty())
        Serve(entry);
}

template <typename T, unsigned int capacity>
void Queue<T, capacity>::ClearCO() {
    this->count = 0;
    this->head = 1;
    this->tail = 0;
}

template <typename T, unsigned int capacity>
unsigned int Queue<T, capacity>::Size() {
    return this->count;
}