#include "Queue.h"
#include <iostream>
#include <stdexcept>

template <typename T>
Queue<T>::Queue() {
    head = NULL;
    tail = NULL;
    count = 0;
}

template <typename T>
Queue<T>::~Queue() {
    QueuePointer disposable;
    while (head != NULL) {
        disposable = head;
        head = head->NextNode;
        delete disposable;
    }
    tail = NULL;
    count = 0;
}

template <typename T>
bool Queue<T>::Empty() {
    return head == NULL;
}

template <typename T>
bool Queue<T>::Full() {
    return false;
}

template <typename T>
void Queue<T>::Append(T entry) {
    QueuePointer newNode = new QueueNode;
    if (newNode == NULL)
        throw std::bad_alloc();
    newNode->Entry = entry;
    if (head == NULL)
        head = newNode;
    else
        tail->NextNode = newNode;
    tail = newNode;
    newNode->NextNode = NULL;
}

template <typename T>
void Queue<T>::Serve(T& entry) {
    if (Empty())
        throw std::out_of_range("Fila vazia!");
    entry = head->Entry;
    QueuePointer disposableNode = head;
    head = head->NextNode;
    delete disposableNode;
    if (head == NULL)
        tail = NULL;
}

template <typename T>
void Queue<T>::Front(T& entry) {
    if (Empty())
        throw std::out_of_range("Fila vazia!");
    entry = head->Entry;
}

template <typename T>
void Queue<T>::Rear(T& entry) {
    if (Empty())
        throw std::out_of_range("Fila vazia!");
    entry = tail->Entry;
}

template <typename T>
void Queue<T>::ClearSE() {
    int disposable;
    while (!Empty())
        Serve(disposable);
}

template <typename T>
void Queue<T>::ClearCO() {
    QueuePointer temp;
    while (head != NULL) {
        temp = head;
        head = head->NextNode;
        delete temp;
    }
    tail = NULL;
    count = 0;
}

template <typename T>
unsigned int Queue<T>::Size() {
    return count;
}