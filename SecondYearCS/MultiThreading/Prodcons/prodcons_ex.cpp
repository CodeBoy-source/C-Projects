// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Seminario 2. Introducción a los monitores en C++11.
//
// archivo: prodcons_1.cpp
// Ejemplo de un monitor en C++11 con semántica SC, para el problema
// del productor/consumidor, con un único productor y un único consumidor.
// Opcion LIFO (stack)
//
// Historial:
// Creado en Julio de 2017
// -----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cassert>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include "HoareMonitor.h"

using namespace std ;
using namespace HM ;

constexpr int
        num_items  = 40 ;           // número de items a producir/consumir

mutex mtx ;                         // mutex de escritura en pantalla
unsigned
        cont_prod[num_items],       // contadores de verificación: producidos
cont_cons[num_items];       // contadores de verificación: consumidos

const int N_Prod = 4;               //Número de hebras productores
const int N_Cons = 4;               //Número de hebras consumidoras.

int buffer2[N_Prod] = {0};          //Cantidad producida por cada hebra.

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
    static default_random_engine generador( (random_device())() );
    static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
    return distribucion_uniforme( generador );
}

//**********************************************************************
// funciones comunes a las dos soluciones (fifo y lifo)
//----------------------------------------------------------------------

int producir_dato(int n_hebra)
{
    int contador =(num_items/N_Prod)*n_hebra;
    this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
    mtx.lock();
    contador+=buffer2[n_hebra];
    cout << "producido: " << contador << " buf[" << n_hebra << "]= " << buffer2[n_hebra] << endl << flush ;
    mtx.unlock();
    cont_prod[contador]++;
    buffer2[n_hebra]++;
    return contador;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato )
{
    if ( num_items < dato )
    {
        cout << " dato === " << dato << ", num_items == " << num_items << endl ;
        assert( dato < num_items );
    }
    cont_cons[dato] ++ ;
    this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
    mtx.lock();
    cout << "                  consumido: " << dato << endl ;
    mtx.unlock();
}
//----------------------------------------------------------------------

void ini_contadores()
{
    for( unsigned i = 0 ; i < num_items ; i++ )
    {
        cont_prod[i] = 0 ;
        cont_cons[i] = 0 ;
    }
}

//----------------------------------------------------------------------

void test_contadores()
{
    bool ok = true ;
    cout << "comprobando contadores ...." << flush ;

    for( unsigned i = 0 ; i < num_items ; i++ )
    {
        if ( cont_prod[i] != 1 )
        {
            cout << "error: valor " << i << " producido " << cont_prod[i] << " veces." << endl ;
            ok = false ;
        }
        if ( cont_cons[i] != 1 )
        {
            cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces" << endl ;
            ok = false ;
        }
    }
    if (ok)
        cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

// *****************************************************************************
// clase para monitor buffer, version LIFO, semántica SC, un prod. y un cons.

class ProdCons1SC : public HoareMonitor
{
private:
    static const int           // constantes:
    num_celdas_total = 10;   //  núm. de entradas del buffer
    int                        // variables permanentes
    pares[num_celdas_total],
    impares[num_celdas_total],//  buffer de tamaño fijo, con los datos
    pares_libre,
    impares_libre;          //  indice de celda de la próxima inserción

    CondVar         // colas condicion:
    ocupadas,                //  cola donde espera el consumidor (n>0)
    libres ;                 //  cola donde espera el productor  (n<num_celdas_total)

public:                    // constructor y métodos públicos
    ProdCons1SC(  ) ;           // constructor
    int  leer();                // extraer un valor (sentencia L) (consumidor)
    void escribir( int valor, int n_hebra); // insertar un valor (sentencia E) (productor)
} ;
// -----------------------------------------------------------------------------

ProdCons1SC::ProdCons1SC(  )
{
    pares_libre = 0;
    impares_libre = 0;
    ocupadas = newCondVar();
    libres = newCondVar();
}
// -----------------------------------------------------------------------------
// función llamada por el consumidor para extraer un dato

int ProdCons1SC::leer(  )
{

    // esperar bloqueado hasta que 0 < num_celdas_ocupadas
    if ( pares_libre == 0 && impares_libre == 0 )
        ocupadas.wait( );

    // hacer la operación de lectura, actualizando estado del monitor
    assert( 0 < pares_libre || 0 < impares_libre);

    if(pares_libre){
        pares_libre--;
        const int valor = pares[pares_libre];
        libres.signal();
        return valor;
    }else{
        impares_libre--;
        const int valor = impares[impares_libre];
        libres.signal();
        return valor;
    }


}
// -----------------------------------------------------------------------------

void ProdCons1SC::escribir( int valor, int n_hebra )
{
    // esperar bloqueado hasta que num_celdas_ocupadas < num_celdas_total
    if ( pares_libre == num_celdas_total && n_hebra%2==0 ||
        impares_libre == num_celdas_total && n_hebra%2!=0)
        libres.wait( );

    //cout << "escribir: ocup == " << num_celdas_ocupadas << ", total == " << num_celdas_total << endl ;
    assert( pares_libre < num_celdas_total );
    assert( impares_libre < num_celdas_total );

    // hacer la operación de inserción, actualizando estado del monitor
    if(n_hebra%2==0) {
        cout << "------ Ha escrito una hebra par ------" << endl;
        pares[pares_libre] = valor;
        pares_libre++;
    }else {
        cout << "###### Ha escrito una hebra impar ######" << endl;
        impares[impares_libre] = valor;
        impares_libre++;
    }

    // señalar al consumidor que ya hay una celda ocupada (por si esta esperando)
    ocupadas.signal();
}
// *****************************************************************************
// funciones de hebras

void funcion_hebra_productora( MRef<ProdCons1SC> monitor, int n_hebra)
{
    for( unsigned i = 0 ; i < num_items/N_Prod ; i++ )
    {
        int valor = producir_dato(n_hebra) ;
        monitor->escribir( valor, n_hebra );
    }
}
// -----------------------------------------------------------------------------

void funcion_hebra_consumidora( MRef<ProdCons1SC> monitor )
{
    for( unsigned i = 0 ; i < num_items/N_Cons ; i++ )
    {
        int valor = monitor->leer();
        consumir_dato( valor) ;
    }
}
// -----------------------------------------a------------------------------------

int main()
{
    cout << "-----------------------------Simulacro De Examen--------------------------------" << endl
         << "Problema de los productores-consumidores (1 prod/cons, Monitor SC, buffer FIFO). " << endl
         << "------------------------------Brian Sena Simons---------------------------------" << endl
         << flush ;

    MRef<ProdCons1SC> monitor = Create<ProdCons1SC>();

    thread hebras_consumidoras[N_Cons],
            hebras_productoras[N_Prod];

    for(int i = 0; i < N_Prod; i++){
        hebras_productoras[i] = thread( funcion_hebra_productora,monitor,i);
    }

    for(int i = 0; i < N_Cons; i++){
        hebras_consumidoras[i] = thread( funcion_hebra_consumidora, monitor);
    }

    for(int i=0;i<N_Prod;i++){
        hebras_productoras[i].join();
    }
    for(int i=0;i<N_Cons;i++){
        hebras_consumidoras[i].join();
    }

    // comprobar que cada item se ha producido y consumido exactamente una vez
    test_contadores() ;
}
