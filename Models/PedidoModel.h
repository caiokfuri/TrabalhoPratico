#ifndef PEDIDOMODEL_H
#define PEDIDOMODEL_H
#include "LocalModel.h"

class Pedido {
private:
    int pedidoId;
    Local localOrigem;
    Local localDestino;
    double peso;
public:
    Pedido();
    Pedido(int pedidoId, Local origem, Local destino, double peso);
    void entrada();
    void mostrar() const;

    int getId() const;
    Local& getLocalOrigem();
    Local& getLocalDestino();
    
};

#endif