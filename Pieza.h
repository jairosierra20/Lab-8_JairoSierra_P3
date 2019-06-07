#ifndef PIEZA_H
#define PIEZA_H
#include <string>
using std::string;
#include "Posicion.h"
#include <vector>
using std::vector;
class Pieza
{
private:
    string nombre;
    int x;
    int y;

public:
    Pieza(string, int, int);
    Pieza();
    string getNombre();
    void setNombre(string);
    int getX();
    void setX(int);
    int getY();
    void setY(int);
    virtual vector<Posicion*> Movimientos(char** Matriz);
};
#endif