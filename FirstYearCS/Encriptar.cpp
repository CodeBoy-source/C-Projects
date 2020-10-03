#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void Encript(string& temp){
    bool found;
    cout << "Encriptando: ";
    char alphabet[27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n',
            'o','p','q','r','s','t','u','v','w','x','y','z'};
    int i,j;
    for(i=0;i<temp.size();i++){
        found = false;
        for(j=0; j<27 && !found;j++){
            if(temp.at(i)==alphabet[j])
                found = true;
        }
        j=j-1;
        temp.at(i) = alphabet[(j+4)%27];
    }
}
void Decript(string& temp){
    bool found;
    cout << "Decriptando: ";
    char alphabet[27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n',
            'o','p','q','r','s','t','u','v','w','x','y','z'};
    int i,j;
    for(i=0;i<temp.size();i++){
        found = false;
        for(j=0; j<27 && !found;j++){
            if(temp.at(i)==alphabet[j])
                found = true;
        }
        j=j-1;
        temp.at(i) = alphabet[((j-4)>0 ? j-4:j-4+27)];
    }
}

int main(int argc, char** argv){
    if(argc<4){
        cerr << "Error. Introduzca dos archivos validos." << endl;
        exit(-1);
    }
    fstream input(argv[1], ios::in);
    fstream output(argv[2], ios::out|ios::trunc);
    if( !input || !output){
        cerr << "Error con los archivos introducidos, vuelva a intentar" << endl;
        exit(1);
    }
    string temp;
    while(getline(input,temp,'\n')) {
        Encript(temp);
        output << temp << '\n';
    }
    output.close();
    output.open(argv[2],ios::in);
    fstream decripted(argv[3],ios::out|ios::trunc);
    if(!decripted || !output){
        cerr << "Error decifrando el código." << endl;
        exit(-2);
    }
    while(getline(output,temp,'\n')){
        Decript(temp);
        decripted << temp << '\n';
    }

    input.close();
    output.close();
    decripted.close();

}