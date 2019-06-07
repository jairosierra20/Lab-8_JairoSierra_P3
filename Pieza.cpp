#include "Pieza.h"
#include <string>
using std::string;
#include "Posicion.h"
#include <vector>
using std::vector;
Posicion* pos;
Pieza::Pieza()
{
    
}
Pieza::Pieza(string nombre, int x, int y)
{
    this->nombre = nombre;
    pos = new Posicion(x,y);
}
string Pieza::getNombre()
{
    return nombre;
}
void Pieza::setNombre(string nombre)
{
    nombre = nombre;
}
int Pieza::getX()
{
    return pos->getX();
}
void Pieza::setX(int x)
{
   pos->setX(x);
}
int Pieza::getY()
{
    return pos->getY();
}
void Pieza::setY(int y)
{
    pos->setY(y);
}
vector<Posicion*> Pieza::Movimientos(char** Matriz)
{
    vector<Posicion*> posiciones;
    return posiciones;
}
