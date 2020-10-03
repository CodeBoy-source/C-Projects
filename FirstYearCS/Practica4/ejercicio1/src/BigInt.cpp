#include "BigInt.h"
#include <iostream>
using namespace std;

/**
 * Retornamos la suma de ambos valores una vez
 * que hayamos pasado de vector a Long long int otra
 * vez con el auxilio de otra funcion (GetNum)
 * @param Other
 * @return
 */
BigInt BigInt::Add(BigInt Other){
    return BigInt(this->GetNum()+Other.GetNum());
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
 * Para meter cada digito en una posición diferente del vector
 * es necesario que podamos calcular cada digito que compone el numero
 * para ello empleamos el numero 10 y sus potencias, ya que por ejemplo
 * 12%10 = 2 and 12/10 = 1 (int). Con este razonamiento desarrollamos la
 * funcion:
 * @param num
 */
void BigInt::Descomponer(long long int num){
    Number = new int[size];
    int i;
    for(i=size-1;i>0 && num>10 ;i--){
        *(Number+i) = num%10;
        num = num/10;
    }
    *(Number+i) = num;
}
/**
 * Esto es una función auxiliar que emplea el mismo razonamiento que
 * la funcion descomponer y consiste en calcular la longitud necesaria
 * para nuestro vector segun el numero que vayamos a utilizar de manera
 * que no perdemos memoria.
 * @param num
 * @return
 */
int BigInt::Length(long long int num){
    int temp = 1;
    while(num>10){
        num = num/10;
        temp++;
    }
    return temp;
}
/**
 * Consiste del proceso inverso de descomponer y lo utilizamos para
 * no tener que lidiar con el acarreo que podría generar sumar las posiciones
 * de los vectores una a una.
 * @return
 */
long long int BigInt::GetNum(){
    long long int num = 0;
    long long int cont = 1;
    for(int i=size-1;i>=0;i--){
        num += (*(Number+i))*(cont);
        cont *= 10;
    }
    return num;
}

