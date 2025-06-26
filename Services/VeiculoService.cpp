#include "VeiculoService.h"
#include <iostream>
#include <cstdio>

using namespace std;

void AdicionarVeiculo(vector<Veiculo>& veiculos) {
    Veiculo v;
    v.preencher();
    veiculos.push_back(v);
    cout << "Veículo adicionado com sucesso!\n";
}

void RemoverVeiculo(vector<Veiculo>& veiculos) {
    ListarVeiculos(veiculos);
    if (veiculos.empty()) return;

    cout << "Digite o índice para remover: ";
    int i;
    cin >> i;

    if (i >= 0 && i < veiculos.size()) {
        veiculos.erase(veiculos.begin() + i);
        cout << "Removido com sucesso.\n";
    } else {
        cout << "Índice inválido.\n";
    }
}

void AtualizarVeiculo(vector<Veiculo>& veiculos) {
    ListarVeiculos(veiculos);
    if (veiculos.empty()) return;

    cout << "Digite o índice para atualizar: ";
    int i;
    cin >> i;

    if (i >= 0 && i < veiculos.size()) {
        veiculos[i].preencher();
        cout << "Atualizado com sucesso.\n";
    } else {
        cout << "Índice inválido.\n";
    }
}

void ListarVeiculos(const vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veículo cadastrado.\n";
        return;
    }

    for (int i = 0; i < veiculos.size(); i++) {
        cout << "\n[Índice " << i << "]\n";
        veiculos[i].mostrar();
    }
}

void SalvarEmArquivo(const vector<Veiculo>& veiculos) {
    FILE* file = fopen("veiculos.dat", "wb");
    if (!file) {
        cout << "Erro ao abrir arquivo para salvar.\n";
        return;
    }

    for (const Veiculo& v : veiculos)
        v.salvar(file);

    fclose(file);
    cout << "Backup salvo em 'veiculos.dat'\n";
}

void RestaurarDeArquivo(vector<Veiculo>& veiculos) {
    FILE* file = fopen("veiculos.dat", "rb");
    if (!file) {
        cout << "Arquivo 'veiculos.dat' não encontrado.\n";
        return;
    }

    veiculos.clear();
    Veiculo temp;

    while (temp.carregar(file)) {
        veiculos.push_back(temp);
    }

    fclose(file);
    cout << "Dados restaurados de 'veiculos.dat'\n";
}

void menuVeiculos(vector<Veiculo>& veiculos) {
    int opcao;
    do {
        cout << "\n--- MENU VEÍCULOS ---\n";
        cout << "1 - Adicionar Veículo\n";
        cout << "2 - Remover Veículo\n";
        cout << "3 - Atualizar Veículo\n";
        cout << "4 - Listar Veículos\n";
        cout << "5 - Backup de dados\n";
        cout << "6 - Restaurar dados\n";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: AdicionarVeiculo(veiculos); break;
            case 2: RemoverVeiculo(veiculos); break;
            case 3: AtualizarVeiculo(veiculos); break;
            case 4: ListarVeiculos(veiculos); break;
            case 5: SalvarEmArquivo(veiculos); break;
            case 6: RestaurarDeArquivo(veiculos); break;
            case 0: cout << "Voltando ao menu principal...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}
