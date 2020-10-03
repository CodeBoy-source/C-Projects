#include <iostream>
#include "Valor.h"
#include "utilidades.h"
using namespace std;


int main()
{
    const int TAM=100;
    int k=0, util1=0, util2=0, fila=0, columna=0, util3=0;
    double valor=0.00;
    Valor vect1[TAM], vect2[TAM], vect3[TAM];

    /* Leemos el vector de matrices */

    cout << "Introduzca la fila, la columna y el valor de cada matriz, negativo en la fila para acabar" << endl;
    cin >> fila >> columna >> valor;
    vect1[k].SetFila(fila);
    vect1[k].SetColumna(columna);
    vect1[k].SetValor(valor);

    while (fila>=0){
        util1++;
        k++;
        cin >> fila >> columna >> valor;
        vect1[k].SetFila(fila);
        vect1[k].SetColumna(columna);
        vect1[k].SetValor(valor);
    }

    k=0;

    /* Leemos el segundo vector de matrices */

    cout << "Introduzca la fila, la columna y el valor de cada matriz, negativo en la fila para acabar" << endl;
    cin >> fila >> columna >> valor;
    vect2[k].SetFila(fila);
    vect2[k].SetColumna(columna);
    vect2[k].SetValor(valor);

    while (fila>=0){
        util2++;
        k++;
        cin >> fila >> columna >> valor;
        vect2[k].SetFila(fila);
        vect2[k].SetColumna(columna);
        vect2[k].SetValor(valor);
    }

    /* LLamada a la funcion combinarsuma y guardamos el tamaño del vector3 en una variable util*/

    util3=combinarSuma(vect1, util1, vect2, util2, vect3, util3);

    /* Mostramos el vector de matrices combinado */

    for(int i=0; i<util3; i++){
        cout << vect3[i].GetFila() << " " << vect3[i].GetColumna() << " " << vect3[i].GetValor() << endl;
    }

    return 0;
}
