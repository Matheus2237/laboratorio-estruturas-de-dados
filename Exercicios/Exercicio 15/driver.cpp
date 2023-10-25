#include "BinarySearchTree.h"
#include <iostream>
#define SKIP_LINE std::cout << std::endl

int main() {
    BinarySearchTree tree;
    SKIP_LINE;
    tree.Print();
    SKIP_LINE;

// a)
    std::cout << "a)" << std::endl;
    tree.findParentOf(1);
    tree.findParentOf(2);
    tree.findParentOf(3);
    tree.findParentOf(5);
    tree.findParentOf(8);
    tree.findParentOf(9);
    tree.findParentOf(10);
    tree.findParentOf(12);
    tree.findParentOf(15);
    tree.findParentOf(4);
    SKIP_LINE;

// b)
    std::cout << "b) Soma dos valores da árvore: " << tree.sumTreeKeys() << std::endl;   
}