#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

class OrderedList {
private:
    struct ListNode {
        int Entry;
        ListNode* NextNode;
    };
    typedef ListNode* ListPointer;
    ListPointer head;
    ListPointer sentinel;
    int count;

public:
    OrderedList();
    ~OrderedList();
    void Insert(int entry);
    void Delete(int entry);
    int Search(int entry);
    bool SearchInsert(int entry);
    bool Empty();
    bool Full();
    void Clear();
    int Size();
    
    class Iterator {
    private:
        ListPointer current;

    public:
        Iterator(ListPointer current);
        Iterator& operator++();
        Iterator operator++(int);
        int operator*();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
};

#endif