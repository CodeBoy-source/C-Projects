#include <iostream>
#ifndef ESTIMADORDISTANCIA_H
#define ESTIMADORDISTANCIA_H

using namespace std;
class EstimadorDistancia{
    static const int TAM=100000;
    int muestras;
    double estimacion;
    double vect[TAM];

public:
    void mostrarvector(){
        cout << "Los puntos son:" << endl;
        for(int i=0;i<muestras;i++){
            cout << vect[i] << " ";
        }
    }
    int Getmuestras(){
        return muestras;
    }
    void Setmuestras(int n){
        muestras=n;
    }
    double Getestimacion(){
        return estimacion;
    }
    void Setestimacion(double n){
        estimacion=n;
    }

    EstimadorDistancia(long int);

    void estimar();

    double devolverDistancias(double[],long int&);

};

#endif
