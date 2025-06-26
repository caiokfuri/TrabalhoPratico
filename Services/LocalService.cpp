#include "LocalService.h"
#include <iostream>

using namespace std;

void menuLocais(vector<Local>& locais) {
    int opcao;
    do {
        cout << "\n--- MENU LOCAIS ---\n";
        cout << "1 - Adicionar Local\n";
        cout << "2 - Remover Local\n";
        cout << "3 - Atualizar Local\n";
        cout << "4 - Listar Locais\n";
        cout << "5 - Backup de dados";
        cout << "6 - Restaurar dados";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: AdicionarLocal(locais); break;
            case 2: RemoverLocal(locais); break;
            case 3: AtualizarLocal(locais); break;
            case 4: ListarLocais(locais); break;
            case 5: /*backupDados() */ ; break;
            case 6: /*restaurarDado()*/ ; break;
            case 0: cout << "Voltando...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void AdicionarLocal(vector<Local>& locais) {
    Local l;
    l.preencher();
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
        cout << "Local não encontrado.\n";
    }
}

void AtualizarLocal(vector<Local>& locais) {
    if (locais.empty()) {
        cout << "Nenhum local cadastrado.\n";
        return;
    }
    cout << "Digite o nome do local para atualizar: ";
    cin.ignore();
    char nomeBusca[50];
    cin.getline(nomeBusca, 50);

    bool atualizado = false;
    for (int i = 0; i < locais.size(); i++) {
        if (strcmp(locais[i].getNome(), nomeBusca) == 0) {
            locais[i].preencher();
            cout << "Atualizado com sucesso.\n";
            atualizado = true;
            break;
        }
    }
    if (!atualizado) {
        cout << "Local não encontrado.\n";
    }
}

void ListarLocais(const vector<Local>& locais) {
    if (locais.empty()) {
        cout << "Nenhum local cadastrado.\n";
        return;
    }
    for (int i = 0; i < locais.size(); i++) {
        cout << "\n[Índice " << i << "]\n";
        locais[i].mostrar();
    }
}