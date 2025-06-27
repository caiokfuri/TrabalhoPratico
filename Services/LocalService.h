#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H

#include "../Models/Localmodel.h"
#include <vector>
#include <string>

using namespace std;

void menuLocais(vector<Local>& locais);
void AdicionarLocal(vector<Local>& locais);
void RemoverLocal(vector<Local>& locais);
void AtualizarLocal(vector<Local>& locais);
void ListarLocais(const vector<Local>& locais);

#endif