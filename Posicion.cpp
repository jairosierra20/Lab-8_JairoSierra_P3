#include "Posicion.h"
Posicion::Posicion()
{
}
Posicion::Posicion(int x, int y)
{
    this->x = x;
    this->y = y;
}
int Posicion::getX()
{
    return x;
}

void Posicion::setX(int x)
{
    x = x;
}

int Posicion::getY()
{
    return y;
}

void Posicion::setY(int y)
{
    y = y;
}
