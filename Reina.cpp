#include "Reina.h"
#include "Posicion.h"
#include <vector>
using std::vector;
Reina::Reina(string nombre, int x, int y) : Pieza(nombre, x, y)
{
}
Reina::Reina(){
    
}
vector<Posicion*> Reina::Movimientos(char** Matriz)
{
    vector<Posicion*> posiciones;               
        for(int i=x+1; i<8; i++){ 
                if(Matriz[i][y]!=' '){
                        posiciones.push_back(new Posicion(i, y));
                    break;
                }else {
                    posiciones.push_back(new Posicion(i, y));
                }
        }        
        for(int i=x-1; i>=0 ; i--){ 
                if(Matriz[i][y]!=' '){
                        posiciones.push_back(new Posicion(i, y));
                    break;
                }else {
                    posiciones.push_back(new Posicion(i, y));
                }
        }        
        for(int i=y+1; i<8; i++){ 
                if((Matriz[x][i]!=' ')){
                        posiciones.push_back(new Posicion(x, i));
                    break;
                }else {
                    posiciones.push_back(new Posicion(x, i));
                }
        }
        for(int i=y-1; i>=0; i--){ 
                if(Matriz[x][i]!=' '){
                        posiciones.push_back(new Posicion(x, i));
                    break;
                }else {
                    posiciones.push_back(new Posicion(x, i));
                }
        }
        for (int i=1; i<8; i++){
            if (x+i<8&&x+i>=0&&y+i<8&&y+i>=0) {
                    if (Matriz[x+i][y+i]!=' ') {
                            posiciones.push_back(new Posicion(x+i, y+i));
                        break;
                    }else{
                        posiciones.push_back(new Posicion(x+i, x+i));
                    }
            }
        }
                
        for (int i=1; i<8; i++){
            if (x-i<8&&x-i>=0&&y+i<8&&y+i>=0) {
                    if (Matriz[x-i][y+i]!=' ') {
                            posiciones.push_back(new Posicion(x-i, y+i));
                        break;
                    }else{
                        posiciones.push_back(new Posicion(x-i, y+i));
                    }
            }
        }
                
        for (int i=1; i<8; i++){
            if (x+i<8&&x+i>=0&&y-i<8&&y-i>=0) {
                    if (Matriz[x+i][y-i]!=' ') {
                            posiciones.push_back(new Posicion(x+i, y-i));
                        break;
                    }else{
                        posiciones.push_back(new Posicion(x+i, y-i));
                    }
            }
        }
                
        for (int i=1; i<8; i++){
            if (x-i<8&&x-i>=0&&y-i<8&&y-i>=0) {
                    if (Matriz[x-i][y-i]!=' ') {
                            posiciones.push_back(new Posicion(x-i, y-i));
                        break;
                    }else{
                        posiciones.push_back(new Posicion(x-i, y-i));
                    }
            }
        }
        return posiciones;
}

