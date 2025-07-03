#include "PedidoService.h"
#include "DataService.h"
#include <iostream>

#include "LocalService.h"

using namespace std;

void Pedido::entrada(vector<Local>& locais) {
    cout << "ID do Pedido: ";
    int id;
    cin >> id;

    cin.ignore();
    cout << "--- Local de Origem ---" << endl;
    localOrigem = BuscarLocalPorNome(locais);
    if (localOrigem.getNome() == "") {
        cout << "Cancelando operação..." << endl;
        _sleep(1500);
        return;
    }

    cout << "--- Local de Destino ---" << endl;
    localDestino = BuscarLocalPorNome(locais);
    if (localDestino.getNome() == "") {
        cout << "Cancelando operação..." << endl;
        _sleep(1500);
        return;
    }

    cout << "Peso: ";
    cin >> peso;
    pedidoId = id;
}

void Pedido::mostrar() const {
    cout << "\nPedido ID: " << pedidoId << endl;
    cout << "Origem:" << endl;
    localOrigem.mostrar();
    cout << "Destino:" << endl;
    localDestino.mostrar();
    cout << "Peso: " << peso << " kg" << endl;
}

int Pedido::getId() const {
    return pedidoId;
}

void Pedido::setId(int id) {
    this->pedidoId = id;
}

Local& Pedido::getLocalOrigem() {
    return localOrigem;
}

void Pedido::setLocalOrigem(Local origem) {
    this->localOrigem = origem;
}

Local& Pedido::getLocalDestino() {
    return localDestino;
}

void Pedido::setLocalDestino(Local destino) {
    this->localDestino = destino;
}

double Pedido::getPeso() const {
    return peso;
}

void Pedido::setPeso(double peso) {
    this->peso = peso;
}

void backupPedidos(const vector<Pedido>& pedidos) {
    cout << "Iniciando backup de pedidos..." << endl;

    if (DataService::salvarPedidos(pedidos)) {
        cout << "Backup realizado com sucesso!" << endl;
        cout << "Total de pedidos salvos: " << pedidos.size() << endl;
    } else {
        cout << "Erro ao realizar backup dos pedidos!" << endl;
    }
}

void restaurarPedidos(vector<Pedido>& pedidos) {
    if (!pedidos.empty()) {
        char opcao;
        cout << "Existem " << pedidos.size() << " pedidos cadastrados." << endl;
        cout << "Deseja sobrescrever os dados atuais? (S/N): ";
        cin >> opcao;
        if (opcao != 's' && opcao != 'S') {
            cout << "Restauração cancelada." << endl;
            return;
        }
    }

    cout << "Iniciando restauração de pedidos..." << endl;

    if (DataService::carregarPedidos(pedidos)) {
        cout << "Dados restaurados com sucesso!" << endl;
        cout << "Total de pedidos restaurados: " << pedidos.size() << endl;
    } else {
        cout << "Erro ao restaurar dados dos pedidos!" << endl;
        cout << "Verifique se existe um arquivo de backup válido." << endl;
    }
}

void menuPedidos(vector<Pedido>& pedidos, vector<Local>& locais) {
    system("cls");
    int opcao;
    do {
        cout << "\n--- MENU PEDIDOS ---\n";
        cout << "1 - Adicionar Pedido" << endl;
        cout << "2 - Remover Pedido" << endl;
        cout << "3 - Atualizar Pedido" << endl;
        cout << "4 - Listar Pedidos" << endl;
        cout << "5 - Backup de dados" << endl;
        cout << "6 - Restaurar dados" << endl;
        cout << "0 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                AdicionarPedido(pedidos,locais);
                break;
            case 2:
                RemoverPedido(pedidos);
                break;
            case 3:
                AtualizarPedido(pedidos,locais);
                break;
            case 4:
                ListarPedidos(pedidos);
                break;
            case 5:
                backupPedidos(pedidos);
                break;
            case 6:
                restaurarPedidos(pedidos);
                break;
            case 0:
                cout << "Voltando...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void AdicionarPedido(vector<Pedido>& pedidos,vector<Local>& locais) {
    Pedido pedido;
    pedido.entrada(locais);
    if (pedido.getId() == 0) {
        return;
    }
    pedidos.push_back(pedido);
    cout << "Pedido adicionado com sucesso!\n";
}

void RemoverPedido(vector<Pedido>& pedidos) {
    if (pedidos.empty()) {
        cout << "Nenhum Pedido cadastrado.\n";
        return;
    }

    cout << "Digite o ID do pedido para remover: ";
    int idBusca;
    cin >> idBusca;

    bool removido = false;
    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].getId() == idBusca) {
            pedidos.erase(pedidos.begin() + i);
            cout << "Pedido removido com sucesso.\n";
            removido = true;
            break;
        }
    }

    if (!removido) {
        cout << "Pedido com ID " << idBusca << " não encontrado.\n";
    }
}

void AtualizarPedido(vector<Pedido>& pedidos,vector<Local>& locais) {
    if (pedidos.empty()) {
        cout << "Nenhum pedido cadastrado.\n";
        return;
    }

    ListarPedidos(pedidos);

    cout << "Digite o ID do pedido que deseja atualizar: ";
    int idBusca;
    cin >> idBusca;

    int indice = -1;
    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].getId() == idBusca) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "ID não encontrado.\n";
        return;
    }

    int opcao;
    do {
        cout << "\nO que deseja alterar?\n";
        cout << "1 - Local de Origem\n";
        cout << "2 - Local de Destino\n";
        cout << "3 - Peso\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: {
                cout << "Alterando Local de Origem:\n";
                Local novaOrigem;
                novaOrigem = BuscarLocalPorNome(locais);
                pedidos[indice].setLocalOrigem(novaOrigem);
                cout << "Local de origem atualizado!\n";
                break;
            }
            case 2: {
                cout << "Alterando Local de Destino:\n";
                Local novoDestino;
                novoDestino = BuscarLocalPorNome(locais);
                pedidos[indice].setLocalDestino(novoDestino);
                cout << "Local de destino atualizado!\n";
                break;
            }
            case 3: {
                cout << "Novo peso: ";
                double novoPeso;
                cin >> novoPeso;
                pedidos[indice].setPeso(novoPeso);
                cout << "Peso atualizado!\n";
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

void ListarPedidos(const vector<Pedido>& pedidos) {
    if (pedidos.empty()) {
        cout << "Nenhum pedido cadastrado.\n";
        return;
    }
    for (int i = 0; i < pedidos.size(); i++) {
        cout << "\n[Pedido " << i + 1 << "]\n";
        pedidos[i].mostrar();
    }
}