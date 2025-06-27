#ifndef LOCALMODEL_H
#define LOCALMODEL_H
#include <string>

using namespace std;

class Local {
private:
    string nome;
    double x, y;
public:
    Local() {
        nome = "";
        x = 0;
        y = 0;
    }

    Local(const string& nome, double x, double y) : nome(nome), x(x), y(y) {}

    void entrada();
    void mostrar() const;
    void setNome(const string& novoNome);
    void setX(double novoX);
    void setY(double novoY);
    string getNome() const;
    double getX() const;
    double getY() const;
};

#endif