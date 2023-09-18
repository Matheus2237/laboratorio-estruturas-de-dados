#include "List.h"
#include <iostream>

List::List() {
    this->counter = 0;
    this->head = NULL;
}

List::~List() {
    if (this->head == NULL)
        return;
    ListPointer tempNode = head;
    head = head->nextNode;
    delete tempNode;
    this->~List();
}

bool List::Empty() {
    return this->counter == 0;
}

int List::Size() {
    return this->counter;
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

void List::SetPosition(int position, List::ListPointer &current) {
    current = this->head;
    for (int i = 2; i <= position; ++i) {
        current = current->nextNode;
    }
}

void List::printBackwards() const {
    if (head == NULL)
        throw std::out_of_range("Lista vazia!");
    ListPointer printableNode = head;
    this->printBackwards(printableNode);
    std::cout << std::endl;
}

void List::printBackwards(ListPointer node) const {
    if (node->nextNode != NULL)
        this->printBackwards(node->nextNode);
    std::cout << " " << node->entry;
    return;
}

void List::remove_valor(int x) {
    if (head == NULL)
        throw std::out_of_range("Lista vazia!");
    ListPointer firstNode = head;
    this->removeNode(x, firstNode);
}

List::ListPointer List::removeNode(int x, ListPointer node) {
    if (node == NULL)
        throw std::out_of_range("Elemento nao esta presente na lista");
    if (node->entry == x) {
        ListPointer nextNode = node->nextNode;
        delete node;
        return nextNode;
    }
    node->nextNode = removeNode(x, node->nextNode);
    return node;
}