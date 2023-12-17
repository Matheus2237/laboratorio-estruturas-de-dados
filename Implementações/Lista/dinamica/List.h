#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
private:
    struct ListNode {
        T Entry;
        ListNode* NextNode;
    };
    typedef ListNode* ListPointer;
    ListPointer head;
    unsigned int count;

public:
    List();
    ~List();
    bool Empty();
    bool Full();
    void Insert(int pos, T entry);
    void Delete(int pos, T& entry);
    void Retrieve(int pos, T& entry);
    void Replace(int pos, T entry);
    void Clear();
    unsigned int Size();
    void Reverse();

    class ListIterator {
        private:
            ListPointer listPointer;
        
        public:
            ListIterator(ListPointer listPointer);
            T& operator*();
            ListIterator& operator++();
            bool operator!=(const ListIterator& other) const;
    };

    ListIterator begin();
    ListIterator end();

private:
    void SetPosition(int pos, ListPointer& current);
};

#include "List.cpp"

#endif