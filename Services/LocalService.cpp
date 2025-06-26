#include "LocalService.h"
#include <iostream>

using namespace std;

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
    cout << "Local adicionado com sucesso!\n";
}

void RemoverLocal(vector<Local>& locais) {
    if (locais.empty()) {
        cout << "Nenhum local cadastrado.\n";
        return;
    }
    cout << "Digite o nome do local para remover: ";
    cin.ignore();
    char nomeBusca[50];
    cin.getline(nomeBusca, 50);

    bool removido = false;
    for (int i = 0; i < locais.size(); i++) {
        if (strcmp(locais[i].getNome(), nomeBusca) == 0) {
            locais.erase(locais.begin() + i);
            cout << "Removido com sucesso.\n";
            removido = true;
            break;
        }
    }
    if (!removido) {
        cout << "Local nao encontrado.\n";
    }
}

void ListarLocais(const vector<Local>& locais) {
    if (locais.empty()) {
        cout << "Nenhum local cadastrado.\n";
        return;
    }
    for (int i = 0; i < locais.size(); i++) {
        cout << "\n[Local " << i + 1 << "]\n";
        locais[i].mostrar();
    }
}

void AtualizarLocal(vector<Local>& locais) {
    if (locais.empty()) {
        cout << "Nenhum local cadastrado.\n";
        return;
    }

    ListarLocais(locais);

    cout << "Digite o ID do local que deseja atualizar: ";
    int id;
    cin >> id;

    if (id < 0 || id >= locais.size()) {
        cout << "ID inválido.\n";
        return;
    }

    int opcao;
    do {
        cout << "\nO que deseja alterar?\n";
        cout << "1 - Nome\n";
        cout << "2 - Coordenada X\n";
        cout << "3 - Coordenada Y\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: {
                cout << "Novo nome: ";
                char novoNome[50];
                cin.getline(novoNome, 50);
                locais[id].setNome(novoNome);
                cout << "Nome atualizado!\n";
                break;
            }
            case 2: {
                cout << "Nova coordenada X: ";
                double novoX;
                cin >> novoX;
                locais[id].setX(novoX);
                cout << "Coordenada X atualizada!\n";
                break;
            }
            case 3: {
                cout << "Nova coordenada Y: ";
                double novoY;
                cin >> novoY;
                locais[id].setY(novoY);
                cout << "Coordenada Y atualizada!\n";
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

