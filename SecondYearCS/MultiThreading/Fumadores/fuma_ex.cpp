#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

//**************** Variables globales y compartidas ******+
int last = -1;
const int num_fumadores = 4;
Semaphore ingr_disp[num_fumadores] = {0,0,0,0};
Semaphore mostr_vacio = 1;
mutex terminal;
//*******************************************************

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

//-------------------------------------------------------------------------
// Función que simula la acción de producir un ingrediente, como un retardo
// aleatorio de la hebra (devuelve número de ingrediente producido)

int producir_ingrediente()
{
   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_produ( aleatorio<10,100>() );
    terminal.lock();
   // informa de que comienza a producir
   cout << "Estanquero : empieza a producir ingrediente (" << duracion_produ.count() << " milisegundos)" << endl;
    terminal.unlock();
   // espera bloqueada un tiempo igual a ''duracion_produ' milisegundos
   this_thread::sleep_for( duracion_produ );

   const int num_ingrediente = aleatorio<0,num_fumadores-2>() ;
    terminal.lock();
   // informa de que ha terminado de producir
   cout << "Estanquero : termina de producir ingrediente " << num_ingrediente << endl;
    terminal.unlock();

   return num_ingrediente ;
}

//----------------------------------------------------------------------
/**
 * @brief Producimos un ingrediente y por lo tanto debemos indicar que
 * no tenemos el mostrador vacío ( Aumentando el valor del semaforo mostr_vacio ) y
 * entonces debemos esperar a que el fumador adecuado coja el ingrediente que
 * le falta ( Utilizando nuestro vector intermedio ).
 */
void funcion_hebra_estanquero(  )
{
    while (true) {
        int num = producir_ingrediente();
        if (last==-1 && num==2){
            num += aleatorio<0,1>();
            last = num;
            cout << "\tEsta vez empezamos con el fumador: " << last << endl;
        }else if(num==2){
            cout << "\t\tCambiamos... " << endl;
            if(num==last)
                num++;
            last = num;
        }
        sem_wait(mostr_vacio);
        sem_signal(ingr_disp[num]);

    }
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar
    terminal.lock();
    cout << "Fumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;
    terminal.unlock();
   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar
    terminal.lock();
    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;
    terminal.unlock();
}

//----------------------------------------------------------------------
/**
 * @brief siempre y cuando haya un ingrediente disponible ( en nuestro
 * vector de ingredientes ), deberemos entonces suponer que el mostrador
 * estará vacío ( ya que cogeremos el ingrediente disponible ) y podemos
 * entonces terminar nuestro cigarro y fumarlo. ( Hace falta 1 ingrediente ).
 * Con esta configuración se mantiene que puedan fumar concurrentemente
 * mientras que solamente se produce un ingrediente si alguien coge el que está disponible.
 * @param num_fumador número del fumador en cuestión
 */
void  funcion_hebra_fumador( int num_fumador )
{
   while( true )
   {
    sem_wait(ingr_disp[num_fumador]);
    fumar(num_fumador);
    sem_signal(mostr_vacio);
   }
}

//----------------------------------------------------------------------

/**
 * @brief sintaxis básica de hebras y vectores de hebras con funcione
 * individuales. Y en el orden de espera adecuado.
 * @return Succeso / error
 */
int main()
{
    cout << "############### Simulacro de Examen #############" << endl;
    cout << "1 - Hemos elegido que se turnen los fumadores 2-3" << endl;
    cout << "############### Brian Sena Simons ###############" << endl;
   thread mostrador(funcion_hebra_estanquero);
   thread fumadores[num_fumadores];
   for(int i=0;i<num_fumadores;i++){
       fumadores[i] = thread(funcion_hebra_fumador,i);
   }
   mostrador.join();

   for(int i=0;i<num_fumadores;i++){
       fumadores[i].join();
   }

   return 0;
}
