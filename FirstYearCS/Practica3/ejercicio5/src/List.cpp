#include "List.h"
#include "Node.h"
#include <iostream>

void List::Create(int sz){
    if(sz>0) {
        double value;
        std::cout << "Introduzca los datos a continuacion: " << std::endl;
        for (int i = 0; i < sz; i++) {
            std::cin >> value;
            this->AddEnd(value);
        }
    }
}
/**
 * Recogemos los punteros de la lista mientras
 * el siguiente puntero no sea nulo y vamos contando
 * con una variable.
 * @return
 */
int List::Length(){
    Node* extra;
    int cont = 1;
    if(this->content){
        extra = this -> content;
        while(extra->Get_Next() != 0){
            cont++;
            extra = extra -> Get_Next();
        }
    }
    return cont;
}
/**
 * Tenemos que apuntar a la posición inicial y hacer que esa apunte
 * al nuevo nodo que hemos creado.
 * @param vdata
 */
void List::AddStart(double vdata){
    Node* extra = new Node;
    extra -> Set_Pointer(this->content);
    this->content = extra;
    extra->Set_Data(vdata);
}
/**
 * Recogemos los punteros de nuestra lista mientras
 * una variable contadora sea menor que pos;
 * @param pos
 * @return
 */
Node* List::Obtain(int pos){
    Node* extra;
    int cont = 0;
    extra = this -> content;
    while(extra -> Get_Next()!= 0 && cont < pos){
        extra = extra -> Get_Next();
        cont++;
    }
    return extra;
}
/**
 * Tenemos que ir recoger los punteros de nuestra lista
 * hasta llegar al ultimo (nullptr) y entonces hacemos que
 * este apunte al nuevo nodo que hemos creado.
 * @param vdata
 */
void List::AddEnd(double vdata){
    Node* extra;
    if(this->content){
        extra = this -> content;
        while(extra -> Get_Next() != 0){
            extra = extra -> Get_Next();
        }
        extra -> Set_Pointer(new Node);
        extra = extra -> Get_Next();
    }else{
        this -> content = new Node;
        extra = this -> content;
    }
    extra -> Set_Data(vdata);
    extra -> Set_Pointer(0);
}
/**
 * La misma teoria que los ejercicios anteriores.
 * Recogemos los punteros mientras utilizamos una
 * variable contadora para ubicarnos.
 * Luego nuestro nuevo nodo tiene que apuntar a donde apunta
 * el nodo de la posición indicada y solo entonces podemos cambiar
 * para que ese puntero apunte al nuevo nodo que hemos creado.
 * @param vdata
 * @param pos
 */
void List::AddPos(double vdata, int pos){
    if(pos>=0 && pos<=Length()){
    Node* extra;
    Node* Nuevo = new Node;
    extra = Obtain(pos);
    Nuevo -> Set_Pointer(extra->Get_Next());
    extra -> Set_Pointer(Nuevo);
    Nuevo -> Set_Data(extra->Get_Data());
    extra->Set_Data(vdata);
    }else{
        AddEnd(vdata);
    }
}
/**
 * Recogemos los punteros de nuestra lista x2 para cortar
 * en el penúltimo y entonces anulamos su valor.
 */
void List::RemEnd(){
    Node* extra;
    if(this->content->Get_Next()){
        extra = this->content;
        while(extra->Get_Next()->Get_Next()!=0){
            extra=extra->Get_Next();
        }
        delete extra->Get_Next();
        extra -> Set_Pointer(0);
    }
    else{
        content = 0;
    }
}
/**
 * Basicamente podemos utilizar de forma recursiva nuestra
 * función RemEnd(); que borra la ultima posición.
 */
void List::Release(){
    while(this->content){
        RemEnd();
    }
}/**
 * Mientras el puntero no sea nulo, imprimimos los valores,
 * luego apuntamos al siguiente nodo y volvemos a llamar la función
 */
void List::Show(){
    Node* extra;
    extra = this -> content;
    while(extra!=0){
        extra->Show();
        extra=extra->Get_Next();
        std::cout << " -> ";
    }
        std::cout << "NULL";
        std::cout << std::endl;
}