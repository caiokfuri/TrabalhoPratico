#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H

#include <string>
#include <vector>
#include "../Models/Veiculomodel.h"
#include "../Models/Localmodel.h"

using namespace std;

void AdicionarVeiculo(vector<Veiculo>& frota, const vector<Local>& locais);
void RemoverVeiculo(vector<Veiculo>& frota);
void AtualizarVeiculo(vector<Veiculo>& frota, const vector<Local>& locais);
void ListarVeiculos(const vector<Veiculo>& frota);
void SalvarEmArquivo(const vector<Veiculo>& frota);
void RestaurarDeArquivo(vector<Veiculo>& frota);
void menuVeiculos(vector<Veiculo>& frota, const vector<Local>& locais);

bool validarPlaca(const string& placa);
bool validarLocalExiste(const string& nomeLocal, const vector<Local>& locais);

#endif