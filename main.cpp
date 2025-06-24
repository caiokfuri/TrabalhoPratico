#include "cabecalhos.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opt = 0;

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
                break;
            case 2:
                cout << "Você escolheu o Menu Veículos." << endl;
                break;
            case 3:
                cout << "Você escolheu o Menu Pedidos." << endl;

                break;
            case 4:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
        cout << endl;
    } while(opt != 4);
}