#include <iostream>
#include "Automato.h"

int main() {
    std::string entrada;
    std::cout << "Digite a string: ";
    std::cin >> entrada;

    Automato a;
    a.processar(entrada);

    if (a.estaAceito()) {
        std::cout << "String ACEITA!" << std::endl;
    } else {
        std::cout << "String REJEITADA!" << std::endl;
    }

    return 0;
}