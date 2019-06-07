#include "Pieza.h"
#ifndef CABALLO_H
#define CABALLO_H
#include "Posicion.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
class Caballo: public Pieza
{
public:
string nombre;
    int x;
    int y;
    Caballo();
    Caballo(string, int, int);
    virtual vector<Posicion*> Movimientos(char** Matriz);
};
#endif