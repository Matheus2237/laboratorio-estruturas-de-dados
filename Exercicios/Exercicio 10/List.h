#ifndef LIST_H
#define LIST_H

class List {
private:
    struct ListNode {
        int Entry;
        ListNode* NextNode;
    };
    typedef ListNode* ListPointer;
    ListPointer head;
    int count;

public:
    List();
    ~List();
    bool Empty();
    bool Full();
    void Insert(int pos, int entry);
    void Delete(int pos, int& entry);
    void Retrieve(int pos, int& entry);
    void Replace(int pos, int entry);
    bool searchBiggestValue(int& pos, int& entry);
    void Clear();
    int Size();
    void minimum(int& pos, int& entry);
    void Reverse();
    bool swapElements(int pos, int oPos);

    class ListIterator {
        private:
            ListPointer listPointer;
        
        public:
            ListIterator(ListPointer listPointer);
            int& operator*();
            ListIterator& operator++();
            bool operator!=(const ListIterator& other) const;
    };

    ListIterator begin();
    ListIterator end();

private:
    void SetPosition(int pos, ListPointer& current);
};

#endif