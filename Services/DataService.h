//
// Created by bruno on 02/07/2025.
//

#ifndef DATASERVICE_H
#define DATASERVICE_H
#include <vector>
#include <fstream>
#include <filesystem>
#include "../Models/Localmodel.h"
#include "../Models/Pedidomodel.h"
#include "../Models/Veiculomodel.h"


class DataService {
public:
    static bool salvarLocais(const std::vector<Local>& locais);
    static bool salvarPedidos(const std::vector<Pedido>& pedidos);
    static bool salvarVeiculos(const std::vector<Veiculo>& veiculos);

    static bool carregarLocais(std::vector<Local>& locais);
    static bool carregarPedidos(std::vector<Pedido>& pedidos);
    static bool carregarVeiculos(std::vector<Veiculo>& veiculos);

    static bool criarDiretorioBackup();

private:
    static const std::string BACKUP_DIR;
};




#endif //DATASERVICE_H
