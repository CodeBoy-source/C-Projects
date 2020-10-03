#include <iostream>
#include "utilidades.h"

int main(){
    int sz1, sz2;
    std::cout << "Cual es el tamano del primer vector? ";
    std::cin >> sz1;
    double *vec1 = new double[sz1];
    std::cout << "Introduzca los valores: ";
    for(int i=0; i<sz1;i++){
        std::cin >> *(vec1+i);
    }
    std::cout << "Cual es el tamano del segundo vector? ";
    std::cin >> sz2;
    double *vec2 = new double[sz2];
    std::cout << "Introduzca los valores: ";
    for(int i=0; i<sz2;i++){
        std::cin >> *(vec2+i);
    }
    double* mix = new double[sz1+sz2];
    int szmix = MezclarUnico(vec1,sz1,vec2,sz2,mix);
    Mostrar(mix, szmix);
    delete [] vec1, vec2, mix;

}
