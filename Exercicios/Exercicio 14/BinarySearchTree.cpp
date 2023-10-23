#include "BinarySearchTree.h"
#include <iomanip>
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = new TreeNode;
    root->Entry = 8;

    root->LeftNode = new TreeNode;
    root->LeftNode->Entry = 3;
    root->RightNode = new TreeNode;
    root->RightNode->Entry = 12;
    
    root->LeftNode->LeftNode = new TreeNode;
    root->LeftNode->LeftNode->Entry = 2;
    root->LeftNode->LeftNode->RightNode = NULL;
    root->LeftNode->RightNode = new TreeNode;
    root->LeftNode->RightNode->Entry = 5;
    root->LeftNode->RightNode->LeftNode = NULL;
    root->LeftNode->RightNode->RightNode = NULL;

    root->LeftNode->LeftNode->LeftNode = new TreeNode;
    root->LeftNode->LeftNode->LeftNode->Entry = 1;
    root->LeftNode->LeftNode->LeftNode->LeftNode = NULL;
    root->LeftNode->LeftNode->LeftNode->RightNode = NULL;

    root->RightNode->LeftNode = new TreeNode;
    root->RightNode->LeftNode->Entry = 10;
    root->RightNode->RightNode = new TreeNode;
    root->RightNode->RightNode->Entry = 15;
    root->RightNode->RightNode->LeftNode = NULL;
    root->RightNode->RightNode->RightNode = NULL;

    root->RightNode->LeftNode->LeftNode = new TreeNode;
    root->RightNode->LeftNode->RightNode = NULL;
    root->RightNode->LeftNode->LeftNode->Entry = 9;
    root->RightNode->LeftNode->LeftNode->LeftNode = NULL;
    root->RightNode->LeftNode->LeftNode->RightNode = NULL;
}

void BinarySearchTree::PreOrder(){
    PreOrder(root);
}

void BinarySearchTree::PreOrder(TreePointer r){
    if(r == NULL) return;

    cout << r->Entry <<" ";
    PreOrder(r->LeftNode);
    PreOrder(r->RightNode);
}

void BinarySearchTree::InOrder(){
    InOrder(root);
}

void BinarySearchTree::InOrder(TreePointer r){
    if(r == NULL) return;

    InOrder(r->LeftNode);
    cout << r->Entry << " ";
    InOrder(r->RightNode);
}

void BinarySearchTree::PostOrder(){
    PostOrder(root);
}

void BinarySearchTree::PostOrder(TreePointer r){
    if(r == NULL) return;

    PostOrder(r->LeftNode);
    PostOrder(r->RightNode);
    cout << r->Entry << " ";
}

int BinarySearchTree::Nodes(){
    return Nodes(root);
}

int BinarySearchTree::Nodes(TreePointer r){
    if(r == NULL) return 0;

    return 1 + Nodes(r->LeftNode) + Nodes(r->RightNode);
}

void BinarySearchTree::Print(){
    Print(root, 0);
}

void BinarySearchTree::Print(TreePointer &t, int s){
    int i;
    if(t!=NULL){
        Print(t->RightNode, s+3);
        for(i=1; i<=s; i++)
            cout << " ";
        cout << setw(6) <<t->Entry <<endl;
        Print(t->LeftNode, s+3);
    }
}

int BinarySearchTree::Leaves() {
    return Leaves(root);
}

int BinarySearchTree::Leaves(TreePointer r) {
    if (r == NULL)
        return 0;
    else if (r->LeftNode == NULL && r->LeftNode == NULL)
        return 1;
    else
        return Leaves(r->LeftNode) + Leaves(r->RightNode);
}