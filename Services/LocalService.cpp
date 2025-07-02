#include "LocalService.h"
#include "DataService.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

void Local::entrada() {
    cout << "Nome do local: " << endl;
    cin.ignore();
    getline(cin, nome);
    cout << "Coordenada X: " << endl;
    cin >> x;
    cout << "Coordenada Y: " << endl;
    cin >> y;
}

void Local::mostrar() const {
    cout << "Nome: " << nome << "\nX: " << x << "\nY: " << y << endl;
}

string Local::getNome() const { return nome; }
double Local::getX() const { return x; }
double Local::getY() const { return y; }
void Local::setNome(const string& novoNome) { nome = novoNome; }
void Local::setX(double novoX) { x = novoX; }
void Local::setY(double novoY) { y = novoY; }

void backupLocais(const vector<Local>& locais) {
    cout << "Iniciando backup de locais..." << endl;

    if (DataService::salvarLocais(locais)) {
        cout << "Backup realizado com sucesso!" << endl;
        cout << "Total de locais salvos: " << locais.size() << endl;
    } else {
        cout << "Erro ao realizar backup dos locais!" << endl;
    }
}

void restaurarLocais(vector<Local>& locais) {
    if (!locais.empty()) {
        char opcao;
        cout << "Existem " << locais.size() << " locais cadastrados." << endl;
        cout << "Deseja sobrescrever os dados atuais? (S/N): ";
        cin >> opcao;
        if (opcao != 's' && opcao != 'S') {
            cout << "Restauração cancelada." << endl;
            return;
        }
    }

    cout << "Iniciando restauração de locais..." << endl;

    if (DataService::carregarLocais(locais)) {
        cout << "Dados restaurados com sucesso!" << endl;
        cout << "Total de locais restaurados: " << locais.size() << endl;
    } else {
        cout << "Erro ao restaurar dados dos locais!" << endl;
        cout << "Verifique se existe um arquivo de backup válido." << endl;
    }
}

void menuLocais(vector<Local>& locais) {
    int opcao;
    do {
        cout << "\n--- MENU LOCAIS ---\n";
        cout << "1 - Adicionar Local" << endl;
        cout << "2 - Remover Local" << endl;
        cout << "3 - Atualizar Local" << endl;
        cout << "4 - Listar Locais" << endl;
        cout << "5 - Backup de dados" << endl;
        cout << "6 - Restaurar dados" << endl;
        cout << "0 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                AdicionarLocal(locais);
                break;
            case 2:
                RemoverLocal(locais);
                break;
            case 3:
                system("cls");
                AtualizarLocal(locais);
                break;
            case 4:
                system("cls");
                ListarLocais(locais);
                break;
            case 5:
                backupLocais(locais);
                break;
            case 6:
                restaurarLocais(locais);
                break;
            case 0:
                cout << "Voltando...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void AdicionarLocal(vector<Local>& locais) {
    system("cls");
    Local l;
    l.entrada();
    locais.push_back(l);
    cout << "Local adicionado com sucesso!" << endl;
}

void RemoverLocal(vector<Local>& locais) {
    system("cls");
    string nomeBusca;
    if (locais.empty()) {
        cout << "Nenhum local cadastrado.\n" << endl;
        return;
    }
    cout << "Digite o nome do local para remover: " << endl;
    cin.ignore();
    getline(cin, nomeBusca);

    bool removido = false;
    for (int i = 0; i < (int)locais.size(); i++) {
        if (locais[i].getNome() == nomeBusca) {
            locais.erase(locais.begin() + i);
            cout << "Local removido com sucesso." << endl;
            removido = true;
            break;
        }
    }
    if (!removido) {
        cout << "Local nao encontrado." << endl;
    }
}

void ListarLocais(const vector<Local>& locais) {
    if (locais.empty()) {
        cout << "Nenhum local cadastrado." << endl;
        return;
    }
    for (int i = 0; i < (int)locais.size(); i++) {
        cout << "\n[Local " << i + 1 << "]\n";
        locais[i].mostrar();
    }
}

void AtualizarLocal(vector<Local>& locais) {
    system("cls");
    if (locais.empty()) {
        cout << "Nenhum local cadastrado." << endl;
        return;
    }

    ListarLocais(locais);

    cout << "Digite o ID do local que deseja atualizar: " << endl;
    int id;
    cin >> id;

    if (id <= 0 || id > (int)locais.size()) {
        cout << "ID inválido." << endl;
        return;
    }

    id--;

    int opcao;
    do {
        cout << "\nO que deseja alterar?\n";
        cout << "1 - Nome" << endl;
        cout << "2 - Coordenada X" << endl;
        cout << "3 - Coordenada Y" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: " << endl;
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: {
                cout << "Novo nome: ";
                string novoNome;
                getline(cin, novoNome);
                locais[id].setNome(novoNome);
                cout << "Nome atualizado!" << endl;
                break;
            }
            case 2: {
                cout << "Nova coordenada X: ";
                double novoX;
                cin >> novoX;
                locais[id].setX(novoX);
                cout << "Coordenada X atualizada!" << endl;
                break;
            }
            case 3: {
                cout << "Nova coordenada Y: ";
                double novoY;
                cin >> novoY;
                locais[id].setY(novoY);
                cout << "Coordenada Y atualizada!" << endl;
                break;
            }
            case 0:
                cout << "Saindo da atualização." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 0);
}