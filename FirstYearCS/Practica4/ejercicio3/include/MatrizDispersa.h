#ifndef EJERCICIO3_MATRIZDISPERSA_H
#define EJERCICIO3_MATRIZDISPERSA_H

class MatrizDispersa{
private:
    Valor* valor;
    int fila;
    int columna;
    //Metodo auxiliar para el constructor con vectores.
    int GetMax(int* array,int szr);
    int GetSize(int* vec);
public:
    MatrizDispersa(){
        fila=0;
        columna=0;
        valor = 0;
    }
    MatrizDispersa(MatrizDispersa const &obj);
    MatrizDispersa(int* filas, int* columnas, double* valores);
    void Create(int vfil, int vcol);
    inline void SetValue(int pos, double value){
        if(pos>=0 && pos < fila*columna)
            valor[pos].SetValue(value);
    }
    inline double GetValue(int pos)const{
        if(pos>=0 && pos < fila*columna)
            return valor[pos].GetValue();
    }
    MatrizDispersa operator +(MatrizDispersa const &obj);
    bool operator == (MatrizDispersa const &obj);
    void Show();
    ~MatrizDispersa();
};

#endif //EJERCICIO3_MATRIZDISPERSA_H
