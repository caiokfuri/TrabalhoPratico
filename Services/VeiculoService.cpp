#include "VeiculoService.h"
#include <iostream>
#include <cstdio>

using namespace std;

void Veiculo::entrada() {
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

void Veiculo::setLocalAtual(const string& novoLocal) {
    localAtual = novoLocal;
}

void Veiculo::setPlaca(const string& novaPlaca) {
    placa = novaPlaca;
}

void Veiculo::setModelo(const string& novoModelo) {
    modelo = novoModelo;
}

const string& Veiculo::getPlaca() const { return placa; }
const string& Veiculo::getModelo() const { return modelo; }
const string& Veiculo::getLocalAtual() const { return localAtual; }
int Veiculo::getStatus() const { return status; }

void Veiculo::salvar(FILE* file) const {
    fwrite(this, sizeof(Veiculo), 1, file);
}

bool Veiculo::carregar(FILE* file) {
    return fread(this, sizeof(Veiculo), 1, file) == 1;
}

void AdicionarVeiculo(vector<Veiculo>& veiculos) {
    Veiculo v;
    v.entrada();
    veiculos.push_back(v);
    cout << "Veículo adicionado com sucesso!\n";
}

void RemoverVeiculo(vector<Veiculo>& veiculos) {
    ListarVeiculos(veiculos);
    if (veiculos.empty()) return;

    cout << "Digite o índice para remover: ";
    int i;
    cin >> i;

    if (i >= 0 && i < static_cast<int>(veiculos.size())) {
        veiculos.erase(veiculos.begin() + i);
        cout << "Removido com sucesso.\n";
    } else {
        cout << "Índice inválido.\n";
    }
}

void AtualizarVeiculo(vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veículo cadastrado.\n";
        return;
    }

    ListarVeiculos(veiculos);

    cout << "Digite o índice do veículo que deseja atualizar: ";
    int i;
    cin >> i;

    if (i < 0 || i >= static_cast<int>(veiculos.size())) {
        cout << "Índice inválido.\n";
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
        cout << "Escolha uma opção: ";
        cin >> opcao;

        cin.ignore(); // limpar o buffer antes de getline

        switch (opcao) {
            case 1: {
                cout << "Nova placa: ";
                char novaPlaca[8];
                cin.getline(novaPlaca, 8);
                veiculos[i].setPlaca(novaPlaca); // ✅ IMPLEMENTADO
                cout << "Placa atualizada!\n";
                break;
            }
            case 2: {
                cout << "Novo modelo: ";
                char novoModelo[50];
                cin.getline(novoModelo, 50);
                veiculos[i].setModelo(novoModelo); // ✅ IMPLEMENTADO
                cout << "Modelo atualizado!\n";
                break;
            }
            case 3: {
                cout << "Novo status (0 - Disponível, 1 - Ocupado): ";
                int novoStatus;
                cin >> novoStatus;
                veiculos[i].setStatus(novoStatus);
                cout << "Status atualizado!\n";
                break;
            }
            case 4: {
                cout << "Novo local atual: ";
                char novoLocal[50];
                cin.getline(novoLocal, 50);
                veiculos[i].setLocalAtual(novoLocal);
                cout << "Local atual atualizado!\n";
                break;
            }
            case 0:
                cout << "Saindo da atualizacao.\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void ListarVeiculos(const vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veículo cadastrado.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(veiculos.size()); i++) {
        cout << "\nVeículo " << i << "]\n";
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
