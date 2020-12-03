#include <iostream>
#include <iomanip>
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "HoareMonitor.h"

using namespace std;
using namespace HM;

// #################### Variables globales ########################

const int bff = 4;
const int barra = 2;
mutex terminal; //For printing purposes


// #################################################################

// #################### Funciones Extras #########################

template<int min, int max>
int aleatorio() {
    static default_random_engine generador((random_device())());
    static uniform_int_distribution<int> distribucion_uniforme(min, max);
    return distribucion_uniforme(generador);
}

void wait() {
    this_thread::sleep_for(chrono::milliseconds(aleatorio<20, 120>()));

}

// #################################################################

// ######################## Monitor ###############################

class Bebercio : public HoareMonitor {
private:
        int bebidas[bff], ultima;
        bool empty;
        CondVar amigo[bff], camarero;

public:
        Bebercio();
        int elegir_cocktail();
        void servir_cocktail(int* c);
        void pedir_cocktail(int i);
};

// #################################################################

Bebercio::Bebercio(){
    ultima = -1;
    empty = true;
    camarero = newCondVar();
    for(int i=0;i<bff;i++){
        amigo[i] = newCondVar();
    }
}

int Bebercio::elegir_cocktail(){
    int c = aleatorio<0,bff-1>();
    while(c == ultima)
        c = aleatorio<0,bff-1>();
    return c;
}

void Bebercio::servir_cocktail(int* c){
    if(!empty)
        camarero.wait();
    if(*c == ultima || bebidas[*c] > 0)
        *c = this->elegir_cocktail();
    empty = false;
    bebidas[*c]++;
    amigo[*c].signal();
    ultima = *c;
}

void Bebercio::pedir_cocktail(int i){
    if(bebidas[i] == 0)
        amigo[i].wait();
    empty = true;
    bebidas[i]--;
    camarero.signal();
}

// #################################################################

// #################################################################

void funcion_hebra_barman(MRef<Bebercio> monitor, int i){
    int cocktail;
    while(true){
        cocktail = monitor->elegir_cocktail();
        wait();
        monitor->servir_cocktail(&cocktail);
        terminal.lock();
        cout << "Servido el cocktail nº " << cocktail << " por el barman nº " << i << endl;
        terminal.unlock();
    }
}

// #################################################################

void funcion_hebra_bebedor(MRef<Bebercio> monitor, int i){
    while(true){
        monitor->pedir_cocktail(i);
        terminal.lock();
        cout << "\t\tBebiendo feliz con sus panas el amigo nº " << i << endl;
        terminal.unlock();
        wait();
        terminal.lock();
        cout << "\t\tDale otra al pana nº " << i << endl;
        terminal.unlock();
    }
}

// #################################################################

// #################################################################

int main(){

    MRef<Bebercio> monitor = Create<Bebercio>();
    thread camarero[barra], amigos[bff];

    for(int i=0;i<barra;i++){
        camarero[i] = thread(funcion_hebra_barman,monitor,i);
    }

    for(int i=0;i<bff;i++){
        amigos[i] = thread(funcion_hebra_bebedor,monitor,i);
    }

    for(int i=0;i<barra;i++){
        camarero[i].join();
    }

    for(int i=0;i<bff;i++){
        amigos[i].join();
    }

}
