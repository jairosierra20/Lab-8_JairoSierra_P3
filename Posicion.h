#ifndef POSICION_H
#define POSICION_H
#include <string>
using std::string;
class Posicion
{
private:
    int x;
    int y;

public:
    Posicion(int, int);
    Posicion();;
    int getX();
    void setX(int);
    int getY();
    void setY(int);
};
#endif