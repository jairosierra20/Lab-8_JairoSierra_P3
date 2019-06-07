#include "Pieza.h"
#ifndef PEON_H
#define PEON_H
#include "Posicion.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
class Peon : public Pieza
{
public:
string nombre;
    int x;
    int y;
    bool primermovimiento;
    Peon();
    Peon(string, int, int,bool);
    bool isPrimermovimiento();
    void setPrimermovimiento(bool); 
    virtual vector<Posicion*> Movimientos(char** Matriz);
};
#endif