#ifndef PEDIDOSERVICE_H
#define PEDIDOSERVICE_H

#include "../Models/PedidoModel.h"
#include <vector>
#include <cstring>

using namespace std;

void menuPedidos(vector<Pedido>& pedidos);
void AdicionarPedido(vector<Pedido>& pedidos);
void RemoverPedido(vector<Pedido>& pedidos);
void AtualizarPedido(vector<Pedido>& pedidos);
void ListarPedidos(const vector<Pedido>& pedidos);

#endif