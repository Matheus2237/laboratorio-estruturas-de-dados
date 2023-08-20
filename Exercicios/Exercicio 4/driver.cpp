#include <iostream>
#include "Bag.h"

int main() {
    Bag bag;
    bag.insert(4);
    bag.insert(5);
    bag.insert(8);
    bag.remove(8);
    bag.remove(4);
    bag.insert(4);
    std::cout << "4 aparece " << bag.occurrence(4) << " vezes na bag" << std::endl;
}