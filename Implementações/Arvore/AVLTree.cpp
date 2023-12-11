#include "AVLTree.h"
#include <iostream>
#include <stdexcept>

AVLTree::AVLTree():
    root(nullptr)
{}

AVLTree::~AVLTree() {
    this->clear(root);
}

void AVLTree::clear() {
    this->clear(root);
}

void AVLTree::clear(TreePointer t) {
    if (t == nullptr)
        return;
    this->clear(t->leftSubTree);
    this->clear(t->rightSubTree);
    delete t;
}

bool AVLTree::empty() const {
    return root == nullptr;
}

bool AVLTree::full() const {
    return false;
}

int AVLTree::nodes() const {
    return this->nodes(root);
}

int AVLTree::nodes(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    return 1 + this->nodes(t->leftSubTree) + this->nodes(t->rightSubTree);
}

int AVLTree::leaves() const {
    this->leaves(root);
}

int AVLTree::leaves(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    else if (t->leftSubTree == nullptr && t->rightSubTree == nullptr)
        return 1;
    else
        return this->leaves(t->rightSubTree) + this->leaves(t->rightSubTree);
}

int AVLTree::height() const {
    return this->height(root);
}

int AVLTree::height(const TreePointer& t) const {
    if (t == nullptr)
        return -1;
    int left = this->height(t->leftSubTree);
    int right = this->height(t->rightSubTree);
    return left > right ? left + 1 : right + 1;
}
    
int AVLTree::minimum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia");
    while (t->leftSubTree != nullptr)
        t = t->leftSubTree;
    return t->entry;
}

int AVLTree::maximum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia");
    while (t->rightSubTree != nullptr)
        t = t->rightSubTree;
    return t->entry;
}

bool AVLTree::search(const int value) const {
    return this->search(value, root);
}

bool AVLTree::search(const int value, const TreePointer& t) const {
    if (t == nullptr)
        return false;
    else if (value < t->entry)
        return this->search(value, t->leftSubTree);
    else if (value > t->entry)
        return this->search(value, t->rightSubTree);
    else
        return true;
}

void AVLTree::insert(const int value) {
    bool height = false;
    this->insertValue(value, root, height);
}

void AVLTree::insertValue(const int value, TreePointer& pA, bool& h) {
    TreePointer pB;
    TreePointer pC;
    if (pA == nullptr) {
        pA = new TreeNode;
        pA->entry = value;
        pA->count = 1;
        pA->bal = 0;
        pA->leftSubTree = nullptr;
        pA->rightSubTree = nullptr;
        h = true;
    } else if (value < pA->entry) {
        insertValue(value, pA->leftSubTree, h);
        if (h) {
            switch (pA->bal) {
            case -1:
                pA->bal = 0;
                h = false;
                break;
            case 0:
                pA->bal = 1;
                break;
            case 1:
                pB = pA->leftSubTree;
                if (pB->bal == 1) {
                    pA->leftSubTree = pB->rightSubTree;
                    pB->rightSubTree = pA;
                    pA->bal = 0;
                    pA = pB;
                } else {
                    pC = pB->rightSubTree;
                    pB->rightSubTree = pC->leftSubTree;
                    pC->leftSubTree = pB;
                    pA->leftSubTree = pC->rightSubTree;
                    pC->rightSubTree = pA;
                    pA->bal = pC->bal == 1 ? -1 : 0;
                    pB->bal = pC->bal == -1 ? 1 : 0;
                    pA = pC;
                }
                pA->bal = 0;
                h = false;
                break;
            default:
                break;
            }
        }
    } else if (value > pA->entry) {
        insertValue(value, pA->rightSubTree, h);
        if (h) {
            switch (pA->bal) {
            case 1:
                pA->bal = 0;
                h = false;
                break;
            case 0:
                pA->bal = -1;
                break;
            case -1:
                pB = pA->rightSubTree;
                if (pB->bal == -1) {
                    pA->rightSubTree = pB->leftSubTree;
                    pB->leftSubTree = pA;
                    pA = 0;
                    pA = pB;
                } else {
                    pC = pB->leftSubTree;
                    pB->leftSubTree = pC->rightSubTree;
                    pC->rightSubTree = pB;
                    pA->rightSubTree = pC->leftSubTree;
                    pC->leftSubTree = pA;
                    pA->bal = pC->bal == -1 ? 1 : 0;
                    pB->bal = pC->bal == 1 ? -1 : 0;
                    pA = pC;
                }
                pA->bal = 0;
                h = false;
                break;
            default:
                break;
            }
        }
    } else {
        pA->count++;
    }
}

void AVLTree::deleteValue(const int value) {
    bool height = false;
    deleteValue(value, root, height);
}

void AVLTree::deleteValue(const int value, TreePointer& t, bool& height) {
    if (t == nullptr) {
        std::cout << "Elemento inexistente!" << std::endl;
        return;
    } else if (value < t->entry) {
        deleteValue(value, t->leftSubTree, height);
        if (height)
            balanceLeftSideAfterDeletion(t, height);
    } else if (value > t->entry) {
        deleteValue(value, t->rightSubTree, height);
        if (height)
            balanceRightSideAfterDeletion(t, height);
    } else if (t->count > 1) {
        t->count--;
    } else {
        TreePointer q = t;
        if (q->rightSubTree == nullptr) {
            t = q->leftSubTree;
            height = true;
        } else if (q->leftSubTree == nullptr) {
            t = q->rightSubTree;
            height = true;
        } else {
            deleteMinimumValue(q, q->rightSubTree, height);
            if (height)
                balanceRightSideAfterDeletion(t, height);
        }
        delete q;
    }
}

void AVLTree::deleteMinimumValue(TreePointer& q, TreePointer& r, bool& height) {
    if (r->leftSubTree != nullptr) {
        deleteMinimumValue(q, r->leftSubTree, height);
        if (height)
            balanceLeftSideAfterDeletion(r, height);
    } else {
        q->entry = r->entry;
        q->count = r->count;
        q = r;
        r = r->rightSubTree;
        height = true;
    }
}

void AVLTree::balanceLeftSideAfterDeletion(TreePointer &pA, bool& height) {
    switch (pA->bal) {
    case 1:{
        pA->bal = 0;
        height = false;
        break;
    }
    case 0:{
        pA->bal = -1;
        break;
    }
    case -1: {
        TreePointer pB = pA->rightSubTree;
        if (pB->bal <= 0) {
            pA->rightSubTree = pB->leftSubTree;
            pB->leftSubTree = pA;
            if (pB->bal == 0) {
                pA->bal = -1;
                pB->bal = 1;
                height = false;
            } else {
                pA->bal = 0;
                pB->bal = 0;
            }
            pA = pB;
        } else {
            TreePointer pC = pB->leftSubTree;
            pB->leftSubTree = pC->rightSubTree;
            pC->rightSubTree = pB;
            pA->rightSubTree = pC->leftSubTree;
            pC->leftSubTree = pA;
            pA->bal = pC->bal == -1 ? 1 : 0;
            pB->bal = pC->bal == 1 ? -1 : 0;
            pA = pC;
            pC->bal = 0;
        }
    }
    default:
        break;
    }
}

void AVLTree::balanceRightSideAfterDeletion(TreePointer& pA, bool& height) {
    switch (pA->bal) {
    case -1:{
        pA->bal = 0;
        height = false;
        break;
    }
    case 0:{
        pA->bal = 1;
        break;
    }
    case 1: {
        TreePointer pB = pA->leftSubTree;
        if (pB->bal >= 0) {
            pA->leftSubTree = pB->rightSubTree;
            pB->rightSubTree = pA;
            if (pB->bal == 0) {
                pA->bal = 1;
                pB->bal = -1;
                height = false;
            } else {
                pA->bal = 0;
                pB->bal = 0;
            }
            pA = pB;
        } else {
            TreePointer pC = pB->rightSubTree;
            pB->rightSubTree = pC->leftSubTree;
            pC->leftSubTree = pB;
            pA->leftSubTree = pC->rightSubTree;
            pC->rightSubTree = pA;
            pA->bal = pC->bal == 1 ? -1 : 0;
            pB->bal = pC->bal == -1 ? 1 : 0;
            pA = pC;
            pC->bal = 0;
        }
    }
    default:
        break;
    }
}

int AVLTree::allOcurrencesOfNodes() const {
    return this->allOcurrencesOfNodes(root);
}

int AVLTree::allOcurrencesOfNodes(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    return t->count + this->allOcurrencesOfNodes(t->leftSubTree) + this->allOcurrencesOfNodes(t->rightSubTree);
}

int AVLTree::allOcurrencesOfLeaves() const {
    return this->allOcurrencesOfLeaves(root);
}

int AVLTree::allOcurrencesOfLeaves(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    else if (t->leftSubTree == nullptr && t->rightSubTree == nullptr)
        return t->count;
    else
        return this->allOcurrencesOfLeaves(t->leftSubTree) + this->allOcurrencesOfLeaves(t->leftSubTree);
}

int AVLTree::allOcurrencesOfMinimum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia");
    while (t->leftSubTree != nullptr)
        t = t->leftSubTree;
    return t->count;
}

int AVLTree::allOcurrencesOfMaximum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia");
    while (t->rightSubTree != nullptr)
        t = t->rightSubTree;
    return t->count;
}

void AVLTree::preOrder(const std::function<void(int)>& process) const {
    this->preOrder(root, process);
}

void AVLTree::preOrder(TreePointer t, const std::function<void(int)>& process) const {
    if (t == nullptr) return;
    process(t->entry);
    this->preOrder(t->leftSubTree, process);
    this->preOrder(t->rightSubTree, process);
}

void AVLTree::inOrder(const std::function<void(int)>& process) const {
    this->inOrder(root, process);
}

void AVLTree::inOrder(TreePointer t, const std::function<void(int)>& process) const {
    if (t == nullptr) return;
    this->inOrder(t->leftSubTree, process);
    process(t->entry);
    this->inOrder(t->rightSubTree, process);
}

void AVLTree::postOrder(const std::function<void(int)>& process) const {
    this->postOrder(root, process);
}

void AVLTree::postOrder(TreePointer t, const std::function<void(int)>& process) const {
    if (t == nullptr) return;
    this->postOrder(t->leftSubTree, process);
    this->postOrder(t->rightSubTree, process);
    process(t->entry);
}