#include "Pieza.h"
#ifndef REY_H
#define REY_H
#include "Posicion.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
class Rey : public Pieza
{
public:
string nombre;
    int x;
    int y;
    Rey();
    Rey(string, int, int);
    virtual vector<Posicion*> Movimientos(char** Matriz);
};
#endif