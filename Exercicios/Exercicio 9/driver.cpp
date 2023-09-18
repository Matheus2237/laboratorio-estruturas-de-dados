#include "List.h"
#include <iostream>

int main() {
    List list;
    list.Insert(1, 4);
    list.Insert(2, 5);
    list.Insert(3, 7);

    int antes;
    int depois;
    list.Retrieve(2, antes);
    list.Replace(2, 8);
    list.Retrieve(2, depois);

    std::cout << "Antes da troca na segunda posicao: " << antes << std::endl;
    std::cout << "Depois da troca na segunda posicao: " << depois << std::endl;

    return 0;
}