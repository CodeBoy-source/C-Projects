#include "Punto.h"
#include <iostream>
using namespace std;

void Punto::Show() {
    cout << x << "," << y;
}
bool Punto::operator ==(Punto const &obj){
    return (x==obj.x && y==obj.y);
}
