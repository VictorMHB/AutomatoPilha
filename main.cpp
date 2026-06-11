#include <iostream>
#include "Automato.h"

int main() {
    std::string entrada;

    std::cout << "=== Automato de Pilha ===" << std::endl;
    std::cout << "Linguagem: a^n b^k c^(n+k)" << std::endl;
    std::cout << "Digite 'sair' para encerrar." << std::endl;
    std::cout << "=========================" << std::endl;

    while (true) {
        std::cout << "\nDigite a string: ";
        std::cin >> entrada;

        if (entrada == "sair") {
            std::cout << "Encerrando..." << std::endl;
            break;
        }

        Automato a;
        a.processar(entrada);

        if (a.estaAceito()) {
            std::cout << "Resultado: String ACEITA!" << std::endl;
        } else {
            std::cout << "Resultado: String REJEITADA!" << std::endl;
        }
    }

    return 0;
}