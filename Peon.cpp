#include "Peon.h"
#include "Posicion.h"
#include <vector>
using std::vector;
Peon::Peon(string nombre, int x, int y,bool primermovimiento) : Pieza(nombre, x, y)
{
}
bool Peon::isPrimermovimiento() {
        return primermovimiento;
    }

    void Peon::setPrimermovimiento(bool primermovimiento) {
        primermovimiento = primermovimiento;
}

vector<Posicion*> Peon::Movimientos(char** Matriz)
{
    vector<Posicion*> posiciones;
    return posiciones;
}

