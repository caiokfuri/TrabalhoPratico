#include <iostream>
#include <vector>
#include "Services/VeiculoService.h"
#include "Services/LocalService.h"

using namespace std;

int main() {
    // Arrumar MENUS
    vector<Veiculo> veiculos;
    int opcao;

    do {
        cout << "\n==== MENU VEÍCULOS ====\n";
        cout << "1 - Adicionar Veículo\n";
        cout << "2 - Remover Veículo\n";
        cout << "3 - Atualizar Veículo\n";
        cout << "4 - Listar Veículos\n";
        cout << "5 - Backup de dados\n";
        cout << "6 - Restaurar dados\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: AdicionarVeiculo(veiculos); break;
            case 2: RemoverVeiculo(veiculos); break;
            case 3: AtualizarVeiculo(veiculos); break;
            case 4: ListarVeiculos(veiculos); break;
            case 5: SalvarEmArquivo(veiculos); break;
            case 6: RestaurarDeArquivo(veiculos); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
