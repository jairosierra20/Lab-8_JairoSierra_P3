#include "Pieza.h"
#include "Partida.h"
#include "Posicion.h"
#include "Peon.h"
#include "Rey.h"
#include "Reina.h"
#include "Caballo.h"
#include "Torre.h"
#include "Alfil.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
void Jugar();
//Provisionar la matriz de chars para el juego
char **provisionarMatriz(int);
char **provisionarMatriz2(int);
//liberar memoria de la matriz
void liberarMatriz(int);
void liberarMatriz2(int);
//imprimir la matriz
void printMatrix(int);
void printMatrix2(int);
//Llenado de la matrix
void llenado();
vector<string> movimientos;
string pieza = "", partida = "", pos1 = "", pos2 = "";
Partida *partidas;
int validar(string);
bool MoverCaballo(int, int, int, int);
char **matrix = NULL;
char **matrix2 = NULL;
bool MoverPeon(int, int, int, int, int);
Rey *rey;
Reina *reina;
Alfil *alfil;
void Recrear();
int main()
{
    int opcion = 0, opc = 0;
    while (opcion != 3)
    {
        cout << "Menu" << endl;
        cout << "1) Jugar Partida" << endl;
        cout << "2) Recrear Partida" << endl;
        cout << "3) Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            //inicializar matriz n x n
            matrix = provisionarMatriz(8);
            //llenar la matriz
            llenado();
            printMatrix(8);
            //LLamada del metodo que realiza todas las funciones del juego
            while (opc != 2)
            {
                Jugar();
                movimientos.push_back(pos1);
                cout << "1) desea continuar 2) Salir" << endl;
                cin >> opc;
                pos1 = "";
            }
            partidas = new Partida(partida, pieza, movimientos);
            partidas->GuardarPartida();
            //Libera la matriz
            cout << endl;
            printMatrix(8);
            //Jugar(matrix);
            break;
        case 2:
            matrix2 = provisionarMatriz2(8);
            Recrear();
            break;
        case 3:
            cout << "El programa se cerrara" << endl;
            break;
        }
    }
    return 0;
}
char **provisionarMatriz(int size)
{
    char **matrix = NULL;
    matrix = new char *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new char[size];
    }
    return matrix;
}
char **provisionarMatriz2(int size)
{
    char **matrix2 = NULL;
    matrix2 = new char *[size];
    for (int i = 0; i < size; i++)
    {
        matrix2[i] = new char[size];
    }
    return matrix2;
}
void liberarMatriz(int size)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix[i] != NULL)
        {
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }
    if (matrix != NULL)
    {
        delete[] matrix;
        matrix = NULL;
    }
}
void liberarMatriz2(int size)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix2[i] != NULL)
        {
            delete[] matrix2[i];
            matrix2[i] = NULL;
        }
    }
    if (matrix2 != NULL)
    {
        delete[] matrix2;
        matrix2 = NULL;
    }
}
void printMatrix(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "[" << matrix[i][j] << "]  ";
        }
        cout << endl;
    }
}
void printMatrix2(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "[" << matrix2[i][j] << "]  ";
        }
        cout << endl;
    }
}
void llenado()
{
    cout << "Ingrese el nombre de la partida" << endl;
    cin >> partida;
    cout << "Ingrese el nombre de la pieza con la que quiere jugar" << endl;
    cin >> pieza;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matrix[7][4] = '#';
            matrix[0][4] = '%';
            rey = new Rey();
            if (pieza == "Torre" || pieza == "torre")
            {
                matrix[0][7] = '1';
                matrix[7][0] = '2';
            }
            else if (pieza == "Alfil" || pieza == "alfil")
            {
                alfil = new Alfil();
                matrix[0][5] = '3';
                matrix[7][2] = '4';
            }
            else if (pieza == "Reina" || pieza == "reina")
            {
                reina = new Reina();
                matrix[0][3] = '&';
                matrix[7][3] = 'R';
            }
            else if (pieza == "Caballo" || pieza == "caballo")
            {
                matrix[0][6] = 'C';
                matrix[7][1] = '5';
            }
            else if (pieza == "Peon" || pieza == "peon")
            {
                matrix[1][4] = 'P';
                matrix[6][4] = '6';
            }
            else
            {
                cout << "El nombre de pieza es incorrecto" << endl;
            }
        }
    }
}
void Jugar()
{
    cout << "Ingrese la posicion (solo se permiten minusculas)" << endl;
    cin >> pos1;
    string letra1 = "", letra2, num1 = "", num2 = ""; //variables para dividir las cadenas en letras y numeros
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    letra1 = pos1.substr(1, 1);
    letra2 = pos1.substr(4, 1);
    num1 = pos1.substr(2, 1);
    num2 = pos1.substr(5, 1);
    x1 = (int)num1[0] - 48;
    x2 = (int)num2[0] - 48;
    y1 = validar(letra1);
    y2 = validar(letra2);
    if (pieza == "Caballo" || pieza == "caballo")
    {
        bool move = false;
        if (matrix[x2][y2] != ' ')
        {
            move = MoverCaballo(x1, y1, x2, y2);
            if (move)
            {
                if (matrix[x1][y1] == 'C')
                {
                    matrix[x2][y2] = 'C';
                    matrix[x1][y1] = ' ';
                    cout << "s" << endl;
                }
                else if (matrix[x1][y1] == '5')
                {
                    matrix[x2][y2] = '5';
                    matrix[x1][y1] = ' ';
                }
            }
        }
        printMatrix(8);
    }
    if (pieza == "Peon" || pieza == "Peon")
    {
        bool move = false;
        int hola = 0;
        if (matrix[x1][y1] == 'P')
        {
            hola = 1;
        }
        else if (matrix[x1][y1] == '6')
        {
            hola = 2;
        }
        if (matrix[x2][y2] != ' ')
        {
            move = MoverPeon(x1, y1, x2, y2, hola);
            if (move)
            {
                if (matrix[x1][y1] == 'P')
                {
                    hola = 1;
                    matrix[x2][y2] = 'P';
                    matrix[x1][y1] = ' ';
                }
                else if (matrix[x1][y1] == '6')
                {
                    hola = 2;
                    matrix[x2][y2] = '6';
                    matrix[x1][y1] = ' ';
                }
            }
        }
        printMatrix(8);
    }
    if (pieza == "Reina" || pieza == "Reina")
    {
        vector<Posicion *> posiciones = reina->Movimientos(matrix);
        bool mover = false;
        for (int i = 0; i < posiciones.size(); i++)
        {
            if ((posiciones[i]->getX() == x2) && (posiciones[i]->getY() == y2))
            {
                mover = true;
                break;
            }
        }
        if (mover)
        {
            if (matrix[x1][y1] == '&')
            {
                matrix[x2][y2] = '&';
                matrix[x1][y1] = ' ';
            }
            else if (matrix[x1][y1] == 'R')
            {
                matrix[x2][y2] = 'R';
                matrix[x1][y1] = ' ';
            }
            printMatrix(8);
        }
    }
    if (pieza == "Alfil" || pieza == "Alfil")
    {
        vector<Posicion *> posiciones = reina->Movimientos(matrix);
        bool mover = false;
        for (int i = 0; i < posiciones.size(); i++)
        {
            if ((posiciones[i]->getX() == x2) && (posiciones[i]->getY() == y2))
            {
                mover = true;
                break;
            }
        }
        if (mover)
        {
            if (matrix[x1][y1] == '3')
            {
                matrix[x2][y2] = '3';
                matrix[x1][y1] = ' ';
            }
            else if (matrix[x1][y1] == '4')
            {
                matrix[x2][y2] = '4';
                matrix[x1][y1] = ' ';
            }
            printMatrix(8);
        }
    }
    if (matrix[x1][y1] == '%' || matrix[x1][y1] == '#')
    {
        vector<Posicion *> posiciones = reina->Movimientos(matrix);
        bool mover = false;
        for (int i = 0; i < posiciones.size(); i++)
        {
            if ((posiciones[i]->getX() == x2) && (posiciones[i]->getY() == y2))
            {
                mover = true;
                break;
            }
        }
        if (mover)
        {
            if (matrix[x1][y1] == '%')
            {
                matrix[x2][y2] = '%';
                matrix[x1][y1] = ' ';
            }
            else if (matrix[x1][y1] == '#')
            {
                matrix[x2][y2] = '#';
                matrix[x1][y1] = ' ';
            }
        }
        printMatrix(8);
    }
}
int validar(string cadena1)
{
    int x = 0;
    if (cadena1 == "a" || cadena1 == "a")
    {
        x = 0;
    }
    if (cadena1 == "B" || cadena1 == "b")
    {
        x = 1;
    }
    if (cadena1 == "C" || cadena1 == "c")
    {
        x = 2;
    }
    if (cadena1 == "D" || cadena1 == "d")
    {
        x = 3;
    }
    if (cadena1 == "E" || cadena1 == "e")
    {
        x = 4;
    }
    if (cadena1 == "F" || cadena1 == "f")
    {
        x = 5;
    }
    if (cadena1 == "G" || cadena1 == "g")
    {
        x = 6;
    }
    if (cadena1 == "H" || cadena1 == "h")
    {
        x = 7;
    }
    return x;
}
bool MoverCaballo(int startRow, int startColumn, int desRow, int desColumn)
{

    if (desRow == (startRow - 2) && desColumn == (startColumn - 1))
    {
        return true;
    }
    else if (desRow == (startRow - 2) && desColumn == (startColumn + 1))
    {
        return true;
    }
    else if (desRow == (startRow + 2) && desColumn == (startColumn - 1))
    {
        return true;
    }
    else if (desRow == (startRow + 2) && desColumn == (startColumn + 1))
    {
        return true;
    }
    else if (desRow == (startRow - 1) && desColumn == (startColumn - 2))
    {
        return true;
    }
    else if (desRow == (startRow - 1) && desColumn == (startColumn + 2))
    {
        return true;
    }
    else if (desRow == (startRow + 1) && desColumn == (startColumn - 2))
    {
        return true;
    }
    else if (desRow == (startRow + 1) && desColumn == (startColumn + 2))
    {
        return true;
    }

    return false;
}
bool MoverPeon(int startRow, int startColumn, int desRow, int desColumn, int currentPlayer)
{

    bool legalMove = true;
    vector<int> playerPawnStart = {6, 1};
    if ((currentPlayer == 1 && desRow >= startRow) || (currentPlayer == 2 && desRow <= startRow))
    {
        legalMove = false;
    }
    else if (desColumn != startColumn)
    {
        if ((desColumn > startColumn && desColumn == (startColumn + 1)) || (desColumn < startColumn && desColumn == (startColumn - 1)))
        {
            if ((desRow == (startRow + 1) && currentPlayer == 2) || (desRow == (startRow - 1) && currentPlayer == 1))
            {
                if (matrix[desRow][desColumn] == ' ')
                {
                    legalMove = false;
                }
            }
            else
            {
                legalMove = false;
            }
        }
        else
        {
            legalMove = false;
        }
    }
    else if ((currentPlayer == 1 && desRow < (startRow - 1)) || (currentPlayer == 2 && desRow > (startRow + 1)))
    {
        if ((currentPlayer == 1 && desRow == (startRow - 2)) || (currentPlayer == 2 && desRow == (startRow + 2)))
        {
            if (playerPawnStart[currentPlayer - 1] != startRow)
            {
                legalMove = false;
            }
        }
        else
        {
            legalMove = false;
        }
    }
    return legalMove;
}
void Recrear()
{
    int opcion2 = 0;
    string pos3 = "";
    while (opcion2 != 2)
    {
                for (int i = 0; i < movimientos.size(); i++)
                {
                    pos3 = movimientos[i];
                    string letra1 = "", letra2, num1 = "", num2 = ""; //variables para dividir las cadenas en letras y numeros
                    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
                    letra1 = pos3.substr(1, 1);
                    letra2 = pos3.substr(4, 1);
                    num1 = pos3.substr(2, 1);
                    num2 = pos3.substr(5, 1);
                    x1 = (int)num1[0] - 48;
                    x2 = (int)num2[0] - 48;
                    y1 = validar(letra1);
                    y2 = validar(letra2);
                    if (matrix[x2][y2] == '%')
                    {
                        matrix2[x2][y2] = '%';
                        break;
                    }
                    else if (matrix[x2][y2] == '#')
                    {
                        matrix[x2][y2] = '#';
                        break;
                    }
                    else if (matrix[x2][y2] == '1')
                    {
                        matrix[x2][y2] = '1';
                        break;
                    }
                    else if (matrix[x2][y2] == '2')
                    {
                        matrix[x2][y2] = '2';
                        break;
                    }
                    else if (matrix[x2][y2] == '3')
                    {
                        matrix[x2][y2] = '3';
                        break;
                    }
                    else if (matrix[x2][y2] == '4')
                    {
                        matrix[x2][y2] = '4';
                        break;
                    }
                    else if (matrix[x2][y2] == 'P')
                    {
                        matrix[x2][y2] = 'P';
                        break;
                    }
                    else if (matrix[x2][y2] == '6')
                    {
                        matrix[x2][y2] = '6';
                        break;
                    }
                    else if (matrix[x2][y2] == '&')
                    {
                        matrix[x2][y2] = '&';
                        break;
                    }
                    else if (matrix[x2][y2] == 'R')
                    {
                        matrix[x2][y2] = 'R';
                        break;
                    }
                    else if (matrix[x2][y2] == 'C')
                    {
                        matrix[x2][y2] = 'C';
                        break;
                    }
                    else if (matrix[x2][y2] == '5')
                    {
                        matrix[x2][y2] = '5';
                        break;
                    }
                }
                printMatrix2(8);
                cout<<"1) Ver el siguiente movimiento 2) Salir"<<endl;
                cin>>opcion2;
    }
}