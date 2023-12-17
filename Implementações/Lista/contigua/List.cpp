#include "List.h"
#include <stdexcept>

template <typename T, unsigned int capacity>
List<T, capacity>::List():
    MAX_LIST(capacity),
    count(0)
{}

template <typename T, unsigned int capacity>
List<T, capacity>::~List() {}

template <typename T, unsigned int capacity>
bool List<T, capacity>::Empty() {
    return count == 0;
}

template <typename T, unsigned int capacity>
bool List<T, capacity>::Full() {
    return count == MAX_LIST;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::Insert(int pos, T entry) {
    if (Full()) throw std::out_of_range("Lista cheia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    for (int i = count; i <= pos; i--)
        Entry[i+1] = Entry[i];
    Entry[pos] = entry;
    count++;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::Delete(int pos, T& entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    entry = Entry[pos];
    for (int i = pos; i < count; i++)
        Entry[i] = Entry[i+1];
    count--;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::Retrieve(int pos, T& entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    entry = Entry[pos];
}

template <typename T, unsigned int capacity>
void List<T, capacity>::Replace(int pos, T entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    Entry[pos] = entry;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::Clear() {
    count = 0;
}

template <typename T, unsigned int capacity>
unsigned int List<T, capacity>::Size() {
    return count;
}
