#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "BinaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
private:
    struct TreeNode {
        T entry;
        TreeNode* leftSubTree;
        TreeNode* rightSubTree;
    };
    typedef TreeNode* TreePointer;
    TreePointer root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void clear() override;
    bool empty() const override;
    bool full() const override;
    unsigned int nodes() const override;
    unsigned int leaves() const override;
    int height() const override;
    T minimum() const override;
    T maximum() const override;
    bool search(const T value) const override;
    void insert(const T value) override;
    void deleteValue(const T value) override;
    void preOrder(const std::function<void(T)>& process) const override;
    void inOrder(const std::function<void(T)>& process) const override;
    void postOrder(const std::function<void(T)>& process) const override;


    void printTree() override;

private:
    void preOrder(TreePointer t, const std::function<void(T)>& process) const;
    void inOrder(TreePointer t, const std::function<void(T)>& process) const;
    void postOrder(TreePointer t, const std::function<void(T)>& process) const;
    void clear(TreePointer t);
    unsigned int nodes(const TreePointer& t) const;
    unsigned int leaves(const TreePointer& t) const;
    int height(const TreePointer& t) const;
    bool search(const T value, const TreePointer& t) const;
    void deleteValue(const T value, TreePointer& t);
    void deleteMaximumValue(TreePointer& q, TreePointer& r);


    void printTree(TreePointer &t, int s);
};

#include "BinarySearchTree.cpp"

#endif