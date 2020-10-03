#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Punto.h"
#include "Node.h"
#include "List.h"
#include "Utilities.h"

using namespace std;

int Divide(int K, List obj, List* Segments){
    int maxLen = obj.GetLen();
    int size = int(maxLen/K);
    int cont = 0;
    for(int i=0; i<=size && cont<maxLen; i++){
        List B;
        for(int j=0; j<K && cont+j<maxLen; j++) {
            B.AddEnd(obj.GetPos(cont+j)->GetPunto());
        }
        Segments[i] = B;
        cont += K;
    }
    return size;
}
List Do(int action, List Menu){
    switch(action){
        case 1: {
            string x = " ";
            while (x.at(0) != 'q') {
                Punto vp;
                cout << "\e[AInsert 'q' to stop(x, y): ";
                cin >> x;
                if (x.at(0) != 'q') {
                    vp.SetX(stoi(x));
                    cin >> x;
                    if(x.at(0) != 'q') {
                        vp.SetY(stoi(x));
                        Menu.AddEnd(vp);
                    }
                }
            }
            break;
        }
        case 2:
        {
            char x = ' ';
            while(x!='q'){
                cout << "\e[AInsert the position to remove ('q' to stop): ";
                cin >> x;
                if(x != 'q')
                    Menu.RemPos(x-'0');
            }
        }
        case 3: {
            cout << Menu;
            break;
        }
        case 6:{
            string output;
            output += "\n";
            int size = Menu.GetLen();
            for(int i=0; i<size;i++){
                output += to_string(Menu.GetPos(i)->GetPunto().GetX());
                output += " ";
                output += to_string(Menu.GetPos(i)->GetPunto().GetY());
                if(i!=size-1)
                    output += " -> ";
            }
            cout << output << endl;
            ofstream myfile;
            myfile.open("Points.dat",ios::app);
            if(!myfile.fail())
                myfile << output;
            myfile.close();
            break;
        }
        case 7:{

        }
        case 8:{
            break;
        }
    }
}