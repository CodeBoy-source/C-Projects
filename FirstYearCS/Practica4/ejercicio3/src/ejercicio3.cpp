#include <iostream>
#include "Valor.h"
#include "MatrizDispersa.h"
using namespace std;

int main() {
    MatrizDispersa First;
    int sz, vx;
    double vy;
    cout << "Cual es el tamano de la matriz que deseas crear (vx,vy): ";
    cin >> vx >> sz;
    cout << "Introduzca los valores: ";
    First.Create(vx,sz);
    cout << "Cual sera el tamano de los vectores para la segunda matriz? ";
    cin >> sz;
    while(sz<0){
        cin >> sz;
    }
    int filas[sz+1],columnas[sz];
    cout << "Introduzca las filas: ";
    for(int i=0;i<sz;i++){
        cin>>vx;
        while(vx <= 0){
            cout << "Introduca un valor valido: ";
            cin >> vx;
        }
        filas[i] = vx;
    }
    //valor centinela para calcular el tamano en la función luego
    filas[sz] = -1;
    cout << "Introduzca las columnas: ";
    for(int i=0;i<sz;i++){
        cin>>vx;
        while(vx<=0){
            cout << "Introduca un valor valido: ";
            cin >> vx;
        }
        columnas[i] = vx;
    }
    double Valores[sz];
    cout << "Introduzca los valores del vector valor: ";
    for(int i=0;i<sz;i++){
        cin >> vy;
        Valores[i] = vy;
    }
    MatrizDispersa Second(filas,columnas,Valores);
    Second.Show();
    MatrizDispersa Result = First + Second;
    cout << "El resultado de sumarlos es: " << endl;
    Result.Show();
    return 0;
}