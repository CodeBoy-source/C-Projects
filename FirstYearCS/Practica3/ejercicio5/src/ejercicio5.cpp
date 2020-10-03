#include <iostream>
#include "Node.h"
#include "List.h"
#include "utilidades.h"

int main() {
    List Initial;
    int sz, value;
    std::cout << "Cual es la longitud de la lista? ";
    std::cin >> sz;
    while(sz<=0){
        std::cout << "Introduzca un valor real: ";
        std::cin >> sz;
    }
    Initial.Create(sz);
    std::cout << "(Introduzca -1 para finalizar el programa) " << std::endl;
    std::cout << "Cual sera la longitud de los segmentos? ";
    std::cin >> sz;
    while(sz>0) {
        List *Segments = new List[Initial.Length()];
        sz = Divide(Initial, sz, Segments);
        for (int i = 0; i < sz; i++) {
            Segments[i].Show();
            Segments[i].Release();
        }
        std::cout << "Cual sera la longitud de los segmentos? ";
        std::cin >> sz;
    }
}