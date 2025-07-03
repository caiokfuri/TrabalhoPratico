#ifndef PEDIDOSERVICE_H
#define PEDIDOSERVICE_H

#include "../Models/PedidoModel.h"

#include <vector>

using namespace std;


void menuPedidos(vector<Pedido>& pedidos, vector<Local>& locais);
void AdicionarPedido(vector<Pedido>& pedidos, vector<Local>& locais);
void RemoverPedido(vector<Pedido>& pedidos);
void AtualizarPedido(vector<Pedido>& pedidos, vector<Local>& locais);
void ListarPedidos(const vector<Pedido>& pedidos);

#endif