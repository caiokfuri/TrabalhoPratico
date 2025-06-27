#include "PedidoService.h"
#include <iostream>

using namespace std;


void Pedido::entrada() {
    cout << "ID do Pedido: ";
    cin >> pedidoId;
    cout << "--- Local de Origem ---" << endl;
    localOrigem.entrada();
    cout << "--- Local de Destino ---" << endl;
    localDestino.entrada();
    cout << "Peso: ";
    cin >> peso;
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

Local& Pedido::getLocalOrigem() {
    return localOrigem;
}

Local& Pedido::getLocalDestino() {
    return localDestino;
}


void menuPedidos(vector<Pedido>& pedidos) {
    int opcao;
    do {
        cout << "\n--- MENU PEDIDOS ---\n";
        cout << "1 - Adicionar Pedido" << endl;
        cout << "2 - Remover Pedido" << endl;
        cout << "3 - Atualizar Pedido" << endl;
        cout << "4 - Listar Pedidos" << endl;
        cout << "0 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: 
                AdicionarPedido(pedidos); 
                break;
            case 2: 
                RemoverPedido(pedidos); 
                break;
            case 3: 
                AtualizarPedido(pedidos); 
                break;
            case 4: 
                ListarPedidos(pedidos); 
                break;
            case 0: 
                cout << "Voltando...\n"; 
                break;
            default: 
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void AdicionarPedido(vector<Pedido>& pedidos) {
    Pedido pedido;
    pedido.entrada();
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


void AtualizarPedido(vector<Pedido>& pedidos) {
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
            case 1:
                cout << "Alterando Local de Origem:\n";
                //SET LOCAL DE ORIGEM
                break;
            case 2:
                cout << "Alterando Local de Destino:\n";
                //SET LOCAL DE DESTINO
                break;
            case 3: {
                //SET PESO
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