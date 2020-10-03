/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN 
//
// Clase "Cliente"
//
// Fichero: Cliente.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CLIENTE
#define CLIENTE

#include <string>
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Cliente {

private:

    int 	id_cliente;
    double 	descuento;
    string 	nombre;
    string 	NIF;

public:

    /***********************************************************************/
    // Constructores

    Cliente(){ //Para inicializar las variables y no tener un comportamiento ambiguo.
        id_cliente = 0;
        descuento = 0;
        nombre = " ";
        NIF = " ";
    }

    Cliente(const Cliente &obj);

    Cliente (string el_NIF, double el_descuento,
             string el_nombre, int el_id_cliente=0);

    /***********************************************************************/
    // Método de escritura: modifica el id_cliente

    void SetIdCliente (int el_id_cliente);

    /***********************************************************************/
    // Método de consulta: devuelve el id_clientede un "Cliente"

    int GetIdCliente (void) const;

    /***********************************************************************/
    // Método de consulta: devuelve el descuento de un "Cliente"

    double GetDescuentoCliente (void) const;

    /***********************************************************************/
    // Método de consulta: devuelve el nombre de un "Cliente"

    string GetNombreCliente (void) const;

    /***********************************************************************/
    // Método de consulta: devuelve el NIF de un "Cliente"

    string GetNIFCliente (void) const;

    /***********************************************************************/
    // Operador << Inserta un "Cliente" en un flujo de texto.

    friend ostream & operator << (ostream & out, const Cliente & un_cliente);

    /***********************************************************************/
    // Operador >> Extrae un "Cliente" de un flujo de texto.

    friend istream & operator >> (istream & in, Cliente & un_cliente);
    /***********************************************************************/
    //Operador = Asignacion
    void operator =(const Cliente &obj);

    //Operador ==
    bool operator ==(const Cliente &obj);

    /***********************************************************************/
    //Destructor
    //No es necesario ya que ya viene implementado para variables por defecto.
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif