#include "utilidades.h"
#include <iostream>
void Mostrar(double* vec, int szvec){
    for(int i=0; i < szvec; i++){
        std::cout << *(vec+i) << " ";
    }
    std::cout << std::endl;
}
/**
 * Algoritmo de ordenación que consiste en mover n-veces
 * el número hacía la izquierda según su tamano.
 * @param vec
 * @param szvec
 */
void Insertion(double* vec, int szvec){
    double move;
    int i,j;
    for(i=1; i < szvec; i++){
        move = *(vec+i);
        for(j = i; j > 0 && move < *(vec+j-1); j--)
            *(vec+j) = *(vec+j-1);

        *(vec+j) = move;
    }
}
/**
 * Una vez que tenemos todos los array ordenados,
 * podemos ir comparando valor a valor e ir mezclando.
 * @param array1
 * @param sz_vec1
 * @param array2
 * @param sz_vec2
 * @param resultante
 * @return
 */
int MezclarUnico(double* array1, int sz_vec1, double* array2, int sz_vec2, double* resultante){
    Insertion(array1,sz_vec1);
    Mostrar(array1,sz_vec1);
    Insertion(array2,sz_vec2);
    Mostrar(array2, sz_vec2);
    int i = 0, j = 0, cont = 0;
    while (i < sz_vec1 && j < sz_vec2) {
        if (*(array1+i) < *(array2+j)) {
            *(resultante+cont) = *(array1+i);
            cont++; i++;
            continue;
        }
        if (*(array1+i) == *(array2+j)) {
            *(resultante+cont) = *(array1+i);
            i++; j++; cont++;
            continue;
        } else {
            *(resultante+cont) = *(array2+j);
            j++; cont++;
        }
    }
    if (i == sz_vec1) {
        while (j != sz_vec2) {
            *(resultante+cont) = *(array2+j);
            j++;
            cont++;
        }
    }
    while(j<sz_vec2){
        *(resultante+cont) = *(array2+j);
        j++; cont++;
    }
    while(i<sz_vec1){
        *(resultante+cont) = *(array1+i);
        i++; cont++;
    }
    return cont;
}
/**
 * En el caso de que se especifique parametros
 * (titulo=true) se imprime por pantalla el titulo
 * con su respectivo numero(num). En caso contrario
 * es un simple separador entre casos con "-";
 * @param num
 * @param titulo
 */
void Barritas(int num, bool titulo){
    if(titulo){
        for(int i = 0; i < 20; i++)
            std::cout << "--";
        std::cout << " caso prueba " << num << " ";
        for(int i = 0; i < 20; i++)
            std::cout << "--";
        std::cout << std::endl;
    }else {
        for(int i = 0; i < 40; i++)
            std::cout << "--";
        std::cout << std::endl;
    }
}

