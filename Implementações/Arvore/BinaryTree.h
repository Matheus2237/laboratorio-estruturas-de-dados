#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <functional>

template <typename T>
class BinaryTree {

    static_assert(std::is_arithmetic<T>::value && !std::is_same<T, bool>::value && !std::is_same<T, char>::value, "Classe aceita apenas tipos numericos");

public:
    BinaryTree() = default;
    ~BinaryTree() = default;
    virtual void clear() = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual unsigned int nodes() const = 0;
    virtual unsigned int leaves() const = 0;
    virtual int height() const = 0;
    virtual T minimum() const = 0;
    virtual T maximum() const = 0;
    virtual bool search(const T value) const = 0;
    virtual void insert(const T value) = 0;
    virtual void deleteValue(const T value) = 0;
    virtual void preOrder(const std::function<void(T)>& process) const = 0;
    virtual void inOrder(const std::function<void(T)>& process) const = 0;
    virtual void postOrder(const std::function<void(T)>& process) const = 0;
};

#endif