#include <iostream>
#include "Node.h"
#include "List.h"

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
    Initial.Show();
    std::cout << "Que posicion quieres remover? ";
    std::cin >> sz;
    Initial.RemPos(sz);
    Initial.Show();
//    std::cout << "Ahora vamos a borrar el valor de la ultima pos: " << std::endl;
//    Initial.RemEnd();
//    Initial.Show();
//    std::cout << "Que valor agregamos al final de la lista? ";
//    std::cin >> value;
//    Initial.AddEnd(value);
//    Initial.Show();
//    std::cout << "Que valor agregamos al inicio de la lista? ";
//    std::cin >> value;
//    Initial.AddStart(value);
//    Initial.Show();
//    std::cout << "La lista tiene ahora longitud: " << Initial.Length() << std::endl;
//    std::cout << "Introduzca la posicion y el valor a anadir (i.e: pos value): ";
//    std::cin >> sz >> value;
//    Initial.AddPos(value,sz);
//    Initial.Show();
//    std::cout << "Introduzca la posicion que quieres obtener: ";
//    std::cin >> value;
//    std::cout << "El valor de la pos " << value << " es " << Initial.Obtain(value)->Get_Data() << std::endl;
//    std::cout << "Ahora liberamos memoria: " << std::endl;
//    Initial.Release();
//    Initial.Show();
}