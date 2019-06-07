#include "Alfil.h"
#include "Posicion.h"
#include <vector>
using std::vector;
Alfil::Alfil(string nombre, int x, int y) : Pieza(nombre, x, y)
{
}
Alfil::Alfil(){
    
}
vector<Posicion*> Alfil::Movimientos(char** Matriz)
{
    vector<Posicion*> posiciones;
    for (int i = 1; i < 8; i++)
    {
        if (x + i < 8 && x + i >= 0 && y + i < 8 && y + i >= 0)
        {
            if (Matriz[y + i][y + i] != ' ')
            {
                posiciones.push_back(new Posicion(x + i, y + i));

                break;
            }
            else
            {
                posiciones.push_back(new Posicion(x - i, y + i));
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x - i < 8 && x - i >= 0 && y + i < 8 && y + i >= 0)
        {
            if (Matriz[x - i][y + i] != ' ')
            {
                posiciones.push_back(new Posicion(x + i, y + i));
                break;
            }
            else
            {
                posiciones.push_back(new Posicion(x - i, x + i));
            }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x + i < 8 && x + i >= 0 && x - i < 8 && x - i >= 0)
        {
                    if (Matriz[x+i][y-i]!=' ')
                        {
                            posiciones.push_back(new Posicion(x + i, y - i));
                            break;
                        }
                    else
                    {
                        posiciones.push_back(new Posicion(x + i, y - i));
                    }
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (x - i < 8 && x - i >= 0 && y - i < 8 && y - i >= 0)
        {
            if (Matriz[x - i][y - i] != ' ')
            {
                posiciones.push_back(new Posicion(x - i, y - i));
                break;
            }
            else
            {
                posiciones.push_back(new Posicion(x - i, y - i));
            }
        }
    }
    return posiciones;
}

