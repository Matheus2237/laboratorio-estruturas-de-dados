#include "BinarySearchTree.h"
#include <stdexcept>

template <typename T>
BinarySearchTree<T>::BinarySearchTree():
    root(nullptr)
{}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    clear(root);
}

template <typename T>
void BinarySearchTree<T>::clear() {
    clear(root);
}

template <typename T>
void BinarySearchTree<T>::clear(TreePointer t) {
    if (t == nullptr)
        return;
    clear(t->leftSubTree);
    clear(t->rightSubTree);
    delete t;
}

template <typename T>
bool BinarySearchTree<T>::empty() const {
    return root == nullptr;
}

template <typename T>
bool BinarySearchTree<T>::full() const {
    return false;
}

template <typename T>
void BinarySearchTree<T>::preOrder(const std::function<void(T)>& process) const {
    this->preOrder(root, process);
}

template <typename T>
void BinarySearchTree<T>::preOrder(TreePointer t, const std::function<void(T)>& process) const {
    if (t == nullptr) return;
    process(t->entry);
    this->preOrder(t->leftSubTree, process);
    this->preOrder(t->rightSubTree, process);
}

template <typename T>
void BinarySearchTree<T>::inOrder(const std::function<void(T)>& process) const {
    this->inOrder(root, process);
}

template <typename T>
void BinarySearchTree<T>::inOrder(TreePointer t, const std::function<void(T)>& process) const {
    if (t == nullptr) return;
    this->inOrder(t->leftSubTree, process);
    process(t->entry);
    this->inOrder(t->rightSubTree, process);
}

template <typename T>
void BinarySearchTree<T>::postOrder(const std::function<void(T)>& process) const {
    this->postOrder(root, process);
}

template <typename T>
void BinarySearchTree<T>::postOrder(TreePointer t, const std::function<void(T)>& process) const {
    if (t == nullptr) return;
    this->postOrder(t->leftSubTree, process);
    this->postOrder(t->rightSubTree, process);
    process(t->entry);
}

template <typename T>
unsigned int BinarySearchTree<T>::nodes() const {
    return this->nodes(root);
}

template <typename T>
unsigned int BinarySearchTree<T>::nodes(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    return 1 + nodes(t->leftSubTree) + nodes(t->rightSubTree);
}

template <typename T>
unsigned int BinarySearchTree<T>::leaves() const {
    return this->leaves(root);
}

template <typename T>
unsigned int BinarySearchTree<T>::leaves(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    else if (t->leftSubTree == nullptr && t->rightSubTree == nullptr)
        return 1;
    else
        return leaves(t->leftSubTree) + leaves(t->rightSubTree);
}

template <typename T>
int BinarySearchTree<T>::height() const {
    return this->height(root);
}

template <typename T>
int BinarySearchTree<T>::height(const TreePointer& t) const {
    if (t == nullptr)
        return -1;
    int left = height(t->leftSubTree);
    int right = height(t->rightSubTree);
    return left > right ? left + 1 : right + 1;
}

template <typename T>
T BinarySearchTree<T>::minimum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia!");
    while (t->leftSubTree != nullptr)
        t = t->leftSubTree;
    return t->entry;
}

template <typename T>
T BinarySearchTree<T>::maximum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia!");
    while (t->rightSubTree != nullptr)
        t = t->rightSubTree;
    return t->entry;
}

template <typename T>
bool BinarySearchTree<T>::search(const T value) const {
    return search(value, root);
}

template <typename T>
bool BinarySearchTree<T>::search(const T value, const TreePointer& t) const {
    if (t == nullptr)
        return false;
    else if (value < t->entry)
        return search(value, t->leftSubTree);
    else if (value > t->entry)
        return search(value, t->rightSubTree);
    else
        return true;
}

template <typename T>
void BinarySearchTree<T>::insert(const T value) {
    TreePointer p = nullptr;
    TreePointer q = root;
    while (q != nullptr) {
        p = q;
        if (value < q->entry)
            q = q->leftSubTree;
        else
            q = q->rightSubTree;
    }

    TreePointer r = new TreeNode;
    if (r == nullptr) throw std::bad_alloc();
    r->entry = value;
    r->leftSubTree = nullptr;
    r->rightSubTree = nullptr;

    if (p == nullptr)
        root = r;
    else if (value < p->entry)
        p->leftSubTree = r;
    else
        p->rightSubTree = r;
}

template <typename T>
void BinarySearchTree<T>::deleteValue(const T value) {
    deleteValue(value, root);
}

template <typename T>
void BinarySearchTree<T>::deleteValue(const T value, TreePointer& t) {
    if (t == nullptr)
        throw std::out_of_range("Elemento não se encontra na árvore!");
    else if (value < t->entry)
        deleteValue(value, t->leftSubTree);
    else if (value > t->entry)
        deleteValue(value, t->rightSubTree);
    else {
        TreePointer q = t;
        if (q->leftSubTree == nullptr)
            t = q->rightSubTree;
        else if (q->rightSubTree == nullptr)
            t = q->leftSubTree;
        else
            deleteMaximumValue(q, q->leftSubTree);
        delete q;
    }
}

template <typename T>
void BinarySearchTree<T>::deleteMaximumValue(TreePointer& q, TreePointer& r) {
    if (r->rightSubTree != nullptr)
        deleteMaximumValue(q, r->rightSubTree);
    else {
        q->entry = r->entry;
        q = r;
        r = r->rightSubTree;
    }
}