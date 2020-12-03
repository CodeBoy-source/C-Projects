#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct data {
    string nombre;
    string apellidos;
    int prioridad;

    data(string name, string nick, int num){
        nombre = name;
        apellidos = nick;
        prioridad = num;
    }
    friend ostream& operator <<(ostream& out, const data& obj){
        out << obj.prioridad << endl;
        return out;
    }
};

struct ComparePriority{
    bool operator()(const data& obj, const data& obj2){
        return obj.prioridad < obj2.prioridad;
    }
};

int main(){

    priority_queue<data,vector<data>,ComparePriority> cola;

    for(int i=0;i<10;i++){
        cola.push(data("a","b",i));
    }

    while(!cola.empty()){
        cout << "Elemento: " << cola.top() << endl;
        cola.pop();
    }

}