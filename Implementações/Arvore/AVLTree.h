#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "BinaryTree.h"

template <typename T>
class AVLTree : public BinaryTree<T> {
private:
    struct TreeNode {
        T entry;
        unsigned int count;
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
    unsigned int nodes() const override;
    unsigned int leaves() const override;
    int height() const override;
    T minimum() const override;
    T maximum() const override;
    bool search(const T value) const override;
    void insert(const T value) override;
    void deleteValue(const T value) override;
    unsigned int allOcurrencesOfNodes() const;
    unsigned int allOcurrencesOfLeaves() const;
    unsigned int allOcurrencesOfMinimum() const;
    unsigned int allOcurrencesOfMaximum() const;
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
    void insertValue(const T value, TreePointer& pA, bool& height);
    void deleteValue(const T value, TreePointer& t, bool& h);
    void deleteMinimumValue(TreePointer& q, TreePointer& r, bool& height);
    void balanceLeftSideAfterDeletion(TreePointer& pA, bool& height);
    void balanceRightSideAfterDeletion(TreePointer& pA, bool& height);
    unsigned int allOcurrencesOfNodes(const TreePointer& t) const;
    unsigned int allOcurrencesOfLeaves(const TreePointer& t) const;
};

#include "AVLTree.cpp"

#endif