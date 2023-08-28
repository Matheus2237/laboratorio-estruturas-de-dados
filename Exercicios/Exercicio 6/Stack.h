#ifndef STACK_H
#define STACK_H

class Stack {
private:
    struct StackNode {
        int entry;
        StackNode* nextNode;
    };
    typedef struct StackNode* StackPointer;
    StackPointer topNode;

public:
    Stack();
    ~Stack();
    void push(int entry);
    void pop(int& entry);
    void top(int& entry);
    bool empty();
    bool full();
    int size();
};

#endif