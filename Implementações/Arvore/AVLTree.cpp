#include "AVLTree.h"
#include <iostream>
#include <stdexcept>

template <typename T>
AVLTree<T>::AVLTree():
    root(nullptr)
{}

template <typename T>
AVLTree<T>::~AVLTree() {
    this->clear(root);
}

template <typename T>
void AVLTree<T>::clear() {
    this->clear(root);
}

template <typename T>
void AVLTree<T>::clear(TreePointer t) {
    if (t == nullptr)
        return;
    this->clear(t->leftSubTree);
    this->clear(t->rightSubTree);
    delete t;
}

template <typename T>
bool AVLTree<T>::empty() const {
    return root == nullptr;
}

template <typename T>
bool AVLTree<T>::full() const {
    return false;
}

template <typename T>
unsigned int AVLTree<T>::nodes() const {
    return this->nodes(root);
}

template <typename T>
unsigned int AVLTree<T>::nodes(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    return 1 + this->nodes(t->leftSubTree) + this->nodes(t->rightSubTree);
}

template <typename T>
unsigned int AVLTree<T>::leaves() const {
    return this->leaves(root);
}

template <typename T>
unsigned int AVLTree<T>::leaves(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    else if (t->leftSubTree == nullptr && t->rightSubTree == nullptr)
        return 1;
    else
        return this->leaves(t->rightSubTree) + this->leaves(t->rightSubTree);
}

template <typename T>
int AVLTree<T>::height() const {
    return this->height(root);
}

template <typename T>
int AVLTree<T>::height(const TreePointer& t) const {
    if (t == nullptr)
        return -1;
    int left = this->height(t->leftSubTree);
    int right = this->height(t->rightSubTree);
    return left > right ? left + 1 : right + 1;
}
    
template <typename T>
T AVLTree<T>::minimum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia");
    while (t->leftSubTree != nullptr)
        t = t->leftSubTree;
    return t->entry;
}

template <typename T>
T AVLTree<T>::maximum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia");
    while (t->rightSubTree != nullptr)
        t = t->rightSubTree;
    return t->entry;
}

template <typename T>
bool AVLTree<T>::search(const T value) const {
    return this->search(value, root);
}

template <typename T>
bool AVLTree<T>::search(const T value, const TreePointer& t) const {
    if (t == nullptr)
        return false;
    else if (value < t->entry)
        return this->search(value, t->leftSubTree);
    else if (value > t->entry)
        return this->search(value, t->rightSubTree);
    else
        return true;
}

template <typename T>
void AVLTree<T>::insert(const T value) {
    bool height = false;
    this->insertValue(value, root, height);
}

template <typename T>
void AVLTree<T>::insertValue(const T value, TreePointer& pA, bool& h) {
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

template <typename T>
void AVLTree<T>::deleteValue(const T value) {
    bool height = false;
    deleteValue(value, root, height);
}

template <typename T>
void AVLTree<T>::deleteValue(const T value, TreePointer& t, bool& height) {
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

template <typename T>
void AVLTree<T>::deleteMinimumValue(TreePointer& q, TreePointer& r, bool& height) {
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

template <typename T>
void AVLTree<T>::balanceLeftSideAfterDeletion(TreePointer &pA, bool& height) {
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

template <typename T>
void AVLTree<T>::balanceRightSideAfterDeletion(TreePointer& pA, bool& height) {
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

template <typename T>
unsigned int AVLTree<T>::allOcurrencesOfNodes() const {
    return this->allOcurrencesOfNodes(root);
}

template <typename T>
unsigned int AVLTree<T>::allOcurrencesOfNodes(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    return t->count + this->allOcurrencesOfNodes(t->leftSubTree) + this->allOcurrencesOfNodes(t->rightSubTree);
}

template <typename T>
unsigned int AVLTree<T>::allOcurrencesOfLeaves() const {
    return this->allOcurrencesOfLeaves(root);
}

template <typename T>
unsigned int AVLTree<T>::allOcurrencesOfLeaves(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    else if (t->leftSubTree == nullptr && t->rightSubTree == nullptr)
        return t->count;
    else
        return this->allOcurrencesOfLeaves(t->leftSubTree) + this->allOcurrencesOfLeaves(t->leftSubTree);
}

template <typename T>
unsigned int AVLTree<T>::allOcurrencesOfMinimum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia");
    while (t->leftSubTree != nullptr)
        t = t->leftSubTree;
    return t->count;
}

template <typename T>
unsigned int AVLTree<T>::allOcurrencesOfMaximum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia");
    while (t->rightSubTree != nullptr)
        t = t->rightSubTree;
    return t->count;
}

template <typename T>
void AVLTree<T>::preOrder(const std::function<void(T)>& process) const {
    this->preOrder(root, process);
}

template <typename T>
void AVLTree<T>::preOrder(TreePointer t, const std::function<void(T)>& process) const {
    if (t == nullptr) return;
    process(t->entry);
    this->preOrder(t->leftSubTree, process);
    this->preOrder(t->rightSubTree, process);
}

template <typename T>
void AVLTree<T>::inOrder(const std::function<void(T)>& process) const {
    this->inOrder(root, process);
}

template <typename T>
void AVLTree<T>::inOrder(TreePointer t, const std::function<void(T)>& process) const {
    if (t == nullptr) return;
    this->inOrder(t->leftSubTree, process);
    process(t->entry);
    this->inOrder(t->rightSubTree, process);
}

template <typename T>
void AVLTree<T>::postOrder(const std::function<void(T)>& process) const {
    this->postOrder(root, process);
}

template <typename T>
void AVLTree<T>::postOrder(TreePointer t, const std::function<void(T)>& process) const {
    if (t == nullptr) return;
    this->postOrder(t->leftSubTree, process);
    this->postOrder(t->rightSubTree, process);
    process(t->entry);
}

template <typename T>
void AVLTree<T>::printTree() {

}