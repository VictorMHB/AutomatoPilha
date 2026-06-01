#ifndef AUTOMATO_H
#define AUTOMATO_H

#include "Pilha.h"
#include <string>

class Automato {
    private:
        int estadoAtual;
        Pilha pilha;

    public:
        Automato();
        void processar(std::string entrada);
        bool estaAceito();
};

#endif