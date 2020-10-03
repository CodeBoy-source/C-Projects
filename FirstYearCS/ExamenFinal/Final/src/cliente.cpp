#include "cliente.h"
#include <iostream>
using namespace std;

/**********************************************/
//Constructor de copia;
Cliente::Cliente(const Cliente &obj){
    id_cliente = obj.id_cliente;
    descuento = obj.descuento;
    nombre = obj.nombre;
    NIF = obj.NIF;
}
/**********************************************/
//operador asignacion
void Cliente::operator =(const Cliente &obj){
    this->id_cliente = obj.id_cliente;
    this->descuento = obj.descuento;
    this->nombre = obj.nombre;
    this->NIF = obj.NIF;
}

/*********************************************************/
//Operador ==
bool operator ==(const Cliente &obj){
    return ((NIF == obj.NIF)? true:false);
}

/*********************************************************/
//operador <<
ostream& operator <<(ostream &out, const Cliente &un_cliente){
    out << un_cliente.id_cliente << " " << un_cliente.descuento <<
        " " << un_cliente.nombre << " " << un_cliente.NIF;

    return out;
}

/*********************************************************/
//operator >>
istream & operator >> (istream & in, Cliente & un_cliente){
    in >> un_cliente.id_cliente >> un_cliente.descuento >>
        un_cliente.nombre >>  un_cliente.NIF;

    return in;
}