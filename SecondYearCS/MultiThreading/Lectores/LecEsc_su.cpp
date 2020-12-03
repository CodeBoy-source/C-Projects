#include <iostream>
#include <iomanip>
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "HoareMonitor.h"

using namespace std ;
using namespace HM ;

template< int min, int max > int aleatorio()
{
    static default_random_engine generador( (random_device())() );
    static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
    return distribucion_uniforme( generador );
}

void wait()
{
    this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

}

class Lec_Esc : public HoareMonitor{
private:
    int n_lec;
    bool escrib;
    CondVar lectura, escritura;

public:
    Lec_Esc();
    void ini_lectura();
    void fin_lectura();
    void ini_escritura();
    void fin_escritura();
};

Lec_Esc::Lec_Esc(){
    n_lec = 0;
    escrib = false;
    lectura = newCondVar();
    escritura = newCondVar();
}
void Lec_Esc::ini_lectura(){
    if(escrib || escritura.get_nwt()>0)
        lectura.wait();
    n_lec++;
    lectura.signal();
}

void Lec_Esc::fin_lectura(){
    n_lec--;
    if(n_lec == 0)
        escritura.signal();
}

void Lec_Esc::ini_escritura(){
    if ( n_lec > 0  || escrib )
        escritura.wait();
    escrib = true;
}

void Lec_Esc::fin_escritura(){
    escrib = false;
    if(!lectura.empty())
        lectura.signal();
    else
        escritura.signal();
}

void Lector(MRef<Lec_Esc> monitor, int n_hebra){
    while(true){
        monitor->ini_lectura();
        cout << "Lector " << n_hebra << " esta leyendo.." << endl;
        wait();
        monitor->fin_lectura();
    }
}

void Escritor(MRef<Lec_Esc> monitor, int n_hebra){
    while(true){
        monitor->ini_escritura();
        cout << "\t\tEscritor " << n_hebra << " escribiendo.." << endl;
        wait();
        monitor->fin_escritura();
    }
}

int main(void){

    const int num_escritores = 2, num_lectores = 2;
    thread escritores[num_escritores], lectores[num_lectores];
    MRef<Lec_Esc> monitor = Create<Lec_Esc>();

    for(int i=0;i<num_escritores;i++)
        escritores[i] = thread(Escritor, monitor,i);

    for(int i=0; i < num_lectores; i++)
        lectores[i] = thread(Lector, monitor,i);


    //Nunca termina
    for(int i=0; i < num_escritores; i++)
        escritores[i].join();

    for(int i=0; i < num_lectores; i++)
        lectores[i].join();

}