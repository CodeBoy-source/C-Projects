#include "Matriz2D.h"
#include <iostream>

/**
 * Almacenamos memoria para un array de tamano a, y luego
 * apuntamos a arrays de tamano b
 * @param a
 * @param b
 */
void Matriz2D::Create(int a, int b){
    row = a;
    column = b;
    array = new int*[a];
    for(int i=0; i < a; i++){
        *(array+i) = new int[b];
        for(int j=0; j < b; j++){
            std::cin >> *(*(array+i)+j);
        }
    }
}

Matriz2D* Matriz2D::Copy(){
    Matriz2D* Copy = new Matriz2D;
    Copy = this->SubMatrix(0,0,row-1,column-1);
    return Copy;
}
/**
 * Anulamos un puntero en la posicion pos y
 * movemos las posiciones posteriores uno arriba.
 * @param pos
 */
void Matriz2D::RemoveRow(int pos){
    if(pos>=0 && pos < row) {
        int util = row - pos;
        for (int i = 0; i < util; i++) {
            *(array + pos + i) = *(array + pos + i+1);
        }
        row--;
        *(array+row) = 0;
    }
}
/**
 * Aplicamos la misma teoria que para remover una fila.
 * @param pos
 */
void Matriz2D::RemoveCol(int pos){
    if(pos>=0 && pos < column){
        int util = column - pos;
        for(int i = 0; i < row; i++){
            for(int j=0; j < util; j++){
                *(*(array+i)+pos+j) =*(*(array+i)+pos+j+1);
            }
        }
        column--;
    }
}
/**
 * Creamos un nuevo objeto de Matriz2D y entonces vamos
 * copiando los valores del valor original segun las posiciones
 * indicadas.
 * @param ini
 * @param col
 * @param end
 * @param colend
 * @return
 */
Matriz2D* Matriz2D::SubMatrix(int ini, int col, int end, int colend){
    Matriz2D* Extra = new Matriz2D;
    if(ini>=0 && col>=0 && end<row && colend<column) {
        Extra->SetRow(end-ini+1);
        Extra->SetCol(colend-col+1);
        int index = 0, cont;
        for (int i = ini; i <= end; i++) {
            cont = 0;
            Extra->SetPointer(new int[colend-col+1],index);
            for (int j = col; j <= colend; j++) {
                Extra->SetValue(*(*(array+i)+j),index,cont);
                cont++;
            }
            index++;
        }
    }
    return Extra;
}
/**
 * Recogemos la matriz dinamica y vamos imprimiendo por pantalla
 * los valores.
 */
void Matriz2D::Show() {
    for(int i = 0; i < row; i++) {
        if (*(array + i)) {
            for (int j = 0; j < column; j++) {
                std::cout << *(*(array + i) + j) << " ";
            }
            std::cout << std::endl;
        }
    }
}
