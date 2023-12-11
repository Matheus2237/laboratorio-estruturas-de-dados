#include "OrderedList.h"
#include <stdexcept>

OrderedList::OrderedList() {
    sentinel = new ListNode;
    if (sentinel == nullptr)
        throw std::bad_alloc();
    head = sentinel;
    count = 0;
}

OrderedList::~OrderedList() {
    ListPointer disposable;
    while (head != sentinel) {
        disposable = head;
        head = head->NextNode;
        delete disposable;
    }
    delete sentinel;
}

bool OrderedList::Empty() {
    return head == sentinel;
}

bool OrderedList::Full() {
    return false;
}

void OrderedList::Insert(int entry) {
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

void OrderedList::Delete(int entry) {
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

int OrderedList::Search(int entry) {
    if (Empty())
        throw std::out_of_range("Lista vazia!");
    sentinel->Entry = entry;
    int position = 1;
    ListPointer q = head;
    while (q->Entry < entry) {
        q = q->NextNode;
        ++position;
    }
    if (q->Entry != entry || q == sentinel)
        return 0;
    return position;
}

void OrderedList::Clear() {
    ListPointer disposable;
    while (head != sentinel) {
        disposable = head;
        head = head->NextNode;
        delete head;
    }
    count = 0;
}

int OrderedList::Size() {
    return count;
}

bool OrderedList::SearchInsert(int entry) {
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

OrderedList::Iterator::Iterator(ListPointer current): current(current) {}

OrderedList::Iterator& OrderedList::Iterator::operator++() {
    if (current)
        current = current->NextNode;
    return *this;
}

OrderedList::Iterator OrderedList::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

int OrderedList::Iterator::operator*() {
    return current ? current->Entry : 0;
}

bool OrderedList::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

bool OrderedList::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

OrderedList::Iterator OrderedList::begin() {
    return Iterator(head);
}

OrderedList::Iterator OrderedList::end() {
    return Iterator(sentinel);
}