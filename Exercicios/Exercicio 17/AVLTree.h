#ifndef AVL_TREE_H
#define AVL_TREE_H

class AVLTree {
private:
    struct TreeNode {
        int entry;
        int bal;
        int count;
        TreeNode* leftSubTree;
        TreeNode* rightSubTree;
    };
    typedef TreeNode* TreePointer;
    TreePointer root;

public:
    AVLTree();
    void insert(const int entry);
    void print();

private:
    void print(TreePointer &t, int s);
    void insert(const int entry, TreePointer& current, bool& height);
    void rebalanceAfterLeftInsertion(TreePointer& current, bool& height);
    void rebalanceAfterRightInsertion(TreePointer& current, bool& height);
    void rotateLL(TreePointer& pA, TreePointer& pB);
    void rotateLR(TreePointer& pA, TreePointer& pB, TreePointer& pC);
    void rotateRR(TreePointer& pA, TreePointer& pB);
    void rotateRL(TreePointer& pA, TreePointer& pB, TreePointer& pC);
};

#endif