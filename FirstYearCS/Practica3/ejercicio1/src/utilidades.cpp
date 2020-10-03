#include "utilidades.h"
#include <iostream>
using namespace std;
/**
 * Recogemos los valroes dentro del array buscando aquel que sea inferior y
 * entonces almacenamos su dirección de memoria en la posicion debida en
 * un array de punteros
 * @param vec1
 * @param szvec
 * @param pvec
 */
void OrdenarPunteros(int* vec1, int szvec, int* pvec){
    int min, pos, change;
    for(int j = 0; j < szvec; j++) {
        min = *(vec1+j);
        pos = j;
        for (int i = j+1; i < szvec; i++) {
            if (*(vec1+i) < min) {
                min = *(vec1+i);
                pos = i;
            }
        }
        change = *(vec1+j);
        *(vec1+j) = min;
        *(vec1+pos) = change;
        *(pvec+j) = *(vec1+j);
    }
}
void Mostrar(int* vec1, int szvec){
    for(int i=0; i < szvec; i++){
        cout << *(vec1+i) << " ";
    }
    cout << endl;
}