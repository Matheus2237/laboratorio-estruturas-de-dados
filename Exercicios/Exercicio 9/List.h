#ifndef LIST_H
#define LIST_H

class List {
private:
    struct ListNode {
        int entry;
        ListNode* nextNode;
    };
    typedef ListNode* ListPointer;
    int counter;
    ListPointer head;

public:
    List();
    ~List();
    bool Empty();
    bool Full();
    void Insert(int position, int entry);
    void Delete(int position, int& entry);
    int Size();
    void Retrieve(int position, int& entry);
    void Clear();
    void Replace(int position, int entry);

private:
    void SetPosition(int position, ListPointer& current);
};

#endif