#include "Partida.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
#include <stdlib.h>
using namespace std;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
Partida::Partida(){

}
Partida::Partida(string nombre,string pieza,vector<string> movimientos){
    this->nombre=nombre;
    this->pieza=pieza;
    this->movimientos=movimientos;
}
void Partida::GuardarPartida(){
    ofstream file;
	file.open("bitacoraPartidas.txt",ios::out);
    file<<"Nombre de la partida:"<<nombre<<endl;
    file<<"Nombre de la pieza: "<<pieza<<endl;
    for (int i = 0; i < movimientos.size(); i++)
    {
        file<<movimientos[i]<<";"<<endl;
    }
    
	cout<<"El archivo se creo exitosamente"<<endl;
	file.close();
}