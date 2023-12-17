#ifndef QUEUE_H
#define QUEUE_H

template <typename T, unsigned int capacity>
class Queue {
private:
    const unsigned int MAX_QUEUE;
    T Entry[capacity + 1];
    unsigned int count;
    unsigned int head;
    unsigned int tail;

public:
    Queue();
    ~Queue();
    bool Empty();
    bool Full();
    void Append(T entry);
    void Serve(T& entry);
    void Front(T& entry);
    void Rear(T& entry);
    void ClearSE();
    void ClearCO();
    unsigned int Size();
};

#include "Queue.cpp"

#endif