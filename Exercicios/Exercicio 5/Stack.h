#ifndef STACK_H
#define STACK_H

const int MAX_ELEMENTS = 100;

class Stack {
private:
    int top_position;
    int entries[MAX_ELEMENTS+1];

public:
    Stack();
    ~Stack();
    void push(int entry);
    void pop(int &entry);
    void top(int &entry);
    bool full();
    bool empty();
    unsigned int size();
};

#endif