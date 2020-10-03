#ifndef EJERCICIO3_VALOR_H
#define EJERCICIO3_VALOR_H

class Valor{
private:
    int fila;
    int columna;
    double valor;
public:
    Valor(){
        fila =0;
        columna=0;
        valor=0;
    }
    inline void Set(int vfila, int vcol, double val){
        fila=vfila;
        columna=vcol;
        valor = val;
    }
    inline int GetFila()const{
        return fila;
    }
    inline int GetCol()const{
        return columna;
    }
    inline double GetValue()const{
        return valor;
    }
    inline void SetValue(double value){
        valor = value;
    }
    void Show();
};

#endif //EJERCICIO3_VALOR_H
