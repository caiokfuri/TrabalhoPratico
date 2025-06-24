#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <cstring>
#include <cstdio>

class Veiculo {
private:
    char placa[8];
    char modelo[20];
    int status; //
    char localAtual[30];

public:
    void preencher() {
        std::cout << "Placa (7 chars): ";
        std::cin >> placa;
        std::cout << "Modelo: ";
        std::cin >> modelo;
        std::cout << "Local Atual: ";
        std::cin >> localAtual;
        status = 0;
    }

    void mostrar() const {
        std::cout << "Placa: " << placa
                  << "\nModelo: " << modelo
                  << "\nStatus: " << (status == 0 ? "Disponível" : "Ocupado")
                  << "\nLocal Atual: " << localAtual << "\n";
    }

    void setStatus(int novoStatus) { status = novoStatus; }

    void setLocalAtual(const char* novoLocal) {
        strncpy(localAtual, novoLocal, 29);
        localAtual[29] = '\0';
    }

    const char* getPlaca() const { return placa; }
    const char* getModelo() const { return modelo; }
    const char* getLocalAtual() const { return localAtual; }
    int getStatus() const { return status; }

    void salvar(FILE* file) const { fwrite(this, sizeof(Veiculo), 1, file); }
    bool carregar(FILE* file) { return fread(this, sizeof(Veiculo), 1, file) == 1; }
};

inline Veiculo criarVeiculo() {
    Veiculo v;
    v.preencher();
    return v;
}

#endif
