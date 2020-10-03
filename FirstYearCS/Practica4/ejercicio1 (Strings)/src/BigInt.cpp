#include "BigInt.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Recogemos el vector de mayor longitud y vamos sumando ambos valores.
 * (En caso de hayamos pasado la longitud del vector de menor tamano sabemos
 * que no hay que preocuparse ya que nuestro metodo retorna 0 al sobrepasar
 * los limites) Luego tenemos que tener en consideracion el acarro.
 * Y en caso que haya un acarreo en la ultima posicion creamos un nuevo vector
 * de tamano sz+1 que apunte al vector anterior. Y a su ultima posicion anadimos
 * el acarreo final (Si ese acarreo resulta ser 10-10=0, ponemos un 1). Luego
 * eliminamos ambos vectores dinamicos y retornamos nuestro elemento.
 * @param Other
 * @return
 */
BigInt BigInt::Add(BigInt Other){
    bool CARRY = false;
    int carry = 0, extra;
    int max = (this->GetSize() > Other.GetSize()) ? this->GetSize() : Other.GetSize();
    int* temp = new int[max+1];

    for(int i=0; i<max;i++){
        temp[i] = this->GetElement(i) + Other.GetElement(i) + carry;
        if(temp[i]>=10){
            temp[i] -= 10;
            carry = 1;
            CARRY = true;
            extra = temp[i];
        }else{
            carry = 0;
            CARRY = false;
        }
    }

    if(CARRY)
        max++;
    if(CARRY) {
        temp[max - 1] = (extra > 0) ? extra : 1;
    }
    BigInt Result(temp,max);
    delete [] temp;
    return Result;
}
/**
 * Destructor que consiste en borrar nuestro puntero
 * y además siempre hay que poner los valores a 0 para
 * evitar comportamientos ambiguos.
 */
BigInt::~BigInt(){
    delete [] Number;
    Number = 0;
    size = 1;
}
/**
 * Constructor de copia que consiste en copiar directamente
 * los valores del vector2 al vector1 para así poder modificarlos
 * independientemente.
 * @param other
 */
BigInt::BigInt(const BigInt& other) {
    size = other.size;
    Number = new int[size];
    for(int i=0;i<size;i++){
        *(Number+i) = other.Number[i];
    }
}
/**
 * Esto es una función auxiliar que emplea el mismo razonamiento que
 * la funcion descomponer y consiste en calcular la longitud necesaria
 * para nuestro vector segun el numero que vayamos a utilizar de manera
 * que no perdemos memoria.
 * @param num
 * @return
 */
void BigInt::Transform(string num){
    Number = new int[size];
    int cont = 0;
    int* temp = 0;
    bool letter = false;
    for(int i=num.size()-1;i>=0;i--){
        Number[cont] = num.at(i) - '0';
        if(Number[cont] < 10)
            cont++;
        else{
            delete [] temp;
            size -= 1;
            temp = new int[size];
            letter = true;
        }
    }
    if(letter) {
        for (int i = size - 1; i >= 0; i--) {
            temp[i] = Number[i];
        }
        delete[] Number;
        Number = new int[size];
        for (int i = size - 1; i >= 0; i--) {
            Number[i] = temp[i];
        }
    }
    delete [] temp;
}
/**
 * Sobrecarga del operador << que consiste en
 * sobreescribir << con los valores que deseamos imprimir por pantalla.
 * @param out
 * @param Obj
 * @return
 */
ostream& operator << (ostream &out, const BigInt &Obj) {
    for(int i=0;i<Obj.size;i++){
        out << Obj.Number[i] << " ";
    }
    out << endl;
    return out;
}

