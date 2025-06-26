#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H

#include "../Models/LocalModel.h"
#include <vector>
#include <cstring>

using namespace std;

void menuLocais(vector<Local>& locais);
void AdicionarLocal(vector<Local>& locais);
void RemoverLocal(vector<Local>& locais);
void AtualizarLocal(vector<Local>& locais);
void ListarLocais(const vector<Local>& locais);

#endif