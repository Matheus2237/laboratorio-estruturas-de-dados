#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

#include <type_traits>

template <typename T>
class OrderedList {

    static_assert(std::is_arithmetic<T>::value && !std::is_same<T, bool>::value && !std::is_same<T, char>::value, "Classe aceita apenas tipos numericos");

private:
    struct ListNode {
        T Entry;
        ListNode* NextNode;
    };
    typedef ListNode* ListPointer;
    ListPointer head;
    ListPointer sentinel;
    unsigned int count;

public:
    OrderedList();
    ~OrderedList();
    void Insert(T entry);
    void Delete(T entry);
    unsigned int Search(T entry);
    bool SearchInsert(T entry);
    bool Empty();
    bool Full();
    void Clear();
    unsigned int Size();
    
    class Iterator {
    private:
        ListPointer current;

    public:
        Iterator(ListPointer current);
        Iterator& operator++();
        Iterator operator++(int);
        T operator*();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
};

#include "OrderedList.cpp"

#endif