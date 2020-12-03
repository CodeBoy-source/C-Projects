#include <iostream>
#include <iomanip>
#include <cassert>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include "HoareMonitor.h"

using namespace std;
using namespace HM;

mutex terminal; //For printing purposes only

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template<int min, int max>
int aleatorio() {
    static default_random_engine generador((random_device())());
    static uniform_int_distribution<int> distribucion_uniforme(min, max);
    return distribucion_uniforme(generador);
}

class Peaje : public HoareMonitor {
private:
    int cab1, cab2;
    CondVar primera, segunda;
public:
    Peaje();

    int llegada_peaje();

    void pagado(int cabina);
};

Peaje::Peaje() {
    cab1 = cab2 = 0;
    primera = newCondVar();
    segunda = newCondVar();
}

int Peaje::llegada_peaje() {
    int x;
    if (cab1 < cab2) {
        cout << "Llega un coche a la cabina 1" << endl;
        x = 1;
        cab1++;
        if (cab1 != 1)
            primera.wait();
    } else {
        cout << "\t\tLlega un coche a la cabina 2" << endl;
        x = 2;
        cab2++;
        if (cab2 != 1)
            segunda.wait();
    }

    return x;
}

void Peaje::pagado(int cabina) {
    if (cabina == 1) {
        cout << "## Liberamos la cabina 1 ##" << endl;
        cab1--;
        primera.signal();
    } else {
        cout << "\t\t-- Liberamos la cabina 2 --" << endl;
        cab2--;
        segunda.signal();
    }
}

void funcion_hebra_coche(MRef<Peaje> monitor) {
    int cabina;
    while (true) {
        cabina = monitor->llegada_peaje();
        // calcular milisegundos aleatorios de duración de la acción)
        chrono::milliseconds duracion_produ( aleatorio<10,100>() );
        cout << "Nuevo coche de la cabina " << cabina << " pagando ( " << duracion_produ.count() << " milisegundos ) " << endl;
        this_thread::sleep_for(duracion_produ); //Pagando
        monitor->pagado(cabina);
        this_thread::sleep_for(chrono::milliseconds(aleatorio<20, 100>())); // RS
    }
}

int main() {
    const int n_hebras = 6;
    MRef<Peaje> monitor = Create<Peaje>();

    thread coches[n_hebras];
    for (int i = 0; i < n_hebras; i++)
        coches[i] = thread(funcion_hebra_coche, monitor);

    //Nunca terminan pero por  buena practica :
    for (int i = 0; i < n_hebras; i++)
        coches[i].join();

    return 0;
}