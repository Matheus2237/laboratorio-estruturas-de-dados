#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree {
private:
    struct TreeNode {
        int entry;
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
    int nodes() const override;
    int leaves() const override;
    int height() const override;
    int minimum() const override;
    int maximum() const override;
    bool search(const int value) const override;
    void insert(const int value) override;
    void deleteValue(const int value) override;
    void preOrder(const std::function<void(int)>& process) const override;
    void inOrder(const std::function<void(int)>& process) const override;
    void postOrder(const std::function<void(int)>& process) const override;

private:
    void preOrder(TreePointer t, const std::function<void(int)>& process) const;
    void inOrder(TreePointer t, const std::function<void(int)>& process) const;
    void postOrder(TreePointer t, const std::function<void(int)>& process) const;
    void clear(TreePointer t);
    int nodes(const TreePointer& t) const;
    int leaves(const TreePointer& t) const;
    int height(const TreePointer& t) const;
    bool search(const int value, const TreePointer& t) const;
    void deleteValue(const int value, TreePointer& t);
    void deleteMaximumValue(TreePointer& q, TreePointer& r);
};

#endif