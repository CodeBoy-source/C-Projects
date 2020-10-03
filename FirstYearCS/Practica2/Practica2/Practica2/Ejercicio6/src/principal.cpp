#include <iostream>
#include "utilidades.h"

using namespace std;

int main()
{
    const int FIL=100, COL=100;
    double matriz1[FIL][COL], matriz2[FIL][COL], matriz3[FIL][COL];
    int filas1, columnas1, filas2, columnas2;

    /*Leemos la primera matriz */

    cout << "Escribe las filas que tiene la matriz" << endl;
    cin >> filas1;
    cout << "Escribe las columnas que tiene la matriz" << endl;
    cin >> columnas1;
    for (int i=0;i<filas1 ;i++){

        for(int j=0; j<columnas1; j++){
            cin >> matriz1[i][j];
        }
    }

    /*Leemos las segunda matriz */

    cout << "Escribe las filas que tiene la segunda matriz" << endl;
    cin >> filas2;
    cout << "Escribe las columnas que tiene la segunda matriz" << endl;
    cin >> columnas2;
    for (int i=0;i<filas2 ;i++){

        for(int j=0; j<columnas2; j++){
            cin >> matriz2[i][j];
        }
    }

    cout << endl;

    /*Llamamos a la funcion que multiplica las matrices y muestra el resultado */

    multiplicarMatrices(matriz1, filas1, columnas1, matriz2, filas2, columnas2, matriz3);

    return 0;
}
