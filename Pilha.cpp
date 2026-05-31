#include "Pilha.h"

Pilha::Pilha() {
    topo = -1;
}

void Pilha::empilhar(char elemento) {
    if (topo < 99) {      
        topo++;
        elementos[topo] = elemento;
    }
}

char Pilha::desempilhar() {
    if (!estaVazia()) {
        char elemento = elementos[topo];
        topo--;
        return elemento;
    }

    return '\0'; // Retorna um caractere nulo se a pilha estiver vazia
}

char Pilha::topoPilha() {
    if (!estaVazia()) {
        return elementos[topo];
    }
    return '\0'; // Retorna um caractere nulo se a pilha estiver vazia
}

bool Pilha::estaVazia() {
    return topo == -1;
}