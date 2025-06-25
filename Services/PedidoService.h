#ifndef PEDIDOSERVICE_H
#define PEDIDOSERVICE_H

#include "../Models/PedidoModel.h"
#include <vector>
#include <cstring>

using namespace std;

void menuPedidos(vector<PedidoModel>& pedidos);
void AdicionarPedido(vector<PedidoModel>& pedidos);
void RemoverPedido(vector<PedidoModel>& pedidos);
void AtualizarPedido(vector<PedidoModel>& pedidos);
void ListarPedidos(const vector<PedidoModel>& pedidos);

#endif