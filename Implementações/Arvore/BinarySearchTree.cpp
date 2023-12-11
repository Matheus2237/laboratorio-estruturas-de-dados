#include "BinarySearchTree.h"
#include <stdexcept>

BinarySearchTree::BinarySearchTree():
    root(nullptr)
{}

BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

void BinarySearchTree::clear() {
    clear(root);
}

void BinarySearchTree::clear(TreePointer t) {
    if (t == nullptr)
        return;
    clear(t->leftSubTree);
    clear(t->rightSubTree);
    delete t;
}

bool BinarySearchTree::empty() const {
    return root == nullptr;
}

bool BinarySearchTree::full() const {
    return false;
}

void BinarySearchTree::preOrder(const std::function<void(int)>& process) const {
    this->preOrder(root, process);
}

void BinarySearchTree::preOrder(TreePointer t, const std::function<void(int)>& process) const {
    if (t == nullptr) return;
    process(t->entry);
    this->preOrder(t->leftSubTree, process);
    this->preOrder(t->rightSubTree, process);
}

void BinarySearchTree::inOrder(const std::function<void(int)>& process) const {
    this->inOrder(root, process);
}

void BinarySearchTree::inOrder(TreePointer t, const std::function<void(int)>& process) const {
    if (t == nullptr) return;
    this->inOrder(t->leftSubTree, process);
    process(t->entry);
    this->inOrder(t->rightSubTree, process);
}

void BinarySearchTree::postOrder(const std::function<void(int)>& process) const {
    this->postOrder(root, process);
}

void BinarySearchTree::postOrder(TreePointer t, const std::function<void(int)>& process) const {
    if (t == nullptr) return;
    this->postOrder(t->leftSubTree, process);
    this->postOrder(t->rightSubTree, process);
    process(t->entry);
}

int BinarySearchTree::nodes() const {
    return this->nodes(root);
}

int BinarySearchTree::nodes(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    return 1 + nodes(t->leftSubTree) + nodes(t->rightSubTree);
}

int BinarySearchTree::leaves() const {
    return this->leaves(root);
}

int BinarySearchTree::leaves(const TreePointer& t) const {
    if (t == nullptr)
        return 0;
    else if (t->leftSubTree == nullptr && t->rightSubTree == nullptr)
        return 1;
    else
        return leaves(t->leftSubTree) + leaves(t->rightSubTree);
}

int BinarySearchTree::height() const {
    return this->height(root);
}

int BinarySearchTree::height(const TreePointer& t) const {
    if (t == nullptr)
        return -1;
    int left = height(t->leftSubTree);
    int right = height(t->rightSubTree);
    return left > right ? left + 1 : right + 1;
}

int BinarySearchTree::minimum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia!");
    while (t->leftSubTree != nullptr)
        t = t->leftSubTree;
    return t->entry;
}

int BinarySearchTree::maximum() const {
    TreePointer t = root;
    if (t == nullptr)
        throw std::out_of_range("Árvore vazia!");
    while (t->rightSubTree != nullptr)
        t = t->rightSubTree;
    return t->entry;
}

bool BinarySearchTree::search(const int value) const {
    search(value, root);
}

bool BinarySearchTree::search(const int value, const TreePointer& t) const {
    if (t == NULL)
        return false;
    else if (value < t->entry)
        return search(value, t->leftSubTree);
    else if (value > t->entry)
        return search(value, t->rightSubTree);
    else
        return true;
}

void BinarySearchTree::insert(const int value) {
    TreePointer p = nullptr;
    TreePointer q = root;
    while (q != nullptr) {
        p = q;
        if (value < q->entry)
            q = q->leftSubTree;
        else
            q = q->leftSubTree;
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

void BinarySearchTree::deleteValue(const int value) {
    deleteValue(value, root);
}

void BinarySearchTree::deleteValue(const int value, TreePointer& t) {
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

void BinarySearchTree::deleteMaximumValue(TreePointer& q, TreePointer& r) {
    if (r->rightSubTree != nullptr)
        deleteMaximumValue(q, r->rightSubTree);
    else {
        q->entry = r->entry;
        q = r;
        r = r->rightSubTree;
    }
}