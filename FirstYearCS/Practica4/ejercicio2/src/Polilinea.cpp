#include "Punto.h"
#include "Polilinea.h"
#include <iostream>
using namespace std;

void Polilinea::Create(int size){
    num = size;
    int x,y;
    for(int i=0;i<num;i++){
        cin >> x >> y;
        Punto A(x,y);
        *(P+i) = A;
    }
}
/**
 * Constructor de copia, que pasa los valores
 * del primer vector al segundo directamente para que asi
 * podamos modificarlos independientemente
 * @param other
 */
Polilinea::Polilinea(const Polilinea& other){
    num = other.num;
    P = new Punto[num];
    for(int i=0; i<num;i++){
        *(P+i) = other.P[i];
    }
}
/**
 * Metodo de copiar hasta un valor dado para auxiliar en
 * algunos calculos (Sobre todo en agregar punto, ya que
 * alli necesitamos que el objecto que llame al metodo
 * sea mayor que el antigo de manera que el constructor de copia
 * queda obsoleto en este caso).
 * @param until
 * @return
 */
Punto* Polilinea::Copy(int until) {
    Punto* Extra = 0;
    if(until>=0) {
        Extra = new Punto[until+1];
        for (int i = 0; i < num-1; i++) {
            *(Extra + i) = *(P + i);
        }
    }
    return Extra;
}
/**
 * Creamos un vector que sea 1 valor mayor que el antigo,
 * copiamos los valores del antiguo y en la ultima posicion
 * asignamos el valor nuevo. Luego procedemos a cambiar el
 * vector del objecto por este nuevo y lo organizamos.
 * @param A
 */
void Polilinea::AgregarPunto(Punto A){
    num += 1;
    Punto* Extra = this->Copy(num);
    *(Extra+(num-1)) = A;
    delete [] P;
    P = Extra;
    this->Organize();
}
/**
 * utilizamos el Algoritmo -> Selection para organizar el vector.
 */
void Polilinea::Organize(){
    Punto change;
    int index;
    for(int j=0; j<num-1;j++) {
        change = P[j];
        index = j;
        for (int i = j+1; i < num; i++) {
            if (P[i].GetX() < change.GetX()) {
                change = P[i];
                index = i;
            }
        }
        P[index] = P[j];
        P[j] = change;
    }
}
/**
 * Pasamos los valores del primer vector a un nuevo vector
 * Luego pasamos los valores del segundo vector
 * Eliminamos duplicados. (Para ellos hemos sobrecargado
 * el operador == de la clase punto).
 * @param obj
 * @return
 */
Polilinea Polilinea::operator + (Polilinea const &obj){
    Polilinea Extra;
    for(int i = 0; i < num; i++){
        Extra.AgregarPunto(*(P+i));
    }
    for(int i = 0; i < obj.num; i++){
        Extra.AgregarPunto(obj.P[i]);
    }
    Extra.DelDuplicates();
    return Extra;
}
/**
 * Como el vector creado siempre esta ordenado nos basta
 * con comprobar que la posicion siguiente no coincide
 * con la anterior. Para ello hemos sobrecargado el operador
 * == de la clase punto.
 */
void Polilinea::DelDuplicates() {
    int index[num];
    int cont=0;
    for(int i=0;i<num-1;i++){
        if(*(P+i+1)==*(P+i)){
            index[cont] = i;
            cont++;
        }
    }
    for(int i=0;i<cont;i++){
        Remove(index[i]);
    }
}
/**
 * Eliminamos la posicion y movemos los demas valores
 * para ajustarlos al nuevo vector.
 * @param pos
 */
void Polilinea::Remove(int pos){
    if(pos>=0 && pos<num){
        for(int i=pos;i<num-1;i++){
            *(P+i) = *(P+i+1);
        }
        num--;
    }
}

void Polilinea::Show() {
    for(int i=0; i<num;i++){
        cout << "( ";
        P[i].Show();
        cout << " ) ";
    }
    cout << endl;
}
/**
 * Borramos el vector y asignamos todos los
 * valores de la clase a 0;
 */
Polilinea::~Polilinea(){
    num = 0;
    delete [] P;
    P = 0;
}
