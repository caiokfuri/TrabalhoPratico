#include "Veiculomodel.h"

using namespace std;

Veiculo::Veiculo() {
    placa[0] = '\0';
    modelo[0] = '\0';
    localAtual[0] = '\0';
    status = 0;
}

Veiculo::Veiculo(const char placa[8], const char modelo[20], const char localAtual[30], int status) : status(status) {
    int i = 0;
    for (; i < 7 && placa[i] != '\0'; ++i) this->placa[i] = placa[i];
    this->placa[i] = '\0';

    i = 0;
    for (; i < 19 && modelo[i] != '\0'; ++i) this->modelo[i] = modelo[i];
    this->modelo[i] = '\0';

    i = 0;
    for (; i < 29 && localAtual[i] != '\0'; ++i) this->localAtual[i] = localAtual[i];
    this->localAtual[i] = '\0';
}

void Veiculo::preencher() {
    cout << "Placa (7 chars): ";
    cin >> placa;
    cout << "Modelo: ";
    cin >> modelo;
    cout << "Local Atual: ";
    cin >> localAtual;
    status = 0;
}

void Veiculo::mostrar() const {
    cout << "Placa: " << placa
         << "\nModelo: " << modelo
         << "\nStatus: " << (status == 0 ? "Disponível" : "Ocupado")
         << "\nLocal Atual: " << localAtual << "\n";
}

void Veiculo::setStatus(int novoStatus) { status = novoStatus; }

void Veiculo::setLocalAtual(const char* novoLocal) {
    int i = 0;
    for (; i < 29 && novoLocal[i] != '\0'; ++i) localAtual[i] = novoLocal[i];
    localAtual[i] = '\0';
}

const char* Veiculo::getPlaca() const { return placa; }
const char* Veiculo::getModelo() const { return modelo; }
const char* Veiculo::getLocalAtual() const { return localAtual; }
int Veiculo::getStatus() const { return status; }

void Veiculo::salvar(FILE* file) const { fwrite(this, sizeof(Veiculo), 1, file); }
bool Veiculo::carregar(FILE* file) { return fread(this, sizeof(Veiculo), 1, file) == 1; }