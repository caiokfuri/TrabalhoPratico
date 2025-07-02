#include "DataService.h"
#include <iostream>

using namespace std;

const string DataService::BACKUP_DIR = "backup/";

bool DataService::criarDiretorioBackup() {
    try {
        if (!filesystem::exists(BACKUP_DIR)) {
            return filesystem::create_directories(BACKUP_DIR);
        }
        return true;
    } catch (const exception& e) {
        cerr << "Erro ao criar diretório backup: " << e.what() << endl;
        return false;
    }
}

bool DataService::salvarLocais(const vector<Local>& locais) {
    if (!criarDiretorioBackup()) {
        return false;
    }

    ofstream arquivo(BACKUP_DIR + "Locais.bin", ios::binary);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo Locais.bin para escrita" << endl;
        return false;
    }

    size_t tamanho = locais.size();
    arquivo.write(reinterpret_cast<const char*>(&tamanho), sizeof(tamanho));

    for (const auto& local : locais) {
        string nome = local.getNome();
        size_t tamanhoNome = nome.size();
        arquivo.write(reinterpret_cast<const char*>(&tamanhoNome), sizeof(tamanhoNome));
        arquivo.write(nome.c_str(), tamanhoNome);

        double x = local.getX();
        double y = local.getY();
        arquivo.write(reinterpret_cast<const char*>(&x), sizeof(x));
        arquivo.write(reinterpret_cast<const char*>(&y), sizeof(y));
    }

    arquivo.close();
    cout << "Locais salvos com sucesso em " << BACKUP_DIR << "Locais.bin" << endl;
    return true;
}

bool DataService::salvarPedidos(const vector<Pedido>& pedidos) {
    if (!criarDiretorioBackup()) {
        return false;
    }

    ofstream arquivo(BACKUP_DIR + "Pedidos.bin", ios::binary);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo Pedidos.bin para escrita" << endl;
        return false;
    }

    size_t tamanho = pedidos.size();
    arquivo.write(reinterpret_cast<const char*>(&tamanho), sizeof(tamanho));

    for (const auto& pedido : pedidos) {
        int id = pedido.getId();
        arquivo.write(reinterpret_cast<const char*>(&id), sizeof(id));

        double peso = pedido.getPeso();
        arquivo.write(reinterpret_cast<const char*>(&peso), sizeof(peso));

        Local origem = const_cast<Pedido&>(pedido).getLocalOrigem();
        string nomeOrigem = origem.getNome();
        size_t tamanhoNomeOrigem = nomeOrigem.size();
        arquivo.write(reinterpret_cast<const char*>(&tamanhoNomeOrigem), sizeof(tamanhoNomeOrigem));
        arquivo.write(nomeOrigem.c_str(), tamanhoNomeOrigem);
        double xOrigem = origem.getX();
        double yOrigem = origem.getY();
        arquivo.write(reinterpret_cast<const char*>(&xOrigem), sizeof(xOrigem));
        arquivo.write(reinterpret_cast<const char*>(&yOrigem), sizeof(yOrigem));

        Local destino = const_cast<Pedido&>(pedido).getLocalDestino();
        string nomeDestino = destino.getNome();
        size_t tamanhoNomeDestino = nomeDestino.size();
        arquivo.write(reinterpret_cast<const char*>(&tamanhoNomeDestino), sizeof(tamanhoNomeDestino));
        arquivo.write(nomeDestino.c_str(), tamanhoNomeDestino);
        double xDestino = destino.getX();
        double yDestino = destino.getY();
        arquivo.write(reinterpret_cast<const char*>(&xDestino), sizeof(xDestino));
        arquivo.write(reinterpret_cast<const char*>(&yDestino), sizeof(yDestino));
    }

    arquivo.close();
    cout << "Pedidos salvos com sucesso em " << BACKUP_DIR << "Pedidos.bin" << endl;
    return true;
}

bool DataService::salvarVeiculos(const vector<Veiculo>& frota) {
    if (!criarDiretorioBackup()) {
        return false;
    }

    ofstream arquivo(BACKUP_DIR + "Veiculos.bin", ios::binary);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo Veiculos.bin para escrita" << endl;
        return false;
    }

    size_t tamanho = frota.size();
    arquivo.write(reinterpret_cast<const char*>(&tamanho), sizeof(tamanho));

    for (const auto& veiculo : frota) {
        string placa = veiculo.getPlaca();
        size_t tamanhoPlaca = placa.size();
        arquivo.write(reinterpret_cast<const char*>(&tamanhoPlaca), sizeof(tamanhoPlaca));
        arquivo.write(placa.c_str(), tamanhoPlaca);

        string modelo = veiculo.getModelo();
        size_t tamanhoModelo = modelo.size();
        arquivo.write(reinterpret_cast<const char*>(&tamanhoModelo), sizeof(tamanhoModelo));
        arquivo.write(modelo.c_str(), tamanhoModelo);

        string localAtual = veiculo.getLocalAtual();
        size_t tamanhoLocal = localAtual.size();
        arquivo.write(reinterpret_cast<const char*>(&tamanhoLocal), sizeof(tamanhoLocal));
        arquivo.write(localAtual.c_str(), tamanhoLocal);

        int status = veiculo.getStatus();
        arquivo.write(reinterpret_cast<const char*>(&status), sizeof(status));
    }

    arquivo.close();
    cout << "Veículos salvos com sucesso em " << BACKUP_DIR << "Veiculos.bin" << endl;
    return true;
}

bool DataService::carregarLocais(vector<Local>& locais) {
    ifstream arquivo(BACKUP_DIR + "Locais.bin", ios::binary);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo Locais.bin para leitura" << endl;
        return false;
    }

    locais.clear();

    size_t tamanho;
    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));

    for (size_t i = 0; i < tamanho; ++i) {
        size_t tamanhoNome;
        arquivo.read(reinterpret_cast<char*>(&tamanhoNome), sizeof(tamanhoNome));
        string nome(tamanhoNome, '\0');
        arquivo.read(&nome[0], tamanhoNome);

        double x, y;
        arquivo.read(reinterpret_cast<char*>(&x), sizeof(x));
        arquivo.read(reinterpret_cast<char*>(&y), sizeof(y));

        locais.emplace_back(nome, x, y);
    }

    arquivo.close();
    cout << "Locais carregados com sucesso de " << BACKUP_DIR << "Locais.bin" << endl;
    return true;
}

bool DataService::carregarPedidos(vector<Pedido>& pedidos) {
    ifstream arquivo(BACKUP_DIR + "Pedidos.bin", ios::binary);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo Pedidos.bin para leitura" << endl;
        return false;
    }

    pedidos.clear();

    size_t tamanho;
    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));

    for (size_t i = 0; i < tamanho; ++i) {
        int id;
        arquivo.read(reinterpret_cast<char*>(&id), sizeof(id));

        double peso;
        arquivo.read(reinterpret_cast<char*>(&peso), sizeof(peso));

        size_t tamanhoNomeOrigem;
        arquivo.read(reinterpret_cast<char*>(&tamanhoNomeOrigem), sizeof(tamanhoNomeOrigem));
        string nomeOrigem(tamanhoNomeOrigem, '\0');
        arquivo.read(&nomeOrigem[0], tamanhoNomeOrigem);
        double xOrigem, yOrigem;
        arquivo.read(reinterpret_cast<char*>(&xOrigem), sizeof(xOrigem));
        arquivo.read(reinterpret_cast<char*>(&yOrigem), sizeof(yOrigem));
        Local origem(nomeOrigem, xOrigem, yOrigem);

        size_t tamanhoNomeDestino;
        arquivo.read(reinterpret_cast<char*>(&tamanhoNomeDestino), sizeof(tamanhoNomeDestino));
        string nomeDestino(tamanhoNomeDestino, '\0');
        arquivo.read(&nomeDestino[0], tamanhoNomeDestino);
        double xDestino, yDestino;
        arquivo.read(reinterpret_cast<char*>(&xDestino), sizeof(xDestino));
        arquivo.read(reinterpret_cast<char*>(&yDestino), sizeof(yDestino));
        Local destino(nomeDestino, xDestino, yDestino);

        pedidos.emplace_back(id, origem, destino, peso);
    }

    arquivo.close();
    cout << "Pedidos carregados com sucesso de " << BACKUP_DIR << "Pedidos.bin" << endl;
    return true;
}

bool DataService::carregarVeiculos(vector<Veiculo>& veiculos) {
    ifstream arquivo(BACKUP_DIR + "Veiculos.bin", ios::binary);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo Veiculos.bin para leitura" << endl;
        return false;
    }

    veiculos.clear();

    size_t tamanho;
    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));

    for (size_t i = 0; i < tamanho; ++i) {
        size_t tamanhoPlaca;
        arquivo.read(reinterpret_cast<char*>(&tamanhoPlaca), sizeof(tamanhoPlaca));
        string placa(tamanhoPlaca, '\0');
        arquivo.read(&placa[0], tamanhoPlaca);

        size_t tamanhoModelo;
        arquivo.read(reinterpret_cast<char*>(&tamanhoModelo), sizeof(tamanhoModelo));
        string modelo(tamanhoModelo, '\0');
        arquivo.read(&modelo[0], tamanhoModelo);

        size_t tamanhoLocal;
        arquivo.read(reinterpret_cast<char*>(&tamanhoLocal), sizeof(tamanhoLocal));
        string localAtual(tamanhoLocal, '\0');
        arquivo.read(&localAtual[0], tamanhoLocal);

        int status;
        arquivo.read(reinterpret_cast<char*>(&status), sizeof(status));

        veiculos.emplace_back(placa, modelo, localAtual, status);
    }

    arquivo.close();
    cout << "Veículos carregados com sucesso de " << BACKUP_DIR << "Veiculos.bin" << endl;
    return true;
}
