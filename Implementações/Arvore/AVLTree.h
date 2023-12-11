#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "BinaryTree.h"

class AVLTree : public BinaryTree {
private:
    struct TreeNode {
        int entry;
        int count;
        int bal;
        TreeNode* leftSubTree;
        TreeNode* rightSubTree;
    };
    typedef TreeNode* TreePointer;
    TreePointer root;

public:
    AVLTree();
    ~AVLTree();
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
    int allOcurrencesOfNodes() const;
    int allOcurrencesOfLeaves() const;
    int allOcurrencesOfMinimum() const;
    int allOcurrencesOfMaximum() const;
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
    void insertValue(const int value, TreePointer& pA, bool& height);
    void deleteValue(const int value, TreePointer& t, bool& h);
    void deleteMinimumValue(TreePointer& q, TreePointer& r, bool& height);
    void balanceLeftSideAfterDeletion(TreePointer& pA, bool& height);
    void balanceRightSideAfterDeletion(TreePointer& pA, bool& height);
    int allOcurrencesOfNodes(const TreePointer& t) const;
    int allOcurrencesOfLeaves(const TreePointer& t) const;
};

#endif