#include "Stack.h"
#include <iostream>

int main() {
    Stack s1;
    Stack s2;

    s1.push(3);
    s1.push(5);
    s1.push(8);

    s2.push(50);

    int x;
    s1.top(x);
    std::cout << x << std::endl;
    s1.pop(x);
    std::cout << x << std::endl;
}