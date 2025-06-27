#ifndef PEDIDOMODEL_H
#define PEDIDOMODEL_H
#include "Localmodel.h"


class Pedido {
private:
    int pedidoId;
    Local localOrigem;
    Local localDestino;
    double peso;
public:
    Pedido() {
        pedidoId = 0;
        peso = 0;
    }
    Pedido(int pedidoId, Local origem, Local destino, double peso) {
        this->pedidoId = pedidoId;
        this->localOrigem = origem;
        this->localDestino = destino;
        this->peso = peso;
    }
    void entrada();
    void mostrar() const;

    int getId() const;
    Local& getLocalOrigem();
    Local& getLocalDestino();
    
};

#endif