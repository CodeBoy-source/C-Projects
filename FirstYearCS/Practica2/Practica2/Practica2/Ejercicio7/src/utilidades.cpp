#include <iostream>
#include "utilidades.h"

using namespace std;

/*funcion bool que comprueba si un numero es primo
@param n
@return true si es primo
@return false si no lo es*/

bool primo(int n){
    bool primo=true;
    for(int i=2;i<n && primo;i++){
        if(n%i==0){
            primo=false;
        }
    }
    return primo;
}

/*funcion void que descompone el numero en factores primos
@param numero
@param factores
@param numeroFactores*/

void descomponer(int numero, int factores[], int &numeroFactores){
    bool parar=true;

    if (numero==1){
        factores[numeroFactores]=1;
    }
    else{
        for(int i=2;i<=numero && parar ;i++){

            if(primo(i) && numero%i==0){

                numero=numero/i;
                factores[numeroFactores]=i;
                numeroFactores++;

                descomponer(numero, factores, numeroFactores);
                parar=false;

            }

        }
    }
}
