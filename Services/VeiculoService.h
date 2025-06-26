#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H

#include "../Models/VeiculoModel.h"
#include <vector>

using namespace std;

void AdicionarVeiculo(vector<Veiculo>& veiculos);
void RemoverVeiculo(vector<Veiculo>& veiculos);
void AtualizarVeiculo(vector<Veiculo>& veiculos);
void ListarVeiculos(const vector<Veiculo>& veiculos);
void SalvarEmArquivo(const vector<Veiculo>& veiculos);
void RestaurarDeArquivo(vector<Veiculo>& veiculos);
void menuVeiculos(std::vector<Veiculo>& veiculos);

#endif
