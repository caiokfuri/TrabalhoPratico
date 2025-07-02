#ifndef DATASERVICE_H
#define DATASERVICE_H
#include <vector>
#include <fstream>
#include <filesystem>
#include "../Models/Localmodel.h"
#include "../Models/Pedidomodel.h"
#include "../Models/Veiculomodel.h"

using namespace std;

class DataService {
public:
    static bool salvarLocais(const vector<Local>& locais);
    static bool salvarPedidos(const vector<Pedido>& pedidos);
    static bool salvarVeiculos(const vector<Veiculo>& frota);

    static bool carregarLocais(vector<Local>& locais);
    static bool carregarPedidos(vector<Pedido>& pedidos);
    static bool carregarVeiculos(vector<Veiculo>& frota);

    static bool criarDiretorioBackup();

private:
    static const string BACKUP_DIR;
};

#endif //DATASERVICE_H
