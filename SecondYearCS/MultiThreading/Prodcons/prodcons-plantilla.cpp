#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

//**********************************************************************
// variables compartidas

const int num_items = 40 ,   // número de items
	       tam_vec   = 10 ;   // tamaño del buffer
unsigned  cont_prod[num_items] = {0}, // contadores de verificación: producidos
          cont_cons[num_items] = {0}; // contadores de verificación: consumidos

//************************* Mis variables *******************************++
Semaphore libres = tam_vec, ocupadas=0; //Necesitamos dos semáforos en total
int vec[num_items] = {0}; //Un vector temporal intermedio para almacenar los datos
//*************************************************************************

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

int producir_dato()
{
   static int contador = 0 ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   cout << "producido: " << contador << endl << flush ;

   cont_prod[contador] ++ ;
   return contador++ ;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato )
{
   assert( dato < num_items );
   cont_cons[dato] ++ ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   cout << "                  consumido: " << dato << endl ;

}


//----------------------------------------------------------------------

void test_contadores()
{
   bool ok = true ;
   cout << "comprobando contadores ...." ;
   for( unsigned i = 0 ; i < num_items ; i++ )
   {  if ( cont_prod[i] != 1 )
      {  cout << "error: valor " << i << " producido " << cont_prod[i] << " veces." << endl ;
         ok = false ;
      }
      if ( cont_cons[i] != 1 )
      {  cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces" << endl ;
         ok = false ;
      }
   }
   if (ok)
      cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

//----------------------------------------------------------------------
/**
 * @brief la hebra deberá producir un nuevo dato y almacenarlo en nuestro
 * vector intermedio siempre y cuando haya al menos una celda libre. Tras hacerlo
 * deberá disminuir el numero de celdas libres y aumentar el numero de celdas
 * ocupadas ( Semaforos libres y ocupadas, respectivamente ).
 */
void  funcion_hebra_productora(  )
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
        unsigned dato = producir_dato() ; //Primero debemos producir un dato
        vec[i] = dato; //Almacenamos el dato
      sem_wait(libres); //Reducimos el número de celdas libres
      sem_signal(ocupadas); //Aumentamos el número de celdas ocupadas
   }
}

//----------------------------------------------------------------------
/**
 * @brief La hebra consumidora deberá consumir aquellos datos generados
 * y almacenados en nuestro vector intermedio, siempre y cuando haya al menos
 * una celda del vector ocupada. Antes de hacerlo deberá reducir
 * el número de celdas ocupadas y aumentar el número de celdas libres
 * (Semaforos ocupadas / libres ) para que se vuelva a producir un dato
 * de forma concurrente.
 */
void funcion_hebra_consumidora(  )
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      sem_wait(ocupadas); //Reducimos el número de celdas ocupadas
      sem_signal(libres); //Aumentamos el número de celdas libres
      consumir_dato( vec[i] ) ; //Consumimos el dato apropiado.
    }
}
//----------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------" << endl
        << "Problema de los productores-consumidores (solución LIFO)." << endl
        << "--------------------------------------------------------" << endl
        << flush ;

   thread hebra_productora ( funcion_hebra_productora ),
          hebra_consumidora( funcion_hebra_consumidora );

   hebra_productora.join() ;
   hebra_consumidora.join() ;

   test_contadores();
}
