#include "List.h"
#include <iostream>

int main() {
    List list;
    list.Insert(1, 1);
    list.Insert(2, 2);
    list.Insert(3, 3);
    list.Insert(4, 4);

    // Impressão dos elementos em ordem inversa.
    list.printBackwards();

    // Remoção do elemento 3.
    list.remove_valor(3);
    list.printBackwards();

    // Chamada do destrutor.
    list.~List();
}