#ifndef VEICULOMODEL_H
#define VEICULOMODEL_H

#include <iostream>
#include <cstring>
#include <cstdio>

class Veiculo {
private:
    char placa[8];
    char modelo[15];
    int status;
    char localAtual[50];

public:
    Veiculo();
    Veiculo(const char placa[8], const char modelo[15], const char localAtual[50], int status = 0);

    void preencher();
    void mostrar() const;

    void setStatus(int novoStatus);
    void setLocalAtual(const char* novoLocal);

    const char* getPlaca() const;
    const char* getModelo() const;
    const char* getLocalAtual() const;
    int getStatus() const;

    void salvar(FILE* file) const;
    bool carregar(FILE* file);
};

#endif