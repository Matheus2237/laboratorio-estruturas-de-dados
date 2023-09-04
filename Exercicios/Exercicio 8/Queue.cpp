#include "Queue.h"
#include <iostream>

Queue::Queue() {
    this->head = NULL;
    this->tail = NULL;
}

Queue::~Queue() {
    int deletable;
    while (!this->empty())
        this->serve(deletable);
}

bool Queue::empty() {
    return this->head == NULL;
}

bool Queue::full() {
    return false;
}

void Queue::append(int entry) {
    QueueNode* newNode = new QueueNode;
    if (newNode == NULL) {
        std::cout << "FIla cheia! Nao ha espaco para o novo elemento." << std::endl;
        return;
    }
    newNode->entry = entry;
    newNode->nextNode = NULL;
    if (this->empty()) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->nextNode = newNode;
        this->tail = newNode;
    }
}

void Queue::serve(int& entry) {
    if (this->empty()) {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }
    entry = this->head->entry;
    QueueNode* temporaryNode = this->head;
    head = this->head->nextNode;
    delete temporaryNode;
    if (this->head == NULL)
        this->tail == NULL;
}

void Queue::front(int& entry) {
    if (this->empty()) {
        std::cout << "Fila vazia! Nao ha elemento em head!" << std::endl;
        return;
    }
    entry = this->head->entry;
}

void Queue::rear(int& entry) {
    if (this->empty()) {
        std::cout << "Fila vazia! Nao ha elemento em head!" << std::endl;
        return;
    }
    entry = this->tail->entry;
}

int Queue::size() {
    int counter = 0;
    QueueNode* temporaryPointer = head;
    while (temporaryPointer != NULL) {
        counter++;
        temporaryPointer = temporaryPointer->nextNode;
    }
    return counter;
}

void Queue::clear() {
    int deletable;
    while (this->empty())
        this->serve(deletable);
}