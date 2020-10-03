#include <iostream>
#include "BigInt.h"
using namespace std;

int main(){
    cout << "Introduzca el primer numero: " << endl;
    long long int num = 0;
    cin >> num;
    BigInt First(num);
    cout << "Aqui tienes una copia del numero: " << endl;
    BigInt Copy(First);
    cout << Copy;
    cout << "Introduzca el segundo numero: " << endl;
    cin >> num;
    BigInt Second(num);
    cout << "El resultado de sumarlos es: " << endl;
    BigInt Result = First.Add(Second);
    cout << Result;
    return 0;
}