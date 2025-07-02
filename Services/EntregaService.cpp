#include "../cabecalhos.h"
#include <cmath>
#include "EntregaService.h"
#include "PedidoService.h"

double calculoDistancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) );
}

double CalcularDistanciaEntrega(const Local& origem, const Local& destino)
{
    return calculoDistancia(origem.getX(), origem.getY(), destino.getX(), destino.getY());
}

Veiculo* veiculoMaisProximo(vector<Veiculo>& frota, const Local& localOrigem, const vector<Local>& locais) {
    double minDistancia;
    bool primeiroVeiculo = true;
    Veiculo* veiculoMaisProximo = nullptr;

    if (frota.empty())
    {
        cout << "Nenhum veículo cadastrado na frota!" << endl;
    }

    for(int i = 0; i < frota.size(); i++) {
        if(frota[i].getStatus() == 0) {
            Local localVeiculo;
            for(int j = 0; j < locais.size(); j++) {
                if(locais[j].getNome() == frota[i].getLocalAtual()) {
                    localVeiculo = locais[j];
                    if(primeiroVeiculo) {
                        minDistancia = calculoDistancia(
                            localVeiculo.getX(),
                            localVeiculo.getY(),
                            localOrigem.getX(),
                            localOrigem.getY()
                        );
                        veiculoMaisProximo = &frota[i];
                        primeiroVeiculo = false;
                    } else {
                        double distancia = calculoDistancia(
                            localVeiculo.getX(),
                            localVeiculo.getY(),
                            localOrigem.getX(),
                            localOrigem.getY()
                        );
                        if(distancia < minDistancia) {
                            minDistancia = distancia;
                            veiculoMaisProximo = &frota[i];
                        }
                    }
                    break;
                }
            }
        }
    }
    return veiculoMaisProximo;
}

void processarEntrega(vector<Veiculo>& frota, vector<Local>& locais, vector<Pedido>& pedidos) {
    system("cls");
    cout << "\n---SISTEMA DE ENTREGAS---" << endl;

    if(pedidos.empty()) {
        cout << "Nenhum pedido registrado." << endl;
        return;
    }

    if(frota.empty()) {
        cout << "Nenhum veículo na frota." << endl;
        return;
    }

    cout << "\nPedidos aguardando entrega: " << endl;
    ListarPedidos(pedidos);

    cout << "\nInforme o código do pedido: ";
    int codPedido;
    cin >> codPedido;

    int posicaoPedido = -1;
    for(int i = 0; i < pedidos.size(); i++) {
        if(pedidos[i].getId() == codPedido) {
            posicaoPedido = i;
            break;
        }
    }

    if(posicaoPedido == -1) {
        cout << "Pedido não localizado!" << endl;
        return;
    }

    Veiculo* transportador = veiculoMaisProximo(frota, pedidos[posicaoPedido].getLocalOrigem(), locais);

    if(transportador == nullptr) {
        cout << "Nenhum veículo disponível para transporte." << endl;
        return;
    }

    cout << "\nTransportador designado:" << endl;
    transportador->mostrar();

    Local pontoAtual;
    for(int i = 0; i < locais.size(); i++) {
        if(locais[i].getNome() == transportador->getLocalAtual()) {
            pontoAtual = locais[i];
            break;
        }
    }

    double distanciaColeta = calculoDistancia(
        pontoAtual.getX(), pontoAtual.getY(),
        pedidos[posicaoPedido].getLocalOrigem().getX(),
        pedidos[posicaoPedido].getLocalOrigem().getY()
    );

    double distanciaPercurso = calculoDistancia(
        pedidos[posicaoPedido].getLocalOrigem().getX(),
        pedidos[posicaoPedido].getLocalOrigem().getY(),
        pedidos[posicaoPedido].getLocalDestino().getX(),
        pedidos[posicaoPedido].getLocalDestino().getY()
    );

    double percursoTotal = distanciaColeta + distanciaPercurso;

    cout << "\nRota em andamento..." << endl;
    cout << "\nVeículo em trânsito:" << endl;
    transportador->mostrar();
    cout<< "\nLocal de origem:" << endl;
    pedidos[posicaoPedido].getLocalOrigem().mostrar();
    cout<< "\nLocal de Destino:" << endl;
    pedidos[posicaoPedido].getLocalDestino().mostrar();
    cout << "\nPercurso total:" << percursoTotal << endl;

    cout << "Deseja concluir a entrega? (S/N)" << endl;
    char resp;
    cin >> resp;

    if(resp == 'S' or resp == 's') {
        cout << "\nIniciando transporte" << endl;
        Sleep(2000);
        transportador->setLocalAtual(pedidos[posicaoPedido].getLocalDestino().getNome());
        transportador->setStatus(0);
        cout << "Entrega concluída!" << endl;
        cout << "Transportador disponível em: " << pedidos[posicaoPedido].getLocalDestino().getNome() << endl;
    }
}