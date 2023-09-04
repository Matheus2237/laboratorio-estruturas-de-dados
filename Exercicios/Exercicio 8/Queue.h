#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    struct QueueNode {
        int entry;
        QueueNode* nextNode;
    };
    typedef QueueNode* QueuePointer;
    QueuePointer head;
    QueuePointer tail;

public:
    Queue();
    ~Queue();
    void append(int entry);
    void serve(int& entry);
    bool empty();
    bool full();
    void front(int& entry);
    void rear(int& entry);
    void clear();
    int size();
};

#endif