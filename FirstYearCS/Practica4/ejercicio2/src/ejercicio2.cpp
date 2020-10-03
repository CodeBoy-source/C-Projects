#include <iostream>
#include "Punto.h"
#include "Polilinea.h"
using namespace std;

int main(){
    Polilinea First;
    int num;
    double vx,vy;
    cout << "Cuantos puntos quieres añadir a la polilinea? ";
    cin >> num;
    while(num<0){
        cin >> num;
    }
    for(int i=0;i<num;i++){
        cout << "Introduzca el " << i << " punto (x,y): ";
        cin >> vx >> vy;
        Punto A(vx,vy);
        First.AgregarPunto(A);
    }
    First.Show();
    Polilinea Copy(First);
    cout << "Copia realizada con suceso" << endl;
    Copy.Show();
    Polilinea Second;
    cout << "Cuantos puntos quieres anadir a la polilinea 2? ";
    cin >> num;
    while(num<0){
        cin >> num;
    }
    for(int i=0;i<num;i++){
        cout << "Introduzca el " << i << " punto: ";
        cin >> vx >> vy;
        Punto A(vx,vy);
        Second.AgregarPunto(A);
    }
    Second.Show();
    Polilinea Result = First+Second;
    cout << "El resultado de sumarlo es(Quitamos los duplicados): ";
    Result.Show();
    return 0;
}