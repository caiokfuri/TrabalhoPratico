#include "cabecalhos.h"
#include "Services/VeiculoService.h"
#include "Services/LocalService.h"
#include "Services/PedidoService.h"
#include <locale>


using namespace std;

int main() {
    // setlocale(LC_ALL, "Portuguese_Brazil");
    int opt = 0;
    vector<Veiculo> veiculos;
    vector<Local> locais;
    vector<Pedido> pedidos;
    // vector<pedido> pedidos;

    do {
        cout << "--- MENU PRINCIPAL ---" << endl;
        cout << "1 - Menu Locais" << endl;
        cout << "2 - Menu Veículos" << endl;
        cout << "3 - Menu Pedidos" << endl;
        cout << "4 - Visualizar rota de entrega" << endl;
        cout << "5 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opt;

        switch(opt) {
            case 1:
                cout << "Menu locais" << endl;
                menuLocais(locais);
                break;
            case 2:
            cout << "Menu Veiculos" << endl;
                menuVeiculos(veiculos);
                break;
            case 3:
                cout << "Voce escolheu o Menu Pedidos." << endl;
                menuPedidos(pedidos);
                break;
            case 4:
                // Funçao de cálculo e mostrar rota de entrega, já atualizando os veiculos e locais
                break;
            case 5:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
        cout << endl;
    } while(opt != 5);

    return 0;
}