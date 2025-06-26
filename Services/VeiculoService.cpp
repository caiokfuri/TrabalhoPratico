#include "VeiculoService.h"
#include <iostream>
#include <cstdio>

using namespace std;

void AdicionarVeiculo(vector<Veiculo>& veiculos) {
    Veiculo v;
    v.entrada();
    veiculos.push_back(v);
    cout << "Veiculo adicionado com sucesso!\n";
}

void RemoverVeiculo(vector<Veiculo>& veiculos) {
    ListarVeiculos(veiculos);
    if (veiculos.empty()) return;

    cout << "Digite o indice para remover: ";
    int i;
    cin >> i;

    if (i >= 0 && i < veiculos.size()) {
        veiculos.erase(veiculos.begin() + i);
        cout << "Removido com sucesso.\n";
    } else {
        cout << "Indice invalido.\n";
    }
}

void AtualizarVeiculo(vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veiculo cadastrado.\n";
        return;
    }

    ListarVeiculos(veiculos);

    cout << "Digite o indice do veiculo que deseja atualizar: ";
    int i;
    cin >> i;

    if (i < 0 || i >= veiculos.size()) {
        cout << "Indice invalido.\n";
        return;
    }

    int opcao;
    do {
        cout << "\nO que deseja alterar?\n";
        cout << "1 - Placa\n";
        cout << "2 - Modelo\n";
        cout << "3 - Status\n";
        cout << "4 - Local Atual\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: {
                cout << "Nova placa: ";
                // FAZER SET PLACA
                cout << "Placa atualizada!\n";
                break;
            }
            case 2: {
                cout << "Novo modelo: ";
                //FAZER SET MODELO
                cout << "Modelo atualizado!\n";
                break;
            }
            case 3: {
                cout << "Novo status (0 - Disponivel, 1 - Ocupado): ";
                int novoStatus;
                cin >> novoStatus;
                veiculos[i].setStatus(novoStatus);
                cout << "Status atualizado!\n";
                break;
            }
            case 4: {
                cout << "Novo local atual: ";
                char novoLocal[50];
                cin.ignore();
                cin.getline(novoLocal, 50);
                veiculos[i].setLocalAtual(novoLocal);
                cout << "Local atual atualizado!\n";
                break;
            }
            case 0:
                cout << "Saindo da atualizacao.\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

void ListarVeiculos(const vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veiculo cadastrado.\n";
        return;
    }

    for (int i = 0; i < veiculos.size(); i++) {
        cout << "\n[Indice " << i << "]\n";
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
        cout << "\n--- MENU VEICULOS ---\n";
        cout << "1 - Adicionar Veiculo\n";
        cout << "2 - Remover Veiculo\n";
        cout << "3 - Atualizar Veiculo\n";
        cout << "4 - Listar Veiculos\n";
        cout << "5 - Backup de dados\n";
        cout << "6 - Restaurar dados\n";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: 
                AdicionarVeiculo(veiculos); 
                break;
            case 2: 
                RemoverVeiculo(veiculos); 
                break;
            case 3: 
                AtualizarVeiculo(veiculos); 
                break;
            case 4: 
                ListarVeiculos(veiculos); 
                break;
            case 5: 
                SalvarEmArquivo(veiculos); 
                break;
            case 6: 
                RestaurarDeArquivo(veiculos); 
                break;
            case 0: 
                cout << "Voltando ao menu principal...\n"; 
                break;
            default: 
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}
