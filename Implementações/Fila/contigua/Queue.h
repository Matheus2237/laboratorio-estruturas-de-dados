#ifndef QUEUE_H
#define QUEUE_H

const int MaxQueue = 100;

class Queue {
private:
    int Entry[MaxQueue+1];
    int count;
    int head;
    int tail;

public:
    Queue();
    ~Queue();
    bool Empty();
    bool Full();
    void Append(int entry);
    void Serve(int& entry);
    void Front(int& entry);
    void Rear(int& entry);
    void ClearSE();
    void ClearCO();
    int Size();
};

#endif