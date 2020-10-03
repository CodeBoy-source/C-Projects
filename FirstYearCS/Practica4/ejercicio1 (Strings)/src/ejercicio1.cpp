#include <iostream>
#include "BigInt.h"
#include <string>
using namespace std;

int main(){
    cout << "Introduzca el primer numero: " << endl;
    string num;
    cin >> num;
    BigInt First(num);
    cout << First;
    cout << "Introduzca el segundo numero: " << endl;
    cin >> num;
    BigInt Copy(First);
    BigInt Second(num);
    cout << "El resultado de sumarlos es: " << endl;
    BigInt Result = First.Add(Second);
    cout << Result;
    return 0;
}