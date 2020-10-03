#include <iostream>
#include <fstream>
#include <string>
#include "cliente.h"
#include "clientes.h"
#include "venta.h"
#include "ventas.h"
using namespace std;

int main(int argc, char** argv){
    if(argc<2){
        cerr << "Error, numero invalido de ficheros a comparar" << endl;
        exit(1);
    }
    string* Nombres = new string[argc]; //Vector para almacenar los nombres.
    int* VentasMedias = new int[argc]; //Vector para almacenar la venta media.
    bool Best = true, Done = false, Error = false;
    int i = 1,j = 2;
    Ventas Va, Vb;
    //Inicializamos los vectores.
    for(int x=0;x<argc;x++){
        Nombres[x] = argv[x];
        Va.LeerVentas(argv[x]);
        VentasMedias[x] = Va.GetVentaMedia();
    }
    //Aplicación:
    //1)Obtenemos todos los nombres de fichero con mismo valor de venta medio.
    for(int i=1; i<argc;i++){
        Va.LeerVentas(argv[i]);
        for(int j=1;j<argc;j++){
            Vb.LeerVentas(argv[j]);
            if(Va == Vb && i!=j)
                Nombres[i-1] += " = " argv[j];
        }
    }
    //2)Buscamos aquel que tenga mayor valor de venta medio
    while(!Done && i<argc && !Error){
        Best = true;
        Va.LeerVentas(argv[i]);
        if(!Va)
            Error = true;
        while(Best && j<argc && !Error){
            Vb.LeerVentas(argv[j]);
            if(Vb){
                Best = Va > Vb;
                j++;
            }else {
                Error = true;
            }

        }
        if(Best){
            i++;
            Va.LeerVentas(argv[i]);
        }
        j=i+1;
    }
    //Imprimimos por pantalla el resultado.
    cout << "Mejor cantidad de venta media: " << Nombres[i-1] << " con un media de "
        << VentasMedias[i-1] << " unidades." << endl;
}

