#include "LocalModel.h"
#include <iostream>
#include <cstring>

using namespace std;

Local::Local() {
    nome[0] = '\0';
    x = 0;
    y = 0;
}

Local::Local(const char nome[50], double x, double y) : x(x), y(y) {
    int i = 0;
    for (i = 0; i < 49 && nome[i] != '\0'; ++i) {
        this->nome[i] = nome[i];
    }
    this->nome[i] = '\0';
}

void Local::entrada() {
    cout << "Nome do local: ";
    cin.ignore();
    cin.getline(nome, 50);
    cout << "Coordenada X: ";
    cin >> x;
    cout << "Coordenada Y: ";
    cin >> y;
}

void Local::mostrar() const {
    cout << "Nome: " << nome << "\nX: " << x << "\nY: " << y << endl;
}

void Local::setNome(const char* novoNome) {
    strncpy(nome, novoNome, 49);
    nome[49] = '\0';
}
void Local::setX(double novoX) { x = novoX; }
void Local::setY(double novoY) { y = novoY; }
const char* Local::getNome() const { return nome; }
double Local::getX() const { return x; }
double Local::getY() const { return y; }