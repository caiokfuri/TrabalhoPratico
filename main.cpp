#include "cabecalhos.h"
#include "Services/VeiculoService.h"
#include "Services/LocalService.h"
#include "Services/PedidoService.h"
#include "Services/EntregaService.h"
#include "Services/DataService.h"



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
        cout << "5 - Backup dos dados" << endl;
        cout << "6 - Restaurar dados" << endl;
        cout << "7 - Sair" << endl;
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
                break;
            case 5:
                try {
                    system("cls");

                    DataService::salvarVeiculos(veiculos);
                    DataService::salvarPedidos(pedidos);
                    DataService::salvarLocais(locais);
                    cout << "Dados salvos com sucesso" << endl;
                }
                catch (exception& e) {
                    cout << e.what() << endl;
                }
                break;
            case 6:
                try {
                    system("cls");
                    DataService::carregarVeiculos(veiculos);
                    DataService::carregarPedidos(pedidos);
                    DataService::carregarLocais(locais);
                    cout << "Dados restaurados com sucesso" << endl;
                }
                catch (exception& e) {
                    cout << e.what() << endl;
                }


                break;
            case 7:
                system("cls");
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
        cout << endl;
    } while(opt != 7);

    return 0;
}