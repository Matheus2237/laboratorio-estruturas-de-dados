#ifndef LIST_H
#define LIST_H

template <typename T, unsigned int capacity>
class List {
private:
    const unsigned int MAX_LIST;
    T Entry[capacity+1];
    unsigned int count;

public:
    List();
    ~List();
    bool Empty();
    bool Full();
    void Insert(int pos, T entry);
    void Delete(int pos, T& entry);
    void Retrieve(int pos, T& entry);
    void Replace(int pos, T entry);
    void Clear();
    unsigned int Size();
};

#include "List.cpp"

#endif