#include <stack>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

bool palindromo(string cadena){
    string temp;
    for(int i=0;i<cadena.size();i++){
        if(cadena[i] == ' ')
            continue;
        temp += cadena[i];
    }
    cadena = temp;
    stack<char> pila;
    queue<char> cola;
    bool result = true;
    int j  = cadena.size()-1;
    for(int i=0;i<cadena.size();i++){
        pila.push(cadena[j-i]);
        cola.push(cadena[i]);
        if(toupper(pila.top()) != toupper(cola.front()))
            result = false;
        cola.pop();
        pila.pop();
    }

    return result;
}

int main(){
    int sz_set = 5;
    string test_set[sz_set] = {
            "Obvio",
            "brian",
            "rayar",
            "Sometemos",
            "Amad a la dama"
    };
    bool result = false;
    for(int i=0;i<sz_set;i++){
        result = palindromo(test_set[i]);
        if(result)
            cout << "La expresion: " << test_set[i] << " es un palindromo.." << endl;
        else
            cout << "La expresion: " << test_set[i] << " NO es un palindromo.. " << endl;
    }
}