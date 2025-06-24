#include <cabecalhos.h>

class Local{
private:
    char nome[50];
    double x;
    double y;
public:
    Local(const char nome[50], double x, double y) : x(x), y(y) {
        int i = 0;
        for (; i < 49 && nome[i] != '\0'; ++i) {
            this->nome[i] = nome[i];
        }
        this->nome[i] = '\0';
    }
};