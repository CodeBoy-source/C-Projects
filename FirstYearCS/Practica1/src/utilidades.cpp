#include <cmath>
#include "utilidades.h"
/**
 * @brief Calcula la distancia entre dos puntos. Se trata de
 * una funcion externa a la clase Punto. A implementar
 * @param p1 primer punto
 * @param p2 segundo punto
 * @return la distancia entre el punto @a p1 y el punto @a p2
 */
double calcularDistancia(Punto p1, Punto p2) {
    double euclidean_distance = sqrt(pow(p1.getX()-p2.getX(),2)+pow(p1.getY()-p2.getY(),2));
    return abs(euclidean_distance);
}

/**
 * @brief Calcula el punto que está entre dos puntos dados con distancia
 * mínima a ambos. Se trata de una funcion externa a la clase Punto. A
 * implementar
 * @param p1 primer punto
 * @param p2 segundo punto
 * @return un punto entre el punto @a p1 y el punto @a p2 con distancia
 * mínima a ambos
 */
Punto calcularPuntoMedio(Punto p1, Punto p2) {
    int mx = (p1.getX()+p2.getX())/2;
    int my = (p1.getY()+p2.getY())/2;
    Punto medio(mx,my);
    return medio;
}
/**
 * @brief Calcula la distancia entre dos circulos. Funcion externa a
 * ambas clases
 * @param c1 primer círculo
 * @param c2 segundo círculo
 * @return la distancia entre el círculo @a c1 y el círculo @a c2
 * La distancia entre dos círculos se define como la distancia entre los
 * centros menos los dos radios.
 * Nótese que la distancia puede ser negativa si los círculos se intersecan
 */
double calcularDistancia(Circulo c1, Circulo c2) {
    // Se recuperan los centros de ambos circulos
    Punto cc1=c1.getCentro();
    Punto cc2=c2.getCentro();

    // Se calcula la distancia entre los dos puntos
    double distancia=calcularDistancia(cc1, cc2);

    // Se devuelve el valor calculado
    return distancia;
}
/**
 * @brief Comprueba si un punto es interior a un círculo. FUncion externa
 * a las clases
 * @param p punto a comprobar
 * @param c circulo
 * @retval true si el punto @a p es interior al círculo @a c
 * @retval false en caso contrario
 */
bool comprobarInterior(Punto p, Circulo c) {
    bool interior=false;

    // Se calcula si la distancia entre el punto y el centro
    // del circulo es menor que el radio del circulo
    Punto cc=c.getCentro();
    double radio=c.getRadio();

    // Se calcula la distancia
    double distancia=calcularDistancia(p, cc);

    // Si es interior, se cambia el valor del flag
    if(distancia <= radio){
        interior=true;
    }
    // Se devuelve el valor de interior
    return interior;
}