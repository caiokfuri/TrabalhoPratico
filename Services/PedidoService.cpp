#include "PedidoService.h"
#include <iostream>

using namespace std;

void menuLocais(vector<PedidoModel>& pedidos) {
    int opcao;
    do {
        cout << "\n==== MENU PEDIDOS ====\n";
        cout << "1 - Adicionar Pedido\n";
        cout << "2 - Remover Pedido\n";
        cout << "3 - Atualizar Pedido\n";
        cout << "4 - Listar Pedidos\n";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: AdicionarPedido(pedidos); break;
            case 2: RemoverPedido(pedidos); break;
            case 3: AtualizarPedido(pedidos); break;
            case 4: ListarPedidos(pedidos); break;
            case 0: cout << "Voltando...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void AdicionarPedido(vector<PedidoModel>& pedidos) {
    PedidoModel pedido;
    pedido.preencher();
    pedidos.push_back(pedido);
    cout << "Pedido adicionado com sucesso!\n";
}

void RemoverPedido(vector<PedidoModel>& pedidos) {
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


void AtualizarPedido(vector<PedidoModel>& pedidos) {
    if (pedidos.empty()) {
        cout << "Nenhum Pedido cadastrado.\n";
        return;
    }

    cout << "Digite o ID do pedido para atualizar: ";
    int idBusca;
    cin >> idBusca;

    bool atualizado = false;
    for (auto& pedido : pedidos) {
        if (pedido.getId() == idBusca) {
            cout << "Preencha os novos dados do pedido:\n";
            pedido.preencher();
            cout << "Pedido atualizado com sucesso.\n";
            atualizado = true;
            break;
        }
    }

    if (!atualizado) {
        cout << "Pedido com ID " << idBusca << " não encontrado.\n";
    }
}


void ListarPedidos(const vector<PedidoModel>& pedidos) {
    if (pedidos.empty()) {
        cout << "Nenhum pedido cadastrado.\n";
        return;
    }
    for (int i = 0; i < pedidos.size(); i++) {
        cout << "\n[Índice " << i << "]\n";
        pedidos[i].mostrar();
    }
}