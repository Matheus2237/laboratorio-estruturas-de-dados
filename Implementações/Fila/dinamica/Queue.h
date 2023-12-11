#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    struct QueueNode {
        int Entry;
        QueueNode* NextNode;
    };
    typedef QueueNode* QueuePointer;
    QueuePointer head;
    QueuePointer tail;
    int count;

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