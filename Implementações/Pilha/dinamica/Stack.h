#ifndef STACK_H
#define STACK_H

class Stack {
    private:
        struct StackNode {
            int data;
            StackNode* nextNode;
        };
        StackNode* topNode;
        int elementCounter;

    public:
        Stack();
        ~Stack();
        bool empty();
        bool full();
        void push(int entry);
        void pop(int& entry);
        void clearEP();
        void clearPt();
        void topPPE(int& entry);
        void topPt(int& entry);
        int size();
        int sizeOpt();
};

#endif