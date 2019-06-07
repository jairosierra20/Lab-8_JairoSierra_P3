#include "Pieza.h"
#ifndef TORRE_H
#define TORRE_H
#include "Posicion.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
class Torre : public Pieza
{
public:
string nombre;
    int x;
    int y;
    Torre();
    Torre(string, int, int);
    virtual vector<Posicion*> Movimientos(char** Matriz);
};
#endif