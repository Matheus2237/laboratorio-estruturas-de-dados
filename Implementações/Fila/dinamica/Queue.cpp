#include "Queue.h"
#include <iostream>
#include <stdexcept>

Queue::Queue() {
    head = NULL;
    tail = NULL;
    count = 0;
}

Queue::~Queue() {
    QueuePointer disposable;
    while (head != NULL) {
        disposable = head;
        head = head->NextNode;
        delete disposable;
    }
    tail = NULL;
    count = 0;
}

bool Queue::Empty() {
    return head == NULL;
}

bool Queue::Full() {
    return false;
}

void Queue::Append(int entry) {
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

void Queue::Serve(int& entry) {
    if (Empty())
        throw std::out_of_range("Fila vazia!");
    entry = head->Entry;
    QueuePointer disposableNode = head;
    head = head->NextNode;
    delete disposableNode;
    if (head == NULL)
        tail = NULL;
}

void Queue::Front(int& entry) {
    if (Empty())
        throw std::out_of_range("Fila vazia!");
    entry = head->Entry;
}

void Queue::Rear(int& entry) {
    if (Empty())
        throw std::out_of_range("Fila vazia!");
    entry = tail->Entry;
}

void Queue::ClearSE() {
    int disposable;
    while (!Empty())
        Serve(disposable);
}

void Queue::ClearCO() {
    QueuePointer temp;
    while (head != NULL) {
        temp = head;
        head = head->NextNode;
        delete temp;
    }
    tail = NULL;
    count = 0;
}

int Queue::Size() {
    return count;
}