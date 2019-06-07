#include "Pieza.h"
#ifndef REINA_H
#define REINA_H
#include "Posicion.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
class Reina : public Pieza
{
public:
string nombre;
    int x;
    int y;
    Reina();
    Reina(string, int, int);
    virtual vector<Posicion*> Movimientos(char** Matriz);
};
#endif