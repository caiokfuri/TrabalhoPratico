#ifndef VEICULOMODEL_H
#define VEICULOMODEL_H

#include <iostream>
#include <string>
using namespace std;

class Veiculo {
private:
    string placa;
    string modelo;
    int status;
    string localAtual;

public:
    Veiculo() {
        placa = "";
        modelo = "";
        localAtual = "";
        status = 0;
    }

    Veiculo(const string& placa, const string& modelo, const string& localAtual, int status)
        : placa(placa), modelo(modelo), localAtual(localAtual), status(status) {}

    void entrada();
    void mostrar() const;

  
    void setPlaca(const string& novaPlaca);
    void setModelo(const string& novoModelo);
    void setStatus(int novoStatus);
    void setLocalAtual(const string& novoLocal);

 
    const string& getPlaca() const;
    const string& getModelo() const;
    const string& getLocalAtual() const;
    int getStatus() const;

    void salvar(FILE* file) const;
    bool carregar(FILE* file);
};

#endif
