#ifndef STACK_H
#define STACK_H

template <typename T, unsigned int capacity>
class Stack {
    private:
        const unsigned int MAX_QUANTITY;
        T entries[capacity+1];
        unsigned int top_position;

    public:
        Stack();
        ~Stack();
        void push(T entry);
        void pop(T& entry);
        void clearEP();
        void clearVT();
        void topPPE(T& entry);
        void topVT(T& entry);
        bool full();
        bool empty();
        unsigned int size();
};

#include "Stack.cpp"

#endif