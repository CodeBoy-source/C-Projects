/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// Clase "Clientes"
//
// Fichero: Clientes.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CLIENTES
#define CLIENTES

#include "cliente.h"
#include <string>
#include <iostream>
using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Clientes {

private:

    int 	  num_clientes; // Núm.casillas ocupadas
    Cliente * los_clientes;

public:
    /********************************************************************+**/
    //Constructor sin argumento
    Clientes(){
        num_clientes = 0;
        los_clientes = 0; //Para no apuntar a una direccion de memoria aleatoria.
    }
    //Constructor de copia;
    Clientes(const Cliente &obj);

    //Constructor por Fichero
    Clietnes(const string filename);

    /***********************************************************************/
    // Método de consulta: núm. de clientes

    int NumClientes (void) const;

    /***********************************************************************/
    // Método de cálculo: genera un id_cliente que no existe

    int GeneraIdCliente (void) const;
    /**********************************************************************/
    //Método para Almacenar el objecto en un fichero;
    void EscribirClientes (const string nombre) const;

    /***********************************************************************/
    // Operador << Inserta un conjunto "Clientes" en un flujo de texto.

    friend ostream & operator << (ostream & out, const Clientes & clientes);

    // Operador >>  Extrae un conjunto "Clientes" de un flujo de texto.

    friend istream & operator >> (istream & in, Clientes & clientes);

    //Operador asignacion =
    void operator =(const Clientes &obj);

    //Operador +=
    void operator +=(const Cliente &obj);

    //operator +
    Clientes* operator +(const Clientes &obj);
    /*********************************************************************/
    //Destructor
    ~Clientes(){
        num_clientes = 0;
        delete [] los_clientes;
    }
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


#endif
