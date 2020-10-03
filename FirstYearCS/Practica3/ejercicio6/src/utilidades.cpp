#include "utilidades.h"

/**
 * Comparamos a y b para que a sea menor que b
 * @param a
 * @param b
 */
void OrdenarPos(int* a, int* b){
    int change;
    if(a>=b) {
        change = *b;
        *b = *a;
        *a = change;
    }
}