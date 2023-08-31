#include <iostream>
#include "Queue.h"

int main() {
    Queue fila1, fila2;

    fila1.append(3);
    fila1.append(5);
    fila1.append(8);

    int x;
    fila1.serve(x);
    std::cout << "Valor servido da Fila 1: " << x << std::endl;

    fila1.rear(x);
    std::cout << "Valor de tail em Fila 1: " << x << std::endl;

    fila1.front(x);
    std::cout << "Valor de head em Fila 1: " << x << std::endl;

    return 0;
}