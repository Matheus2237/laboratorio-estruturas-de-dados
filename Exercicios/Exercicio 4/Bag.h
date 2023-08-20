#ifndef BAG_H
#define BAG_H
#define CAPACITY 20

class Bag{
private:
    int data[CAPACITY+1];
    int used;

public:
    Bag();
    void insert(int entry);
    int occurrence(int value);
    void remove(int value);
    bool full();
};

#endif