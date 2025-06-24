#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H

#include "../Models/Veiculo.h"
#include <vector>

void AdicionarVeiculo(std::vector<Veiculo>& veiculos);
void RemoverVeiculo(std::vector<Veiculo>& veiculos);
void AtualizarVeiculo(std::vector<Veiculo>& veiculos);
void ListarVeiculos(const std::vector<Veiculo>& veiculos);
void SalvarEmArquivo(const std::vector<Veiculo>& veiculos);
void RestaurarDeArquivo(std::vector<Veiculo>& veiculos);

#endif
