#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "punto.h"
#include "circulo.h"

double calcularDistancia(Punto p1, Punto p2);
Punto calcularPuntoMedio(Punto p1, Punto p2);
double calcularDistancia(Circulo c1, Circulo c2);
bool comprobarInterior(Punto p, Circulo c);
#endif