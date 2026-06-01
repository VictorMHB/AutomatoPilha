#include "Automato.h"
#include <iostream>

Automato::Automato() {
    estadoAtual = 0; // Estado inicial
}

void Automato::processar(std::string entrada) {
    for (int i = 0; i < entrada.length(); i++){
        char c = entrada[i];

        if (estadoAtual == 0) { // q0 - esperando 'a'
            if (c == 'a') {
                pilha.empilhar('A');
            } else if (c == 'b') {
                pilha.empilhar('A');
                estadoAtual = 1; // mudança de estado para q1
            } else {
                estadoAtual = 4; // Erro
                return;
            }
        } else if (estadoAtual == 1) { // q1 - esperando 'b'
            if (c == 'b') {
                pilha.empilhar('A');
            } else if (c == 'c') {
                if (!pilha.estaVazia()) {
                    estadoAtual = 4;
                    return;
                }
                pilha.desempilhar();
                estadoAtual = 2; // mudança de estado para q2
            } else {
                estadoAtual = 4; // Estado de erro
                return;
            }
        } else if (estadoAtual == 2) { // q2 - esperando 'c'
            if (c == 'c') {
                if (!pilha.estaVazia()) {
                    estadoAtual = 4;
                    return;
                }
                pilha.desempilhar();
            } else {
                estadoAtual = 4; // Estado de erro
                return;
            }
        } 
    }

    if (pilha.estaVazia() && estadoAtual == 2) {
        estadoAtual = 3; // Estado de aceitação
    } else {
        estadoAtual = 4; // Estado de erro
    }
}

bool Automato::estaAceito() {
        return estadoAtual == 3;
    }