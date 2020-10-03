#include <iostream>
#include "Rep.h"
#include "Sequence.h"
using namespace std;

int main() {
    cout << "Introduzca el valor: ";
    int value;
    cin >> value;
    Sequence First(value);
    First.Show();
    Sequence Copy(First);
    cout << "Copia realizada con exito.." << endl;
    cout << "Introduzca el valor a agregar: ";
    cin >> value;
    First.AddNum(value);
    First.Show();
    cout << "Introduzca el segundo valor: ";
    cin >> value;
    Sequence Second(value);
    Second.Show();
    cout << "Introduzca el valor a agregar: ";
    cin >> value;
    Second.AddNum(value);
    Second.Show();
    if (Second == First) {
        cout << endl;
        cout << "Hemos comprobado que son el mismo numero" << endl;
        cout << endl;
    }
    if (Second != First) {
        cout << endl;
        cout << "Hemos comprobado que NO son el mismo numero" << endl;
        cout << endl;
    }

    cout << "Valores de la copia: " << endl;
    Copy.Show();
    return 0;
}