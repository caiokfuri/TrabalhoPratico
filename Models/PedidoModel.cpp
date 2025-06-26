#include "PedidoModel.h"
#include <iostream>
#include <cstring>

using namespace std;

Pedido::Pedido() {
    pedidoId = 0;
    peso = 0;
}

Pedido::Pedido(int pedidoId, Local origem, Local destino, double peso) {
   this->pedidoId = pedidoId;
   this->localOrigem = origem;
   this->localDestino = destino;
   this->peso = peso;
}

 void Pedido::preencher() {
        cout << "ID do Pedido: ";
        cin >> pedidoId;
        cout << "--- Local de Origem ---\n";
        localOrigem.preencher();
        cout << "--- Local de Destino ---\n";
        localDestino.preencher();
        cout << "Peso: ";
        cin >> peso;
}

void Pedido::mostrar() const {
        cout << "\nPedido ID: " << pedidoId << endl;
        cout << "Origem:\n";
        localOrigem.mostrar();
        cout << "Destino:\n";
        localDestino.mostrar();
        cout << "Peso: " << peso << " kg\n";
}
