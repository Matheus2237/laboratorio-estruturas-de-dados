#ifndef LIST_H
#define LIST_H

const int MaxList = 100;

class List {
private:
    int Entry[MaxList+1];
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
    void Clear();
    int Size();
};

#endif