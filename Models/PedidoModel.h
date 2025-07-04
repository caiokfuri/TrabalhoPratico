#ifndef PEDIDOMODEL_H
#define PEDIDOMODEL_H
#include "Localmodel.h"
#include <vector>


class Pedido {
private:
    //Atributos
    int pedidoId;
    Local localOrigem;
    Local localDestino;
    double peso;
public:
    //Construtores
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
    void entrada(vector<Local>& locais);
    void mostrar() const;

    int getId() const;
    void setId(int id);
    Local& getLocalOrigem();
    void setLocalOrigem(Local origem);
    Local& getLocalDestino();
    void setLocalDestino(Local destino);
    double getPeso() const;
    void setPeso(double peso);

    
};

#endif