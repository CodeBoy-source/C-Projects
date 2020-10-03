#include <iostream>
#include "utilidades.h"
using namespace std;

/* funcion void para mezclar dos vectores y meter los elementos en el vector3
@param vect1
@param util1
@param vect2
@param util2
@param vect3 */
void mezclarVectores(Valor vect1[], int util1, Valor vect2[], int util2, Valor vect3[]){

    int util3=util1+util2, z=0;
    int fila=0, columna=0;
    double valor=0.00;

    for(int i=0;i<util1;i++){
        fila=vect1[i].GetFila();
        columna=vect1[i].GetColumna();
        valor=vect1[i].GetValor();
        vect3[i].SetFila(fila);
        vect3[i].SetColumna(columna);
        vect3[i].SetValor(valor);
        z=i;
    }

    int j=0;
    z++;

    for(int i=z;i<util3;i++){
        fila=vect2[j].GetFila();
        columna=vect2[j].GetColumna();
        valor=vect2[j].GetValor();
        vect3[i].SetFila(fila);
        vect3[i].SetColumna(columna);
        vect3[i].SetValor(valor);
        j++;

    }
}
/* funcion int para combinar las matrices del vector3
@param vect1
@param util1
@param vect2
@param util2
@param vect3
@param util3
@return el numero de elementos del vector3*/
int combinarSuma(Valor vect1[], int util1, Valor vect2[], int util2, Valor vect3[], int util3){
    util3=util1+util2;
    int fila=0, columna=0;
    double nuevovalor=0.00, valor=0.00;
    mezclarVectores(vect1, util1, vect2, util2, vect3);

    int z=0;

    for(int i=0; i<util3; i++){

		for(int j=i+1; j<util3; j++){

			if((vect3[i].GetFila()==vect3[j].GetFila()) && (vect3[i].GetColumna()==vect3[j].GetColumna())){
                nuevovalor=vect3[i].GetValor() + vect3[j].GetValor();
                vect3[i].SetValor(nuevovalor);
                vect3[j].SetValor(nuevovalor);
                z=j;

				while(z<util3){
                    fila=vect3[z+1].GetFila();
                    vect3[z].SetFila(fila);
					columna=vect3[z+1].GetColumna();
					vect3[z].SetColumna(columna);
					valor=vect3[z+1].GetValor();
					vect3[z].SetValor(valor);
                    ++z;
				}
				--util3;
				--j;
            }
        }
    }
    return util3;

}
