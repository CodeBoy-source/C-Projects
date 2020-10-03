#include <iostream>
#include "utilidades.h"

using namespace std;

int main()
{
    const int TAM=100;
    double v1[TAM], v2[TAM], v3[TAM], x;
    int util1=0, util2=0, usados;

    //Lectura del primer vector//

    cout << "Introduzca el primer vector, numero negativo para acabar" << endl;
    cin >> x;
    while(x>=0){
        v1[util1]=x;
        util1++;
        cin >> x;
    }

    //Lectura del segundo vector//

    cout << "Introduzca el segundo vector, numero negativo para acabar" << endl;
    cin >> x;
    while(x>=0){
        v2[util2]=x;
        util2++;
        cin >> x;
    }

    cout << endl;

    //LLamada a la función mezclar y guardamos el resultado en la variable usados//

    usados=mezclar(v1, v2, v3, util1, util2);

    for(int i=0; i<usados; i++){
        cout << v3[i] << " ";
    }

    return 0;
}