#include "AVLTree.h"

int main() {
    AVLTree tree;
    tree.insert(3);
    tree.print();
    tree.insert(2);
    tree.insert(1);
    tree.print();
    tree.insert(3);
}