#include<iostream>
#include "EstimadorDistancia.h"

using namespace std;

int main() {
    /*Leemos el numero de muestras y mostramos la distancia media */
    const int TAM=100;
    double distanciaObtenidas[TAM];
    long int muestras;
    double resultado=0;
    cout << "Escribe el numero de muestras" << endl;
    cin >> muestras;
    EstimadorDistancia prueba(muestras);
    prueba.estimar();
    resultado=prueba.devolverDistancias(distanciaObtenidas, muestras);
    prueba.mostrarvector();
    cout << endl;
    cout << "La media es " << resultado;
    return 0;
}

