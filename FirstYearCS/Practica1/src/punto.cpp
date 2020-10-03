#include <iostream>
#include "punto.h"
using namespace std;

/**
 * Muestra el contenido del objeto por pantalla. A implementar
 */
void Punto::mostrar_punto() const {
    // Formato de escritura del punto: (x,y)
    cout << "(" << getX() << "," << getY() << ")" << endl;
}

/**
 * Metodo para preguntar los valores de los datos miembro al
 * usuario. Por implementar
 */
void Punto::leerDatos(){
    // Se leen los datos del usaurio
    cout << " (x,y): ";
    int vx,vy;
    cin >> vx >> vy;
    setX(vx);
    setY(vy);
}