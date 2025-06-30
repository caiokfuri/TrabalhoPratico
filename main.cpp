#include "cabecalhos.h"
#include "Services/VeiculoService.h"
#include "Services/LocalService.h"
#include "Services/PedidoService.h"
#include "Services/EntregaService.h"


using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
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
                system("cls");
                menuLocais(locais);
                break;
            case 2:
                system("cls");
                menuVeiculos(veiculos);
                break;
            case 3:
                system("cls");
                menuPedidos(pedidos);
                break;
            case 4:
                system("cls");
                processarEntrega(veiculos, locais, pedidos);
                // Funçao de cálculo e mostrar rota de entrega, já atualizando os veiculos e locais
                break;
            case 5:
                system("clear");
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
        cout << endl;
    } while(opt != 5);

    return 0;
}