#include <iostream>
#include "utilidades.h"

using namespace std;

/*funcion bool para comprobar si se pueden multiplicar las matrices
@param columnas1
@param filas2
@return true si son multiplicables
@return false si no lo son */

bool multiplicables(int columnas1, int filas2){

    if(columnas1==filas2){
        return true;
    }
    else{
        return false;
    }
}

/*funcion void que multiplica las matrices y pasa el resultado a una matriz3
@param matriz1
@param filas1
@param columnas1
@param matriz2
@param filas2
@param columnas2
@param matriz3*/

void multiplicarMatrices(double matriz1[][100], int filas1, int columnas1, double matriz2[][100], int filas2, int columnas2, double matriz3[][100]){
    if(multiplicables(columnas1, filas2)){
        int filas3=filas1, columnas3=columnas2;

        for(int i=0;i<filas1;i++){
            for(int j=0;j<columnas2;j++){
                for(int k=0;k<filas2;k++){
                    matriz3[i][j]+= matriz1[i][k] * matriz2[k][j];
                }
            }
        }
        for(int i=0;i<filas3;i++){
            for(int j=0;j<columnas3;j++){
                cout << matriz3[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No se pueden multiplicar" << endl;
    }

}
