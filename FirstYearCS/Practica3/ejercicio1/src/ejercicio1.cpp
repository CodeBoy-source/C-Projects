#include <iostream>
#include "utilidades.h"

int main() {
    std::cout << "Con cuantos vectores quieres probar? ";
    int times;
    std::cin >> times;
    while(times<=0){
        std::cout << "Introduzca un valor real: ";
        std::cin >> times;
    }
    for(int i=1; i<=times;i++) {
        int sz;
        std::cout << "Cual es el tamano del vector " << i << "? ";
        std::cin >> sz;
        int* a = new int[sz];
        std::cout << "Introduzca los valores: ";
        for(int j=0; j<sz; j++){
            std::cin >> *(a+j);
        }
        int* b = new int[sz];
        OrdenarPunteros(a,sz,b);
        Mostrar(b,sz);
        delete [] a,b;
    }
}