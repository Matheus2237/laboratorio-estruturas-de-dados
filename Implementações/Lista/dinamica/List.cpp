#include "List.h"
#include <iostream>

List::List() {
    head = NULL;
    count = 0;
}

List::~List() {
    ListPointer disposable;
    while (head != NULL) {
        disposable = head;
        head = head->NextNode;
        delete disposable;
    }
}

bool List::Empty() {
    return head == NULL;
}

bool List::Full() {
    return false;
}

void List::Insert(int pos, int entry) {
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    ListPointer newNode = new ListNode;
    if (newNode == NULL) throw std::out_of_range("Lista cheia!");
    newNode->Entry = entry;
    if (pos == 1) {
        newNode->NextNode = head;
        head = newNode;
    } else {
        ListPointer current;
        SetPosition(pos-1, current);
        newNode->NextNode = current->NextNode;
        current->NextNode = newNode;
    }
    count++;
}

void List::Delete(int pos, int& entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    ListPointer deletable = new ListNode;
    if (deletable == NULL) throw std::bad_alloc();
    if (pos == 1) {
        deletable = head;
        head = head->NextNode;
    } else {
        ListPointer current;
        SetPosition(pos-1, current);
        deletable = current->NextNode;
        current->NextNode = deletable->NextNode;
    }
    entry = deletable->Entry;
    delete deletable;
    count--;
}

void List::Retrieve(int pos, int& entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    ListPointer current;
    SetPosition(pos, current);
    entry = current->Entry;
}

void List::Replace(int pos, int entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    ListPointer current;
    SetPosition(pos, current);
    current->Entry = entry;
}

void List::Clear() {
    ListPointer deletable;
    while (head != NULL) {
        deletable = head;
        head = head->NextNode;
        delete deletable;
    }
    count = 0;
}

int List::Size() {
    return count;
}

void List::minimum(int& pos, int& entry) {
    if (Empty())
        pos = 0;
    else {
        ListPointer q = head;
        int posit;
        entry = q->Entry;
        q = q->NextNode;
        while (q != NULL) {
            if (q->Entry < entry) {
                entry = q->Entry;
                pos = posit;
            }
            q = q->NextNode;
            pos++;
        }
    }
}

void List::Reverse() {
    ListPointer p = head;
    ListPointer q = NULL;
    while (p != NULL) {
        head = p;
        p = p->NextNode;
        head->NextNode = q;
        q = head;
    }
}

void List::SetPosition(int pos, ListPointer& current) {
    current = head;
    for (int i = 2; i <= pos; i++)
        current = current->NextNode;
}

List::ListIterator::ListIterator(ListPointer listPointer):
    listPointer(listPointer)
{}

int& List::ListIterator::operator*() {
    return listPointer->Entry;
}

List::ListIterator& List::ListIterator::operator++() {
    listPointer = listPointer->NextNode;
    return *this;
}

bool List::ListIterator::operator!=(const ListIterator& other) const {
    return listPointer != other.listPointer;
}

List::ListIterator List::begin() {
    return ListIterator(head);
}

List::ListIterator List::end() {
    return ListIterator(nullptr);
}