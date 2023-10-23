#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(){
    root = new TreeNode;
    root->Entry = 'A';

    root->LeftNode = new TreeNode;
    root->LeftNode->Entry = 'B';
    root->RightNode = new TreeNode;
    root->RightNode->Entry = 'C';
    
    root->LeftNode->LeftNode = new TreeNode;
    root->LeftNode->LeftNode->Entry = 'D';
    root->LeftNode->LeftNode->RightNode = NULL;
    root->LeftNode->RightNode = new TreeNode;
    root->LeftNode->RightNode->Entry = 'E';
    root->LeftNode->RightNode->LeftNode = NULL;
    root->LeftNode->RightNode->RightNode = NULL;

    root->LeftNode->LeftNode->LeftNode = new TreeNode;
    root->LeftNode->LeftNode->LeftNode->Entry = 'H';
    root->LeftNode->LeftNode->LeftNode->LeftNode = NULL;
    root->LeftNode->LeftNode->LeftNode->RightNode = NULL;

    root->RightNode->LeftNode = new TreeNode;
    root->RightNode->LeftNode->Entry = 'F';
    root->RightNode->RightNode = new TreeNode;
    root->RightNode->RightNode->Entry = 'G';
    root->RightNode->RightNode->LeftNode = NULL;
    root->RightNode->RightNode->RightNode = NULL;

    root->RightNode->LeftNode->LeftNode = new TreeNode;
    root->RightNode->LeftNode->RightNode = NULL;
    root->RightNode->LeftNode->LeftNode->Entry = 'I';
    root->RightNode->LeftNode->LeftNode->LeftNode = NULL;
    root->RightNode->LeftNode->LeftNode->RightNode = NULL;
}

void BinaryTree::PreOrder() {
    PreOrder(root);
}

void BinaryTree::PreOrder(TreePointer r) {
    if (r == NULL)
        return;
    std::cout << r->Entry << " ";
    PreOrder(r->LeftNode);
    PreOrder(r->RightNode);
}

void BinaryTree::InOrder() {
    InOrder(root);
}

void BinaryTree::InOrder(TreePointer r) {
    if (r == NULL)
        return;
    InOrder(r->LeftNode);
    std::cout << r->Entry << " ";
    InOrder(r->RightNode);
}

void BinaryTree::PostOrder() {
    PostOrder(root);
}

void BinaryTree::PostOrder(TreePointer r) {
    if (r == NULL)
        return;
    PostOrder(r->LeftNode);
    std::cout << r->Entry << " ";
    PostOrder(r->RightNode);
}

int BinaryTree::Nodes() {
    return Nodes(root);
}

int BinaryTree::Nodes(TreePointer r) {
    if (r == NULL)
        return;
    return 1 + Nodes(r->LeftNode) + Nodes(r->RightNode);
}

int BinaryTree::Leaves() {
    return Leaves(root);
}

int BinaryTree::Leaves(TreePointer r) {
    if (r == NULL)
        return 0;
    else if (r->LeftNode == NULL && r->LeftNode == NULL)
        return 1;
    else
        return Leaves(r->LeftNode) + Leaves(r->RightNode);
}