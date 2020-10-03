#include "utilidades.h"

/*funcion void que ordena un vector
@param v3
@param tot_utilizados */

void ordenar_vector(double v3[], int tot_utilizados){

    bool cambio=true;
    double intercambia=0;

    for (int i=0; i<tot_utilizados && cambio; i++){

        cambio=false;

        for (int j=tot_utilizados-1; j>i; j--){

            if (v3[j]<v3[j-1]){

                cambio=true;
                intercambia=v3[j];
                v3[j]=v3[j-1];
                v3[j-1]=intercambia;
            }
        }
    }
}

/*funcion int que elimina los elementos repetidos de un vector
@param v3
@param tot_utilizados
@return el número de elementos del vector */

int eliminar_repetidos(double v3[], int tot_utilizados){

    int z=0;

    for(int i=0; i<tot_utilizados; i++){
		for(int j=i+1; j<tot_utilizados; j++){
			if(v3[i]==v3[j]){
                z=j;
				while(z<tot_utilizados){
					v3[z]=v3[z+1];
                    ++z;
				}
				--tot_utilizados;
				--j;
            }
        }
    }
    return tot_utilizados;
}

/* funcion int que añade en un vector3 los elemenos del vector1 y vector2
@param v1
@param v2
@param v3
@param util1
@param util2
@return el número de elementos del vector3 */

int mezclar(double v1[], double v2[], double v3[], int util1, int util2){

    int util3=util1+util2, z=0, tot_utilizados=0;

    for(int i=0;i<util1;i++){
        v3[i]=v1[i];
        z=i;
    }

    int j=0;
    z++;

    for(int i=z;i<util3;i++){
        v3[i]=v2[j];
        j++;

    }

    ordenar_vector(v3, util3);

    tot_utilizados=eliminar_repetidos(v3, util3);

    return tot_utilizados;

}
