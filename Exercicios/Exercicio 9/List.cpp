#include "List.h"
#include <iostream>

List::List() {
    this->counter = 0;
    this->head = NULL;
}

List::~List() {
    ListPointer temp;
    while (this->head != NULL) {
        temp = head;
        this->head = this->head->nextNode;
        delete temp;
    }
}

bool List::Empty() {
    return this->counter == 0;
}

bool List::Full() {
    return false;
}

void List::Insert(int position, int entry) {
    if (position < 1 || position > this->counter + 1) {
        std::cout << "Posicao invalida para insercao!" << std::endl;
        return;
    }
    ListPointer newNode = new ListNode;
    if (newNode == NULL) {
        std::cout << "Falha na alocacao dinamica!" << std::endl;
        return;
    }
    newNode->entry = entry;
    ListPointer current;
    if (position == 1) {
        newNode->nextNode = this->head;
        this->head = newNode;
    } else {
        SetPosition(position-1, current);
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    this->counter++;
}

void List::Delete(int position, int &entry) {
    if (position < 1 || position > this->counter) {
        std::cout << "Posicao de remocao invalida!" << std::endl;
        return;
    }
    if (this->Empty()) {
        std::cout << "Estrutura vazia!" << std::endl;
        return;
    }
    ListPointer temp;
    ListPointer current;
    if (position == 1) {
        temp = this->head;
        head = head->nextNode;
    } else {
        SetPosition(position - 1, current);
        temp = current->nextNode;
        current->nextNode = temp->nextNode;
    }
    entry = temp->entry;
    delete temp;
    this->counter++;
}

int List::Size() {
    return this->counter;
}

void List::Clear() {
    ListPointer temp;
    while (this->head != NULL) {
        temp = head;
        this->head = this->head->nextNode;
        delete temp;
    }
    this->counter = 0;
}

void List::Retrieve(int position, int& entry) {
    if (position < 1 || position > this->counter) {
        std::cout << "Posicao de recuperacao invalida!" << std::endl;
        return;
    }
    if (this->Empty()) {
        std::cout << "Estrutura vazia!" << std::endl;
        return;
    }
    ListPointer current;
    SetPosition(position, current);
    entry = current->entry;
}

void List::Replace(int position, int entry) {
    if (position < 1 || position > this->counter) {
        std::cout << "Posicao de recuperacao invalida!" << std::endl;
        return;
    }
    if (this->Empty()) {
        std::cout << "Estrutura vazia!" << std::endl;
        return;
    }
    ListPointer current;
    SetPosition(position, current);
    current->entry = entry;
}

void List::SetPosition(int position, List::ListPointer &current) {
    current = this->head;
    for (int i = 2; i <= position; ++i) {
        current = current->nextNode;
    }
}