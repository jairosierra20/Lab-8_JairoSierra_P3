#include "Caballo.h"
#include "Posicion.h"
#include <vector>
using std::vector;
Caballo::Caballo(string nombre, int x, int y) : Pieza(nombre, x, y)
{
}
vector<Posicion*> Caballo::Movimientos(char** Matriz)
{
    vector<Posicion*> posiciones;
    return posiciones;
}

