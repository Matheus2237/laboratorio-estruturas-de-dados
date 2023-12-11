#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <functional>

class BinaryTree {
public:
    BinaryTree() = default;
    ~BinaryTree() = default;
    virtual void clear() = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual int nodes() const = 0;
    virtual int leaves() const = 0;
    virtual int height() const = 0;
    virtual int minimum() const = 0;
    virtual int maximum() const = 0;
    virtual bool search(const int value) const = 0;
    virtual void insert(const int value) = 0;
    virtual void deleteValue(const int value) = 0;
    virtual void preOrder(const std::function<void(int)>& process) const = 0;
    virtual void inOrder(const std::function<void(int)>& process) const = 0;
    virtual void postOrder(const std::function<void(int)>& process) const = 0;
};

#endif