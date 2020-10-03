#include "cliente.h"
#include "clientes.h"
#include <iostream>
#include <fstream>
using namespace std;

/*********************************************************/
//Constructor de copia.
Clientes::Clientes(const Cliente &obj){
    num_clientes = obj.num_clientes;
    los_clientes = new Cliente[num_clientes];
    for(int i=0; i<num_clientes;i++){
        *(los_clientes+i) = obj.los_clientes[i];
    }

}

/*********************************************************/
//Constructor por Fichero
Clientes::Clientes(const string filename){
    ifstream input(filename);
    if(input.fail()){
        cerr << "Error, no pudimos abrir el archivo!" << endl;
        exit(-1);
    }
    string temp;
    int size = 0;
    while(getline(input, temp, '\n'))
        size++;

    num_clientes = size-1;//Quitamos el titulo;
    los_clientes = new Clientes[num_clientes];
    input.seekg(0,ios::beg) //Volvemos al principio del archivo;
    getline(input,temp,'\n');//Ignoramos la primera linea (titulo);
    Cliente extra;
    while(!input.eof()) {
        input >> extra; //ifstream inherits from istream operator >>;
        los_clientes += extra;
    }
    input.close();
}

/*********************************************************/
//Escribir a un fichero dado
void EscribirClientes (const string nombre) const{
    ofstream output(nombre); //ios::app si queremos aniadir a un fichero con datos.
    if(output.fail()){
        cerr << "Error, no pudimos crear/abrir el archivo dado" << endl;
        exit(1);
    }
    output << "FICHEROCLIENTES \n"; //Implementamos el titulo del archivo.
    for(int i=0; i<num_clientes;i++){
        output << los_clientes[i] << '\n'; //ofstream inherits from ostream operator >>;
    }
    output.close();
}

/*********************************************************/
//operador asignacion =
void Clientes::operator =(const Clientes &obj){
    this->num_clientes = obj.num_clientes;
    this->los_clientes = new Clientes[num_clientes];
    for(int i=0; i<num_clientes;i++){
        this->los_clientes[i] = obj.los_clientes[i];
    }
}

/*********************************************************/
//operador +=
void CLientes::operator +=(const Cliente &obj){
    bool found = false;
    for(int i=0;i<num_clientes;i++){
        if(los_clientes[i] == obj) //Hemos sobrecargado el operador == cliente.
            found = true;
    }
    if(!found){
        obj.SetIdCliente(this->GeneraIdCliente());
        Cliente* temp = new Cliente[num_clientes+1];
        for(int i=0; i<num_clientes;i++){
            temp[i] = los_clientes[i];
        }
        temp[num_clientes] = obj;
        delete [] los_clientes; //Liberar memoria siempre que abrimos;
        num_clientes++;
        los_clientes = new Cliente[num_clientes];
        for(int i=0; i<num_clientes;i++){
            los_clientes[i] = temp[i];
        }
        delete [] temp; //Liberar memoria siempre que abrimos.
    }
}

/*********************************************************/
//operador +
Clientes* Clientes::operator +(const Clientes &obj){
    Clientes* result;
    for(int i=0; i<num_clientes;i++){
        result += los_clientes[i];
    } //Anadimos los objectos de la clase implicita;
    for(int i=0;i<obj.num_clientes;i++){
        result += obj.los_clientes[i];
    }
    return result;
}

/*********************************************************/
//Operadores de flujo de texto
ostream& operator << (ostream &out, const Clientes &clientes){
    //Hemos sobrecargado el operator << cliente
    for(int i=0; i<clientes.num_clientes;i++){
        out << clientes.los_clientes[i] << endl;
    }
    return out;
}

/*********************************************************/
istream& operator>>(istream &in, Clientes &clientes){
    //Hemos sobrecargado el operator >> cliente
    for(int i=0; i<clientes.num_clientes;i++){
        in >> clientes.los_clientes[i];
    }
    return in;
}

