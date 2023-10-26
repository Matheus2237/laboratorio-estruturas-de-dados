#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree{
    public:
    BinarySearchTree();
    //~BinarySearchTree();
    void PreOrder();
    void InOrder();
    void PostOrder();
    int Nodes();
    int Leaves();
    void Print();
    int sumTreeKeys() const;
    void findParentOf(int value);
    void Insert(int x);
    void Delete(int x);

    private:
    
    struct TreeNode{
        int Entry;
        TreeNode* LeftNode;
        TreeNode* RightNode;
    };
    typedef TreeNode* TreePointer;
    TreePointer root;
    void PreOrder(TreePointer r);
    void InOrder(TreePointer r);
    void PostOrder(TreePointer r);
    int Nodes(TreePointer r);
    int Leaves(TreePointer r);
    void Print(TreePointer &r, int s);
    int sumTreeKeys(const TreePointer& t) const;
    void findParentOf(const int value, TreePointer& t, TreePointer& q);
    void showParentSearchResult(const int value, const TreePointer& parent) const;
    void Delete(int x, TreePointer& p);
    void DelMin(TreePointer& q, TreePointer& r);
};

#endif