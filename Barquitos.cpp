#include <iostream>
using namespace std;

class Barquitos{
private:
    int** tablero;
    int filas;
    int columnas;

    //Estos son metodos auxiliar para facilitar la insercion del barco
    bool AddHorizontal(int vx, int vy, int size);
    bool AddVertical(int vx, int vy, int size);
public:
    Barquitos(){
        tablero = 0;
        filas = 0;
        columnas = 0;
    }
    //Constructor por parametros con valor 9 por defecto
    Barquitos(int vx, int vy);
    //Aqui tenemos algunas funciones esenciales.
    inline const int GetFilas();
    inline const int GetCol();
    inline const int GetPos(int vx,int vy);

    //Aqui empiezan las funciones que valen nota xD
    void Shoot(int vx, int vy);
    bool AddBoat(int vx, int vy, int size, char axis);
    void Show();
    ~Barquitos();
};
Barquitos::Barquitos(int vx, int vy){
    this->filas = vy;
    this->columnas = vx;
    tablero = new int*[vy];
    for(int i=0;i<vy;i++){
        *(tablero+i) = new int[vx];
        for(int j=0;j<vx;j++){
            *(*(tablero+i)+j) = 9;
        }
    }
}
inline const int Barquitos::GetFilas(){
    return filas;
}
inline const int Barquitos::GetCol(){
    return columnas;
}
inline const int GetPos(int vx,int vy){
    int a = 0;
    if(vx>=0 && vy>=0 && vy<filas && vx<columnas){
        a = tablero[vy][vx];
    }
    return a;
}
void Barquitos::Shoot(int vx, int vy){
    tablero[vy][vx] = -tablero[vy][vx]; //Bastante sencilla.
}
/**
     * Aqui tenemos un valor axis que permuta entre las dos funciones que hemos
     * creado de manera que así nos podemos centrar en problemas más pequenos.
     * Utilizamos toupper para poder igualar 'h' a 'H' o 'v' a 'V' (basicamente,
     * pone el char a mayuscula). Empezamos suponiendo que podemos añadir algo
     * y luego comprobamos si es verdad.
     * @param vx
     * @param vy
     * @param size
     * @param axis
     * @return
     */
bool Barquitos::AddBoat(int vx, int vy, int size, char axis){
    bool result = true;
    if(toupper(axis) == 'H'){
        result = AddHorizontal(vx,vy,size);
    }else{
        result = AddVertical(vx,vy,size);
    }
    return result;
}
void Barquitos::Show(){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
/**
 * Como sabemos que avanza horizontalmente solamente tenemos que
 * verificar que (Ademas que vx, vy >= 0) vx+size < columnas. En
 * caso verdadero podemos ir cambiando los valores a size.
 * Y retornaremos verdadero si se ha podido y falso si no.
 * @param vx
 * @param vy
 * @param size
 * @return
 */
bool Barquitos::AddHorizontal(int vx, int vy, int size) {
    bool result = true;
    if(vx>=0 && vy>=0 && vx+size<columnas && vy<filas) {
        for (int j = vx; j < vx + size; j++) {
            if (tablero[vy][j] != 9) {
                result = false;
            }
        }
        if (result) {
            for (int j = vx; j < vx + size; j++) {
                tablero[vy][j] = size;
            }
        }
    }
    return result;
}
/**
 * Haremos lo mismo que hemos hecho en el AddHorizontal pero
 * ahora con enfasis en el eje y, o mejor dicho, vy+size < filas;
 * @param vx
 * @param vy
 * @param size
 * @return
 */
bool Barquitos::AddVertical(int vx, int vy, int size) {
    bool result = true;
    if(vx>=0 && vy>=0 && vx<columnas && vy+size<filas) {
        for (int j = vy; j < vy + size; j++){
            if(tablero[j][vx]!=9){
                result = false;
            }
        }
        if(result){
            for (int j = vy; j < vy + size; j++) {
                tablero[j][vx] = size;
            }
        }
    }
    return result;
}
/**
* Recogemos las filas de la matriz y vamos borrando
* luego ponemos los valores a 0;
*/
Barquitos::~Barquitos(){
    for(int i=0;i<filas;i++){
        delete [] *(tablero+i);
    }
    delete [] tablero;
    tablero = 0;
    filas = 0;
    columnas = 0;
}

int main(){
    Barquitos Brian(10,10);
    Brian.AddBoat(0,0,3,'H');
    Brian.AddBoat(0,5,3,'V');
    Brian.Shoot(0,5);
    Brian.Show();
}