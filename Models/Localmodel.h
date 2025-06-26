#ifndef LOCALMODEL_H
#define LOCALMODEL_H

class Local {
private:
    char nome[50];
    double x;
    double y;
public:
    Local();
    Local(const char nome[50], double x, double y);
    void entrada();
    void mostrar() const;
    void setNome(const char* novoNome);
    void setX(double novoX);
    void setY(double novoY);
    const char* getNome() const;
    double getX() const;
    double getY() const;
};

#endif