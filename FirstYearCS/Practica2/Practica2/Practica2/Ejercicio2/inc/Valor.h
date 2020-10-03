
#ifndef VALOR_H
#define VALOR_H

#include <iostream>

using namespace std;

class Valor{
   private:
    int fila;
    int columna;
    double valor;

  public:
    /**
     * Constructor por defecto
     */
    Valor(){
        fila=0;
        columna=0;
        valor=0.00;
    }

    /**
     * Constructor de la clase
     * @param fila
     * @param columna
     * @param valor
     */
    Valor(int fila, int columna, double valor){
        fila=fila;
        columna=columna;
        valor=valor;
    }

    /**
     * Metodo para mostrar el contenido de un objeto
     */
    void mostrar(){
        cout << "fila= " << fila << endl;
        cout << "columna= " << columna << endl;
        cout << "valor= " << valor << endl;
    }

    void SetFila(int xfila){
        fila=xfila;
    }

    void SetColumna(int xcolumna){
        columna=xcolumna;
    }

    void SetValor(double xvalor){
        valor=xvalor;
    }

    int GetFila(){
        return fila;
    }

    int GetColumna(){
        return columna;
    }

    double GetValor(){
        return valor;
    }
};
#endif //VALOR_H
