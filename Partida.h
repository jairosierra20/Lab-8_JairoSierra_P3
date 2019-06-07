#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>
using std::string;
#include "Posicion.h"
#include <vector>
using std::vector;
class Partida
{
private:
    string nombre;
    vector<string> movimientos;
    string pieza;

public:
    Partida(string,string,vector<string>);
    Partida();
    virtual void GuardarPartida();
};
#endif
