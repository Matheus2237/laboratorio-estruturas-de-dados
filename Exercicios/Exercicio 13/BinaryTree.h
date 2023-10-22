#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {
private:
    struct TreeNode{
        char Entry;
        TreeNode* LeftNode;
        TreeNode* RightNode;
    };
    typedef TreeNode* TreePointer;
    TreePointer root;

public:
    BinaryTree();
    //~BinaryTree();
    void PreOrder();
    void InOrder();
    void PostOrder();
    int Nodes();
    int Leaves();

private:
    void PreOrder(TreePointer r);
    void InOrder(TreePointer r);
    void PostOrder(TreePointer r);
    int Nodes(TreePointer r);
    int Leaves(TreePointer r);
};

#endif