    #ifndef VEICULOSERVICE_H
    #define VEICULOSERVICE_H

    #include "../Models/Veiculomodel.h"
    #include <vector>

    using namespace std;

    void AdicionarVeiculo(vector<Veiculo>& frota);
    void RemoverVeiculo(vector<Veiculo>& frota);
    void AtualizarVeiculo(vector<Veiculo>& frota);
    void ListarVeiculos(const vector<Veiculo>& frota);
    void SalvarEmArquivo(const vector<Veiculo>& frota);
    void RestaurarDeArquivo(vector<Veiculo>& frota);
    void menuVeiculos(std::vector<Veiculo>& frota);

    #endif
