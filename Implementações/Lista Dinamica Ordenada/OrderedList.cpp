#include "OrderedList.h"
#include <stdexcept>

template <typename T>
OrderedList<T>::OrderedList():
    count(0)
{
    sentinel = new ListNode;
    if (sentinel == nullptr)
        throw std::bad_alloc();
    head = sentinel;
}

template <typename T>
OrderedList<T>::~OrderedList() {
    ListPointer disposable;
    while (head != sentinel) {
        disposable = head;
        head = head->NextNode;
        delete disposable;
    }
    delete sentinel;
}

template <typename T>
bool OrderedList<T>::Empty() {
    return head == sentinel;
}

template <typename T>
bool OrderedList<T>::Full() {
    return false;
}

template <typename T>
void OrderedList<T>::Insert(T entry) {
    sentinel->Entry = entry;
    ListPointer p = head;
    while (p->Entry < entry)
        p = p->NextNode;
    ListPointer q = new ListNode;
    if (q == NULL)
        throw std::bad_alloc();
    if (p == sentinel) {
        p->NextNode = q;
        sentinel = q;
    } else {
        *q = *p;
        p->NextNode = q;
        p->Entry = entry;
    }
    ++count;
}

template <typename T>
void OrderedList<T>::Delete(T entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    sentinel->Entry = entry;
    ListPointer p = nullptr;
    ListPointer q = head;
    while (q->Entry < entry) {
        p = q;
        q = q->NextNode;
    }
    if (q->Entry != entry || q == sentinel)
        throw std::out_of_range("O elemento nao se encontra na lista!");
    if (q == head)
        head = q->NextNode;
    else
        p->NextNode = q->NextNode;
    delete q;
    --count;
}

template <typename T>
unsigned int OrderedList<T>::Search(T entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    sentinel->Entry = entry;
    unsigned int position = 1;
    ListPointer q = head;
    while (q->Entry < entry) {
        q = q->NextNode;
        ++position;
    }
    if (q->Entry != entry || q == sentinel)
        return 0;
    return position;
}

template <typename T>
void OrderedList<T>::Clear() {
    ListPointer disposable;
    while (head != sentinel) {
        disposable = head;
        head = head->NextNode;
        delete head;
    }
    count = 0;
}

template <typename T>
unsigned int OrderedList<T>::Size() {
    return count;
}

template <typename T>
bool OrderedList<T>::SearchInsert(T entry) {
    sentinel->Entry = entry;
    ListPointer p = head;
    while (p->Entry < entry)
        p = p->NextNode;
    if (p != sentinel && p->Entry == entry)
        return true;
    ListPointer q = new ListNode;
    if (q == NULL)
        throw std::bad_alloc();
    if (p == sentinel) {
        p->NextNode = q;
        sentinel = q;
    } else {
        *q = *p;
        p->NextNode = q;
        p->Entry = entry;
    }
    ++count;
    return false;
}

template <typename T>
OrderedList<T>::Iterator::Iterator(typename OrderedList<T>::ListPointer current): current(current) {}

template <typename T>
typename OrderedList<T>::Iterator& OrderedList<T>::Iterator::operator++() {
    if (current)
        current = current->NextNode;
    return *this;
}

template <typename T>
typename OrderedList<T>::Iterator OrderedList<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
T OrderedList<T>::Iterator::operator*() {
    return current ? current->Entry : 0;
}

template <typename T>
bool OrderedList<T>::Iterator::operator==(const typename OrderedList<T>::Iterator& other) const {
    return current == other.current;
}

template <typename T>
bool OrderedList<T>::Iterator::operator!=(const typename OrderedList<T>::Iterator& other) const {
    return current != other.current;
}

template <typename T>
typename OrderedList<T>::Iterator OrderedList<T>::begin() {
    return Iterator(head);
}

template <typename T>
typename OrderedList<T>::Iterator OrderedList<T>::end() {
    return Iterator(sentinel);
}