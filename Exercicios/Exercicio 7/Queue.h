#ifndef QUEUE_H
#define QUEUE_H

const int MaxQueue = 100;

class Queue {
private:
    int counter;
    int tail;
    int head;
    int entries[MaxQueue+1];

public:
    Queue();
    ~Queue();
    void append(int entry);
    void serve(int& entry);
    bool empty();
    bool full();
    void front(int& entry);
    void rear(int& entry);
    int size();
    void clear();
};

#endif