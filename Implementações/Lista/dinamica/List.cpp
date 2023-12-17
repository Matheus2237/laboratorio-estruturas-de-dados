#include "List.h"
#include <stdexcept>

template <typename T>
List<T>::List():
    head(nullptr),
    count(0)
{}

template <typename T>
List<T>::~List() {
    ListPointer disposable;
    while (head != nullptr) {
        disposable = head;
        head = head->NextNode;
        delete disposable;
    }
}

template <typename T>
bool List<T>::Empty() {
    return head == nullptr;
}

template <typename T>
bool List<T>::Full() {
    return false;
}

template <typename T>
void List<T>::Insert(int pos, T entry) {
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    ListPointer newNode = new ListNode;
    if (newNode == nullptr) throw std::out_of_range("Lista cheia!");
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

template <typename T>
void List<T>::Delete(int pos, T& entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    ListPointer deletable = new ListNode;
    if (deletable == nullptr) throw std::bad_alloc();
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

template <typename T>
void List<T>::Retrieve(int pos, T& entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    ListPointer current;
    SetPosition(pos, current);
    entry = current->Entry;
}

template <typename T>
void List<T>::Replace(int pos, T entry) {
    if (Empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    ListPointer current;
    SetPosition(pos, current);
    current->Entry = entry;
}

template <typename T>
void List<T>::Clear() {
    ListPointer deletable;
    while (head != nullptr) {
        deletable = head;
        head = head->NextNode;
        delete deletable;
    }
    count = 0;
}

template <typename T>
unsigned int List<T>::Size() {
    return count;
}

template <typename T>
void List<T>::Reverse() {
    ListPointer p = head;
    ListPointer q = nullptr;
    while (p != nullptr) {
        head = p;
        p = p->NextNode;
        head->NextNode = q;
        q = head;
    }
}

template <typename T>
void List<T>::SetPosition(int pos, ListPointer& current) {
    current = head;
    for (int i = 2; i <= pos; i++)
        current = current->NextNode;
}

template <typename T>
List<T>::ListIterator::ListIterator(typename List<T>::ListPointer listPointer):
    listPointer(listPointer)
{}

template <typename T>
T& List<T>::ListIterator::operator*() {
    return listPointer->Entry;
}

template <typename T>
typename List<T>::ListIterator& List<T>::ListIterator::operator++() {
    listPointer = listPointer->NextNode;
    return *this;
}

template <typename T>
bool List<T>::ListIterator::operator!=(const typename List<T>::ListIterator& other) const {
    return listPointer != other.listPointer;
}

template <typename T>
typename List<T>::ListIterator List<T>::begin() {
    return ListIterator(head);
}

template <typename T>
typename List<T>::ListIterator List<T>::end() {
    return ListIterator(nullptr);
}