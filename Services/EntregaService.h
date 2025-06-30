#ifndef ENTREGASERVICE_H
#define ENTREGASERVICE_H

#include "../Models/Veiculomodel.h"
#include "../Models/PedidoModel.h"

double calculoDistancia(double x1, double y1, double x2, double y2);
void processarEntrega(vector<Veiculo>& frota, vector<Local>& pontos, vector<Pedido>& pedidos);

#endif