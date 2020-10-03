#include <iostream>
#include <cmath>
#include "circulo.h"
using namespace std;
/**
 * Metodo para mostrar por pantalla los datos de un objeto.
 */
void Circulo::mostrar() const {
    // Formato de escritura del círculo: radio - (x,y)
    cout << "circulo de radio: " << getRadio() << " - "  <<
         "(" << getCentro().getX() << "," << getCentro().getY() << ")" << endl;
}

/**
 * Metodo para preguntar los valores de los datos miembro al
 * usuario. Por implementar (se recomienda leer el radio y
 * delegar en la clase Punto la lectura del punto que hace de
 * centro)
 */
void Circulo::leerDatos(){
    cout << "Circulo de centro: ";
    Punto centro;
    centro.leerDatos();
    setCentro(centro);
    cout << "y de radio: ";
    int radio;
    cin >> radio;
    setRadio(radio);
}

/**
 * Metodo para calcular el area de un circulo
 * @return
 */
double Circulo::calcularArea() const {
    // Se calcula el area
    double area=2*M_PI*pow(radio,2);

    // Se devuelve el resultado
    return area;
}
