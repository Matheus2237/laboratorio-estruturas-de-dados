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
    int Size();
    void Insert(int position, int entry);
    void printBackwards() const;
    void remove_valor(int x);

private:
    void SetPosition(int position, ListPointer& current);
    void printBackwards(ListPointer node) const;
    ListPointer removeNode(int x, ListPointer node);
};

#endif