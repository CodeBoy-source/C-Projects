#include<iostream>
#include <cmath>
#include "EstimadorDistancia.h"
using namespace std ;

/*constructor con parametros que asigna el numero de muestras y inicializa estimacion a 0 */

EstimadorDistancia::EstimadorDistancia(long int numeroMuestras){
        for(int i=0;i<TAM;i++){
            vect[i]=0;
        }
        // Asigna el dato miembro muestras
        muestras=numeroMuestras;

        // Inicializa a 0 la estimacion
        estimacion=0;
    }

    /*funcion void que generera los puntos aleatorios */

    void EstimadorDistancia::estimar(){
        // Se inicializa el generador de numeros aleatorios
        srand(time(NULL));

        double x1, y1, x2, y2;
        double distancia;
        // Se generan tantos pares de puntos como indique el
        // dato miembro muestras
        for(int i=0; i < muestras; i++){
            x1=rand()/(double)RAND_MAX;
            y1=rand()/(double)RAND_MAX;
            x2=rand()/(double)RAND_MAX;
            y2=rand()/(double)RAND_MAX;

            distancia=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
            vect[i]=distancia;

        }

    }

    /**
    * Metodo para devolver el resultado de la estimacion
    * @param distanciasObtenidas array en que devolver las distancias calculadas
    * @param util paraa devolver el numero de distancias que se calcularon
    */
    double EstimadorDistancia::devolverDistancias(double distanciasObtenidas[], long int &muestras){
        double media=0;
        for(int i=0;i < muestras;i++){
            estimacion=estimacion+vect[i];
        }
        media=estimacion/muestras;
        return media;
    }
