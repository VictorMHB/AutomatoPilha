#include <iostream>
#include "Pilha.h"

int main() {
    Pilha p;

    p.empilhar('1');
    p.empilhar('2');
    p.empilhar('3');

    while (!p.estaVazia()) {
        std::cout << p.desempilhar() << std::endl;
    }

    return 0;
}