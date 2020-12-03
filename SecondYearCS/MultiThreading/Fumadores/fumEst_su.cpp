#include <iostream>
#include <cassert>
#include <thread>
#include <iomanip>
#include "HoareMonitor.h"
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "HoareMonitor.h"

using namespace std ;
using namespace HM ;

//**************** Variables globales y compartidas ******+
const int num_fumadores = 3;
//*******************************************************

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

mutex terminal;

template< int min, int max > int aleatorio()
{
    static default_random_engine generador( (random_device())() );
    static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
    return distribucion_uniforme( generador );
}

class FumEstSu : public HoareMonitor{
    private:
        int itemProd; //Basicamente el numero del fumador a consumir
        CondVar mostrador_vacio; //Para saber cuando producir
        CondVar ingr_disp[num_fumadores]; //numero de fumadores

    public:
        FumEstSu();
        void ponerIngrediente(int which); //Cambiamos el itemProd
        void obtenerIngrediente(int which); //Consumimos el itemProd
        void wait(); //Esperamos a que se consuma el itemProd
    };

FumEstSu::FumEstSu(){
    itemProd = -1;
    mostrador_vacio = newCondVar();

    for(int i=0;i<num_fumadores;i++)
        ingr_disp[i] = newCondVar();
}

void FumEstSu::ponerIngrediente(int which){
    itemProd = which;
    ingr_disp[which].signal();
}

void FumEstSu::wait(){
    if(itemProd != -1)
        mostrador_vacio.wait();
}

void FumEstSu::obtenerIngrediente(int which){
    if(itemProd != which)
        ingr_disp[which].wait();
    itemProd=-1;
    mostrador_vacio.signal();
}

///-------------------------------------------------------------------------
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

    const int num_ingrediente = aleatorio<0,num_fumadores-1>() ;
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
void funcion_hebra_estanquero( MRef<FumEstSu> monitor )
{
    int item;
    while (true) {
        item = producir_ingrediente();
        monitor->ponerIngrediente(item);
        terminal.lock();
        cout << "Hemos producido un ingrediente: " << item << endl;
        terminal.unlock();
        monitor->wait();
    }
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra


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
void  funcion_hebra_fumador( MRef<FumEstSu> monitor, int num_fumador )
{
    while( true )
    {
        monitor->obtenerIngrediente(num_fumador);
        terminal.lock();
        cout << "Hemos consumido el ingrediente: " << num_fumador << endl;
        terminal.unlock();
        fumar(num_fumador);
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

    MRef<FumEstSu> monitor = Create<FumEstSu>();

    thread mostrador(funcion_hebra_estanquero,monitor);
    thread fumadores[num_fumadores];
    for(int i=0;i<num_fumadores;i++){
        fumadores[i] = thread(funcion_hebra_fumador,monitor,i);
    }
    //Nunca termina...
    mostrador.join();
    for(int i=0;i<num_fumadores;i++){
        fumadores[i].join();
    }

    return 0;
}
