#include "cabecalhos.h"
#include "Services/VeiculoService.h"
#include "Services/LocalService.h"
#include "Services/PedidoService.h"


using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int opt = 0;
    vector<Veiculo> veiculos;
    vector<Local> locais;
    vector<PedidoModel> pedidos;
    // vector<pedido> pedidos;

    do {
        cout << "===== MENU PRINCIPAL =====" << endl;
        cout << "1 - Menu Locais" << endl;
        cout << "2 - Menu Veículos" << endl;
        cout << "3 - Menu Pedidos" << endl;
        cout << "4 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opt;

        switch(opt) {
            case 1:
                cout << "Você escolheu o Menu Locais." << endl;
                menuLocais(locais);
                break;
            case 2:
                menuVeiculos(veiculos);
                break;
            case 3:
                cout << "Você escolheu o Menu Pedidos." << endl;
                menuPedidos(pedidos);
                break;
            case 4:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
        cout << endl;
    } while(opt != 4);

    return 0;
}