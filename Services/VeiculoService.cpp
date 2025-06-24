#include "VeiculoService.h"
#include <iostream>
#include <cstdio>

void AdicionarVeiculo(std::vector<Veiculo>& veiculos) {
    Veiculo v = criarVeiculo();
    veiculos.push_back(v);
    std::cout << "Veículo adicionado com sucesso!\n";
}

void RemoverVeiculo(std::vector<Veiculo>& veiculos) {
    ListarVeiculos(veiculos);
    if (veiculos.empty()) return;

    std::cout << "Digite o índice para remover: ";
    int i;
    std::cin >> i;

    if (i >= 0 && i < veiculos.size()) {
        veiculos.erase(veiculos.begin() + i);
        std::cout << "Removido com sucesso.\n";
    } else {
        std::cout << "Índice inválido.\n";
    }
}

void AtualizarVeiculo(std::vector<Veiculo>& veiculos) {
    ListarVeiculos(veiculos);
    if (veiculos.empty()) return;

    std::cout << "Digite o índice para atualizar: ";
    int i;
    std::cin >> i;

    if (i >= 0 && i < veiculos.size()) {
        veiculos[i].preencher();
        std::cout << "Atualizado com sucesso.\n";
    } else {
        std::cout << "Índice inválido.\n";
    }
}

void ListarVeiculos(const std::vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        std::cout << "Nenhum veículo cadastrado.\n";
        return;
    }

    for (int i = 0; i < veiculos.size(); i++) {
        std::cout << "\n[Índice " << i << "]\n";
        veiculos[i].mostrar();
    }
}

void SalvarEmArquivo(const std::vector<Veiculo>& veiculos) {
    FILE* file = fopen("veiculos.dat", "wb");
    if (!file) {
        std::cout << "Erro ao abrir arquivo para salvar.\n";
        return;
    }

    for (const Veiculo& v : veiculos)
        v.salvar(file);

    fclose(file);
    std::cout << "Backup salvo em 'veiculos.dat'\n";
}

void RestaurarDeArquivo(std::vector<Veiculo>& veiculos) {
    FILE* file = fopen("veiculos.dat", "rb");
    if (!file) {
        std::cout << "Arquivo 'veiculos.dat' não encontrado.\n";
        return;
    }

    veiculos.clear();
    Veiculo temp;

    while (temp.carregar(file)) {
        veiculos.push_back(temp);
    }

    fclose(file);
    std::cout << "Dados restaurados de 'veiculos.dat'\n";
}
