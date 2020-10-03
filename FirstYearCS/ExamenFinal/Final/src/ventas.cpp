#include <iostream>
#include <fstream>
#include "venta.h"
#includde "ventas.h"
using namespace std;

/*************************************************************/
//Metodo para obtener la venta media segun el num de ventas.
double Ventas::GetVentaMedia(void) const{
    double result = 0;
    for(int i=0;i<num_ventas;i++){
        result += las_ventas[i].GetTotal();
    }
    return (result/num_ventas);
}

/************************************************************/
//Operadores
bool Ventas::operator >(const Ventas &ventas){
    return (this->GetVentaMedia() > ventas.GetVentaMedia());
}

bool Ventas::operator ==(const Ventas &ventas){
    return (this->GetVentaMedia() == ventas.GetVentaMedia());
}

/***********************************************************/
