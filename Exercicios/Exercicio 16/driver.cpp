#include "BinarySearchTree.h"
#include <iostream>

int main() {
    BinarySearchTree t;
    t.Print();
    std::cout << "---------------------" << std::endl;
    t.Insert(20);
    t.Print();
    std::cout << "---------------------" << std::endl;
    t.Delete(12);
    t.Print();
}