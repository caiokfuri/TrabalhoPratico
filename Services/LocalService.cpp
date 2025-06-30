#include "LocalService.h"
#include <iostream>



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

void Local::setNome(const string& novoNome) { nome = novoNome; }
void Local::setX(double novoX) { x = novoX; }
void Local::setY(double novoY) { y = novoY; }
string Local::getNome() const { return nome; }
double Local::getX() const { return x; }
double Local::getY() const { return y; }


void menuLocais(vector<Local>& locais) {
    system("cls");
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
                AtualizarLocal(locais);
                break;
            case 4: 
                ListarLocais(locais); 
                break;
            case 5: 
                /*backupDados() */ ; 
                break;
            case 6: 
                /*restaurarDado()*/ ; 
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
    Local l;
    l.entrada();
    locais.push_back(l);
    cout << "Local adicionado com sucesso!" << endl;
}

void RemoverLocal(vector<Local>& locais) {
    string nomeBusca;
    if (locais.empty()) {
        cout << "Nenhum local cadastrado.\n" << endl;
        return;
    }
    cout << "Digite o nome do local para remover: " << endl;
    cin.ignore();
    getline(cin, nomeBusca);

    bool removido = false;
    for (int i = 0; i < locais.size(); i++) {
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
    for (int i = 0; i < locais.size(); i++) {
        cout << "\n[Local " << i + 1 << "]\n";
        locais[i].mostrar();
    }
}

void AtualizarLocal(vector<Local>& locais) {
    if (locais.empty()) {
        cout << "Nenhum local cadastrado." << endl;
        return;
    }

    ListarLocais(locais);

    cout << "Digite o ID do local que deseja atualizar: " << endl;
    int id;
    cin >> id;

    if (id < 0 || id >= locais.size()) {
        cout << "ID inválido." << endl;
        return;
    }

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

