#include <iostream>
#include <vector>
#include "Services/VeiculoService.h"

int main() {
    std::vector<Veiculo> veiculos;
    int opcao;

    do {
        std::cout << "\n==== MENU VEÍCULOS ====\n";
        std::cout << "1 - Adicionar Veículo\n";
        std::cout << "2 - Remover Veículo\n";
        std::cout << "3 - Atualizar Veículo\n";
        std::cout << "4 - Listar Veículos\n";
        std::cout << "5 - Backup de dados\n";
        std::cout << "6 - Restaurar dados\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: AdicionarVeiculo(veiculos); break;
            case 2: RemoverVeiculo(veiculos); break;
            case 3: AtualizarVeiculo(veiculos); break;
            case 4: ListarVeiculos(veiculos); break;
            case 5: SalvarEmArquivo(veiculos); break;
            case 6: RestaurarDeArquivo(veiculos); break;
            case 0: std::cout << "Saindo...\n"; break;
            default: std::cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
