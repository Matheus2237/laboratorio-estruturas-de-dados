#include "List.h"
#include <iostream>

List::List() {
    count = 0;
}

List::~List() {
    count = 0;
}

bool List::Empty() {
    return count == 0;
}

bool List::Full() {
    return count == MaxList;
}

void List::Insert(int pos, int entry) {
    if (Full()) throw std::out_of_range("Lista cheia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    for (int i = count; i <= pos; i--)
        Entry[i+1] = Entry[i];
    Entry[pos] = entry;
    count++;
}

void List::Delete(int pos, int& entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    entry = Entry[pos];
    for (int i = pos; i < count; i++)
        Entry[i] = Entry[i+1];
    count--;
}

void List::Retrieve(int pos, int& entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    entry = Entry[pos];
}

void List::Replace(int pos, int entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    Entry[pos] = entry;
}

void List::Clear() {
    count = 0;
}

int List::Size() {
    return count;
}
