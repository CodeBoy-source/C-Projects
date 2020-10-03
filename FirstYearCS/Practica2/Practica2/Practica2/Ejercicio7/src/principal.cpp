#include <iostream>
#include "utilidades.h"

using namespace std;

int main()
{
    /*Leemos el numero y mostramos la descomposición en factores primos */

    const int TAM=100;
    int numero, factores[TAM], numeroFactores=0;
    cin >> numero;
    descomponer(numero, factores, numeroFactores);
    cout << "Hay " << numeroFactores << endl;
    for(int i=0;i<numeroFactores;i++){
        cout << factores[i] << " ";
    }

    return 0;
}
