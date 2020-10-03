#ifndef EJERCICIO6_MATRIZ2D_H
#define EJERCICIO6_MATRIZ2D_H

class Matriz2D{
private:
    int** array;
    int row;
    int column;
public:
    Matriz2D(){
        row = 0;
        column = 0;
        array = 0;
    }
    void Create(int a, int b);
    void SetRow(int vrow){
        if(row==0)
            array = new int*[vrow];
        row = vrow;
    }
    void SetCol(int vcol){
        column = vcol;
    }
    /**
     * acceder directamente al valor de la una fila,columna
     * y cambiamos el valor.
     * @param value
     * @param vrow
     * @param vcol
     */
    void SetValue(int value, int vrow, int vcol){
        if(vrow>=0 && vrow<row && vcol>=0 && vcol<column)
            *(*(array+vrow)+vcol) = value;
    }
    int GetRow(){return row;}
    int GetCol(){return column;}
    int* GetPointer(int pos){
        if(pos>=0&&pos<row)
            return *(array+pos);
        else
            return 0;
    }
    int** GetPointers(){
        return array;
    }
    void SetPointer(int* extra,int pos){
        if(pos>=0&&pos<row)
            *(array+pos) = extra;
    }
    void SetPointers(int** update){
        array = update;
    }
    Matriz2D* Copy();
    Matriz2D* SubMatrix(int ini, int col, int end, int colend);
    void RemoveRow(int pos);
    void RemoveCol(int pos);
    void Show();
};

#endif //EJERCICIO6_MATRIZ2D_H
