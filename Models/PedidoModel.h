#ifndef PEDIDOMODEL_H
#define PEDIDOMODEL_H
#include "Models\Localmodel.h"

class PedidoModel {
private:
    int pedidoId;
    Local localOrigem;
    Local localDestino;
    double peso;
public:
    PedidoModel();
    PedidoModel(int pedidoId, Local origem, Local destino, double peso);
    void preencher();
    void mostrar() const;
};

#endif