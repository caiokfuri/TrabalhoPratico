#ifndef PEDIDOMODEL_H
#define PEDIDOMODEL_H
#include "Models/Localmodel.h"

class Pedido {
private:
    int pedidoId;
    Local localOrigem;
    Local localDestino;
    double peso;
public:
    Pedido();
    Pedido(int pedidoId, Local origem, Local destino, double peso);
    void preencher();
    void mostrar() const;

    int getId() const;
    Local& getLocalOrigem();
    Local& getLocalDestino();
};

#endif