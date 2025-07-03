#include "VeiculoService.h"
#include "LocalService.h"
#include "DataService.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool validarPlaca(const string& placa) {
    if (placa.length() != 7) {
        cout << "A placa deve ter exatamente 7 caracteres!" << endl;
        return false;
    }
    return true;
}

bool validarLocalExiste(const string& nomeLocal, const vector<Local>& locais) {
    if (locais.empty()) {
        cout << "Nenhum local encontrado, deve existir um local para o cadastro de veículo!" << endl;
        return false;
    }

    for (const Local& local : locais) {
        if (local.getNome() == nomeLocal) {
            return true;
        }
    }

    cout << "ERRO: Local '" << nomeLocal << "' não encontrado!" << endl;
    cout << "Locais disponíveis:" << endl;
    for (size_t i = 0; i < locais.size(); i++) {
        cout << "- " << locais[i].getNome() << endl;
    }
    return false;
}

void Veiculo::entrada(const vector<Local>& locais) {
    bool placaValida;
    do {
        cout << "Placa (exatamente 7 caracteres): ";
        cin >> placa;
        placaValida = validarPlaca(placa);
        if (!placaValida) {
            cout << "Tente novamente." << endl;
        }
    } while (!placaValida);

    cout << "Modelo: ";
    cin >> modelo;

    cin.ignore();

    bool localValido;
    do {
        cout << "Local Atual: ";
        getline(cin, localAtual);
        localValido = validarLocalExiste(localAtual, locais);
        if (!localValido) {
            cout << "Tente novamente." << endl;
        }
    } while (!localValido);

    status = 0;
}

void Veiculo::mostrar() const {
    cout << "Placa: " << placa
         << "\nModelo: " << modelo
         << "\nStatus: " << (status == 0 ? "Disponível" : "Ocupado")
         << "\nLocal Atual: " << localAtual << "\n";
}

void Veiculo::setStatus(int novoStatus) { status = novoStatus; }

void Veiculo::setLocalAtual(const string& novoLocal) { localAtual = novoLocal; }

bool Veiculo::setPlaca(const string& novaPlaca) {
    if (validarPlaca(novaPlaca)) {
        placa = novaPlaca;
        return true;
    }
    return false;
}

void Veiculo::setModelo(const string& novoModelo) { modelo = novoModelo; }

const string& Veiculo::getPlaca() const { return placa; }
const string& Veiculo::getModelo() const { return modelo; }
const string& Veiculo::getLocalAtual() const { return localAtual; }
int Veiculo::getStatus() const { return status; }

void AdicionarVeiculo(vector<Veiculo>& frota, const vector<Local>& locais) {
    if (locais.empty()) {
        cout << "ERRO: Nenhum local cadastrado!" << endl;
        cout << "Cadastre pelo menos um local antes de adicionar veículos." << endl;
        return;
    }

    Veiculo v;
    v.entrada(locais);
    frota.push_back(v);
    cout << "Veículo adicionado com sucesso!\n";
}

void RemoverVeiculo(vector<Veiculo>& frota) {
    ListarVeiculos(frota);
    if (frota.empty()) return;

    cout << "Digite o código do veículo para remover: ";
    int i;
    cin >> i;
    i--;

    if (i >= 0 && i < frota.size()) {
        frota.erase(frota.begin() + i);
        cout << "Removido com sucesso.\n";
    } else {
        cout << "Código inválido.\n";
    }
}

void AtualizarVeiculo(vector<Veiculo>& frota, const vector<Local>& locais) {
    if (frota.empty()) {
        cout << "Nenhum veículo cadastrado.\n";
        return;
    }

    ListarVeiculos(frota);
    cout << "Digite o código do veículo que deseja atualizar: ";
    int i;
    cin >> i;
    i--;

    if (i < 0 || i >= frota.size()) {
        cout << "Código inválido.\n";
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
        cin.ignore();

        switch (opcao) {
            case 1: {
                string novaPlaca;
                bool placaValida;
                do {
                    cout << "Nova placa (exatamente 7 caracteres): ";
                    getline(cin, novaPlaca);
                    placaValida = validarPlaca(novaPlaca);
                    if (!placaValida) {
                        cout << "Tente novamente." << endl;
                    }
                } while (!placaValida);
                frota[i].setPlaca(novaPlaca);
                cout << "Placa atualizada!\n";
                break;
            }
            case 2: {
                cout << "Novo modelo: ";
                string novoModelo;
                getline(cin, novoModelo);
                frota[i].setModelo(novoModelo);
                cout << "Modelo atualizado!\n";
                break;
            }
            case 3: {
                cout << "Novo status (0 - Disponível, 1 - Ocupado): ";
                int novoStatus;
                cin >> novoStatus;
                frota[i].setStatus(novoStatus);
                cout << "Status atualizado!\n";
                break;
            }
            case 4: {
                string novoLocal;
                bool localValido;
                do {
                    cout << "Novo local atual: ";
                    getline(cin, novoLocal);
                    localValido = validarLocalExiste(novoLocal, locais);
                    if (!localValido) {
                        cout << "Tente novamente." << endl;
                    }
                } while (!localValido);
                frota[i].setLocalAtual(novoLocal);
                cout << "Local atual atualizado!\n";
                break;
            }
            case 0:
                cout << "Saindo da atualização.\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void ListarVeiculos(const vector<Veiculo>& frota) {
    if (frota.empty()) {
        cout << "Nenhum veículo cadastrado.\n";
        return;
    }

    for (int i = 0; i < frota.size(); i++) {
        cout << "\n[Veículo " << i + 1 << "]\n";
        frota[i].mostrar();
    }
}

void SalvarEmArquivo(const vector<Veiculo>& frota) {
    if (DataService::salvarVeiculos(frota)) {
        cout << "Backup dos veículos realizado com sucesso!\n";
    } else {
        cout << "Erro ao realizar backup dos veículos.\n";
    }
}

void RestaurarDeArquivo(vector<Veiculo>& frota) {
    if (!frota.empty()) {
        char opcao;
        cout << "Existem " << frota.size() << " veículos cadastrados." << endl;
        cout << "Deseja sobrescrever os dados atuais? (S/N): ";
        cin >> opcao;
        if (opcao != 's' && opcao != 'S') {
            cout << "Restauração cancelada." << endl;
            return;
        }
    }

    cout << "Iniciando restauração de veículos..." << endl;

    if (DataService::carregarVeiculos(frota)) {
        cout << "Dados restaurados com sucesso!" << endl;
        cout << "Total de veículos restaurados: " << frota.size() << endl;
    } else {
        cout << "Erro ao restaurar dados dos veículos!" << endl;
        cout << "Verifique se existe um arquivo de backup válido." << endl;
    }
}

void menuVeiculos(vector<Veiculo>& frota, const vector<Local>& locais) {
    system("cls");
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
            case 1:
                AdicionarVeiculo(frota, locais);
                break;
            case 2:
                RemoverVeiculo(frota);
                break;
            case 3:
                AtualizarVeiculo(frota, locais);
                break;
            case 4:
                ListarVeiculos(frota);
                break;
            case 5:
                SalvarEmArquivo(frota);
                break;
            case 6:
                RestaurarDeArquivo(frota);
                break;
            case 0:
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}