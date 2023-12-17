#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    struct QueueNode {
        T Entry;
        QueueNode* NextNode;
    };
    typedef QueueNode* QueuePointer;
    QueuePointer head;
    QueuePointer tail;
    unsigned int count;

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