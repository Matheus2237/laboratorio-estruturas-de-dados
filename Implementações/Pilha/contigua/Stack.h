#ifndef STACK_H
#define STACK_H

#define MAX_QUANTITY 100

class Stack {
    private:
        int entries[MAX_QUANTITY+1];
        int top_position;

    public:
        Stack();
        ~Stack();
        void push(int entry);
        void pop(int& entry);
        void clearEP();
        void clearVT();
        void topPPE(int& entry);
        void topVT(int& entry);
        bool full();
        bool empty();
        unsigned int size();
};

#endif