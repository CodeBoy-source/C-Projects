#include <iostream>
#include "utilidades.h"
#include "Matriz2D.h"

int main(){
    Matriz2D Brian;
    int vrow, vcol;
    std::cout << "Numero de filas de la Matriz: ";
    std::cin >> vrow;
    std::cout << "Numero de columnas de la Matriz: ";
    std::cin >> vcol;
    std::cout << "Introduzca los valores: ";
    Brian.Create(vrow,vcol);
    std::cout << "Vamos a hacer una copia " << std::endl;
    Matriz2D* Copy = Brian.Copy();
    std::cout << "Copia realizada" << std::endl;
    std::cout << "Dime los extremos para extraer la sub-matriz (x1,y1,x2,y2): ";
    int x2,y2;
    std::cin >> vrow >> vcol >> x2 >> y2;
    while(vrow<0 || x2<0 || y2<0 || vcol<0 ||
            vrow>Brian.GetRow() || vcol>Brian.GetCol()
            || x2>Brian.GetRow() || y2>Brian.GetCol()){
        std::cout << "Invalid arguments, try again: " << std::endl;
        std::cin >> vrow >> vcol >> x2 >> y2;
    }
    OrdenarPos(&vrow,&x2);
    OrdenarPos(&vcol, &y2);
    Matriz2D* SubMatriz = Brian.SubMatrix(vrow,vcol,x2,y2);
    SubMatriz->Show();
    std::cout << "Que fila quieres borrar? ";
    std::cin >> vrow;
    Brian.RemoveRow(--vrow);
    Brian.Show();
    std::cout << "Que columna quieres borrar? ";
    std::cin >> vcol;
    Brian.RemoveCol(--vcol);
    Brian.Show();
    std::cout << "Y aqui tienes la copia: " << std::endl;
    Copy->Show();
}