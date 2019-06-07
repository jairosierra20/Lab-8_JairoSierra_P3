#include "Rey.h"
#include "Posicion.h"
#include <vector>
using std::vector;
Rey::Rey(string nombre, int x, int y) : Pieza(nombre, x, y)
{
}
Rey::Rey(){
    
}
vector<Posicion*> Rey::Movimientos(char** Matriz)
{
    vector<Posicion*> posiciones;
        for(int i=x-1; i<=x+1; i++){
            for(int j=y-1; j<=y+1; j++){                 
                if(i != x || j != y){                       
                            posiciones.push_back(new Posicion(i, j)); 
                }
            }
        }
        return posiciones;
}


