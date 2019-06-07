#include "Pieza.h"
#ifndef ALFIL_H
#define ALFIL_H
#include "Posicion.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
class Alfil : public Pieza
{
public:
string nombre;
    int x;
    int y;
    Alfil();
    Alfil(string, int, int);
    virtual vector<Posicion*> Movimientos(char** Matriz);
};
#endif