#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H

#include <string>
#include <vector>
#include "../Models/Localmodel.h"

using namespace std;

void AdicionarLocal(vector<Local>& locais);
void RemoverLocal(vector<Local>& locais);
void ListarLocais(const vector<Local>& locais);
void AtualizarLocal(vector<Local>& locais);
void backupLocais(const vector<Local>& locais);
void restaurarLocais(vector<Local>& locais);
void menuLocais(vector<Local>& locais);
Local BuscarLocalPorNome(vector<Local>& locais);

bool validarCoordenada(double& coordenada, const string& tipo);

#endif