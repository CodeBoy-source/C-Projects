/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// Clase "Ventas"
//
// Fichero: ventas.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef VENTAS
#define VENTAS

#include "venta.h"

#include <string>
#include <iostream>
using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Ventas {

private:

    int 	  num_ventas; // Núm.casillas ocupadas
    Venta   * las_ventas;

public:

    /***********************************************************************/
    // Método de consulta: núm. de ventas

    int NumVentas (void) const;

    /***********************************************************************/
    // Método que guarda el contenido de una colección "Ventas" en un
    // fichero de texto llamado "nombre".

    void EscribirVentas (const string nombre) const;

    /***********************************************************************/
    // Método que rellena una colección "Ventas" (que ya existe) a partir
    // de los datos presentes en el fichero de texto llamado "nombre".

    void LeerVentas (const string nombre);

    /***********************************************************************/
    //Metodo para obtener la venta media segun el numero total de ventas.

    double GetVentaMedia(void) const;

    /***********************************************************************/
    // Operador << Inserta un conjunto "Ventas" en un flujo de texto.

    friend ostream & operator << (ostream & out, const Ventas & ventas);

    // Operador >>  Extrae un conjunto "Ventas" de un flujo de texto.

    friend istream & operator >> (istream & in, Ventas & ventas);

    //Operador > En funcion de la venta media de dos conjuntos de ventas

    bool operator >(const Ventas &ventas);

    //Operador == En funcion de la venta media de dos conjuntos de ventas

    bool operator ==(const Ventas &ventas);

    /***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


#endif
