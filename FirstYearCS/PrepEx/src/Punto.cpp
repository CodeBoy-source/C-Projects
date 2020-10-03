#include <iostream>
#include "Punto.h"
using namespace std;

ostream & operator << (ostream &out, const Punto &obj){
    out << obj.x << " " << obj.y;
    return out;
}
Punto Punto::operator = (const Punto &obj){
    this->x = obj.x;
    this->y = obj.y;
}
Punto::~Punto(){
    x = 0;
    y = 0;
}