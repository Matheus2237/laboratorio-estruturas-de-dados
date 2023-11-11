#include "AVLTree.h"
#include <iostream>
#include <iomanip>

AVLTree::AVLTree():
    root(nullptr)
{}

void AVLTree::print(){
    print(root, 0);
}

void AVLTree::print(TreePointer &t, int s){
    int i;
    if(t!=nullptr){
        print(t->rightSubTree, s+3);
        for(i=1; i<=s; i++)
            std::cout << " ";
        std::cout << std::setw(6) << t->entry << std::endl;
        print(t->leftSubTree, s+3);
    }
}

void AVLTree::insert(const int entry) {
    bool height = false;
    insert(entry, root, height);
}

void AVLTree::insert(const int entry, TreePointer& current, bool &height) {
    if (current == nullptr) {
        current = new TreeNode {entry, 0, 1, nullptr, nullptr};
        height = true;
    } else if (entry < current->entry) {
        insert(entry, current->leftSubTree, height);
        if (height)
            rebalanceAfterLeftInsertion(current, height);
    } else if (entry > current->entry) {
        insert(entry, current->rightSubTree, height);
        if (height)
            rebalanceAfterRightInsertion(current, height);
    } else {
        current->count++;
    }
}

void AVLTree::rebalanceAfterLeftInsertion(TreePointer& pA, bool &height) {
    switch (pA->bal) {
        case -1: {
            pA->bal = 0;
            height = false;
            break;
        }
        case 0: {
            pA->bal = 1;
            break;
        }
        case 1: {
            TreePointer pB = pA->leftSubTree;
            if (pB->bal = 1)
                rotateLL(pA, pB);
            else 
                rotateLR(pA, pB, pB->rightSubTree);
            pA->bal = 0;
            height = false;
            break;
        }
        default:
            break;
    }
}

void AVLTree::rebalanceAfterRightInsertion(TreePointer &pA, bool &height) {
    switch (pA->bal) {
        case 1: {
            pA->bal = 0;
            height = false;
            break;
        }
        case 0: {
            pA->bal = -1;
            break;
        }
        case -1: {
            TreePointer pB = pA->rightSubTree;
            if (pB->bal == -1)
                rotateRR(pA, pB);
            else
                rotateRL(pA, pB, pB->leftSubTree);
            height = true;
            pA = 0;
        }
        default:
            break;
    }
}

void AVLTree::rotateLL(TreePointer &pA, TreePointer &pB) {
    pA->leftSubTree = pB->rightSubTree;
    pB->rightSubTree = pA;
    pA->bal = 0;
    pA = pB;
}

void AVLTree::rotateLR(TreePointer &pA, TreePointer &pB, TreePointer &pC) {
    // TODO: Implement method
}

void AVLTree::rotateRR(TreePointer &pA, TreePointer &pB) {
    pA->rightSubTree = pB->leftSubTree;
    pB->leftSubTree = pA;
    pA->bal = 0;
    pA = pB;
}

void AVLTree::rotateRL(TreePointer &pA, TreePointer &pB, TreePointer &pC) {
    // TODO: Implement method
}