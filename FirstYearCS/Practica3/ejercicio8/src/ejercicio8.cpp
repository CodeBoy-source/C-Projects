#include <iostream>
#include "Node.h"
#include "List.h"

int main() {
    List Initial;
    int sz;
    std::cout << "Introduzca la longitud de la lista: ";
    std::cin >> sz;
    while(sz<=0){
        std::cout << "Introduzca un valor real: ";
        std::cin >> sz;
    }
    Initial.Create(sz);
    Initial.Show();
    Initial.RevShow();
    Initial.Release();

}