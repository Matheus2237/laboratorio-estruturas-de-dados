#include "Bag.h"
#include <stdexcept>

Bag::Bag() {
    this->used = 0;
}

void Bag::insert(int entry) {
    if(this->full())
        throw std::out_of_range("Array já cheio");
    this->used++;
    this->data[used] = entry;
}

int Bag::occurrence(int value) {
    int occurrence = 0;
    for (int i = 1; i <= this->used; i++)
        if (this->data[i] == value)
            occurrence++;
    return occurrence;
}

void Bag::remove(int value) {
    int position = 1;
    while (position <= CAPACITY+1 && this->data[position] != value)
        position++;
    
    if(position > CAPACITY+1)
        throw std::out_of_range("Numero invalido");

    this->used--;
    for (int j = position; j <= this->used; j++)
        this->data[j] = this->data[j+1];
}

bool Bag::full() {
    return this->used == CAPACITY+1;
}