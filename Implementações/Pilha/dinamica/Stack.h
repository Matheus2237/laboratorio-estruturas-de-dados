#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
    private:
        struct StackNode {
            T data;
            StackNode* nextNode;
        };
        StackNode* topNode;
        unsigned int elementCounter;

    public:
        Stack();
        ~Stack();
        bool empty();
        bool full();
        void push(T entry);
        void pop(T& entry);
        void clearEP();
        void clearPt();
        void topPPE(T& entry);
        void topPt(T& entry);
        unsigned int size();
        unsigned int sizeOpt();
};

#include "Stack.cpp"

#endif