#ifndef PILHA_H
#define PILHA_H

class Pilha {
private:
    char elementos[100];
    int topo;

public:
    Pilha();
    void empilhar(char elemento);
    char desempilhar();
    char topoPilha();
    bool estaVazia();
};

#endif