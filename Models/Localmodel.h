#ifndef LOCALMODEL_H
#define LOCALMODEL_H
#include <string>

using namespace std;

class Local {
private:
    string nome;
    double x, y;
public:
    //Construtores
    Local() {
        nome = "";
        x = 0;
        y = 0;
    }

    Local(const string& nome, double x, double y) : nome(nome), x(x), y(y) {}

    //Métodos
    void entrada();
    void mostrar() const;
    string getNome() const;
    double getX() const;
    double getY() const;
    void setNome(const string& novoNome);
    void setX(double novoX);
    void setY(double novoY);
};

#endif