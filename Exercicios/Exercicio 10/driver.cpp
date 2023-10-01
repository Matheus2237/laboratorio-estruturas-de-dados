#include "List.h"
#include <iostream>

int main() {

    List list;
    list.Insert(1, 4);
    list.Insert(2, 6);
    list.Insert(3, 3);

    std::cout << "Lista: ";
    for (int num : list)
        std::cout << num << " ";
    std::cout << std::endl;

    int maiorPos, maiorVal;
    if (list.searchBiggestValue(maiorPos, maiorVal))
        std::cout << "Maior valor (" << maiorVal << ") encontrado na posicao " << maiorPos << std::endl;

    if (list.swapElements(1, 3)) {
        std::cout << "Estado da lista apos trocar elementos entre as posicoes 1 e 3: ";
        for (int num : list)
            std::cout << num << " ";
        std::cout << std::endl;
    }
}