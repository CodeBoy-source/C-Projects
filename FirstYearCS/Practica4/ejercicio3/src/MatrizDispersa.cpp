#include <iostream>
#include "Valor.h"
#include "MatrizDispersa.h"
using namespace std;

void MatrizDispersa::Create(int vfil, int vcol){
        fila = vfil;
        columna = vcol;
        valor = new Valor[fila*columna];
        double val; int cont=0;
        Valor A;
        for(int i=0; i<vfil;i++){
            for(int j=0; j<vcol; j++){
                cin >> val;
                A.Set(i,j,val);
                *(valor+cont) = A;
                cont++;
            }
        }
}

/**
 * Constructor de copia para copiar los valores
 * directamente para que puedan ser modificados
 * independientemente.
 * @param obj
 */
MatrizDispersa::MatrizDispersa(MatrizDispersa const &obj){
    fila = obj.fila;
    columna = obj.columna;
    valor = new Valor[fila*columna];
    for(int i=0; i<fila*columna;i++){
        *(valor+i) = obj.valor[i];
    }
}
/**
 * Metodo auxiliar para el constructor mediante vector
 * que calcula la longitud maxima hallada dentro del vector
 * que define su longitud y las posiciones de los valores.
 * @param array
 * @param szr
 * @return
 */
int MatrizDispersa::GetMax(int* array,int szr){
    int max = 0;
    for(int i = 0; i<szr;i++){
        if(max<array[i])
            max = array[i];
    }
    return max;
}
int MatrizDispersa::GetSize(int* vec){
    int cont = 1;
    for(int i=1; *(vec+i) >= 0;i++){
        cont++;
    }
    return cont;
}
/**
 * Constructor segun vectores que se auxilia de un metodo extra que
 * calcula la longitud de la matrix segun el valor maximo que se halla
 * en los vectors con las posiciones de los valores.
 * @param filas
 * @param columnas
 * @param szr
 * @param valores
 */
MatrizDispersa::MatrizDispersa(int *filas, int *columnas, double *valores) {
    int szr = GetSize(filas);
    int szf = GetMax(filas,szr);
    int szc = GetMax(columnas,szr);
    fila = szf;
    columna = szc;
    valor = new Valor[szc*szf];
    for(int i=0; i<szr;i++){
        valor[szc*(filas[i]-1)+(columnas[i]-1)].Set(filas[i]-1,columnas[i]-1,valores[i]);
    }
}
/**
 * Primeramente comprobamos que sean del mismo tamaño (condicion
 * previa para poder sumar matrices) luego procedemos a crear una
 * nueva matrix de la misma dimension que sus valores sumados.
 * @param obj
 * @return
 */
MatrizDispersa MatrizDispersa::operator +(MatrizDispersa const &obj){
    if(*this==obj) {
        MatrizDispersa Extra(obj);
        for (int i = 0; i < fila*columna;i++){
            Extra.SetValue(i,valor[i].GetValue()+obj.valor[i].GetValue());
        }
        return Extra;
    }
    else {
        MatrizDispersa Extra;
        return Extra;
    }
}
/**
 * Operadores sobrecargados para poder comprobar si dos matrices
 * son del mismo tamano.
 * @param obj
 * @return
 */
bool MatrizDispersa::operator == (MatrizDispersa const &obj){
    return (obj.fila==fila&&obj.columna==columna);
}
/**
 * En nuestra matriz dispersa sabemos que la longitud de la matriz
 * es fila*columna.
 */
void MatrizDispersa::Show(){
    for(int i=0; i < fila*columna; i++){
        cout << valor[i].GetValue() << " ";
        if((i+1)%columna==0)
            cout << endl;
    }
}
/**
 * borramos nuestro vector y asignamos todos los valores de la clase
 * a cero para evitar comportamiento ambiguo.
 */
MatrizDispersa::~MatrizDispersa(){
    delete [] valor;
    valor = 0;
    fila = 0;
    columna = 0;
}

