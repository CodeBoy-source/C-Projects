#include <queue>
#include <iostream>
using namespace std;

template<class T>
void insertar(queue<T> &P, int pos, const T& x){
    queue<T> temp;
    if(pos>0)
        pos-=1; //Para empezar a contar de 0;
    int sz = P.size();
    for(int i=0;i<sz;i++){
        if(i == pos)
            temp.push(x);
        temp.push(P.front());
        P.pop();
    }
    P = temp;
}

int main(){
    queue<int> cola;
    int sz = 5;
    for(int i=0;i<sz;i++){
        cout << "Introducimos el elemento: " << i << endl;
        cola.push(i);
    }

    int pos = 1, num = 69;
    cout << "Introducimos en la pos: " << pos << " el Elemento: " << num << endl;

    insertar(cola, pos, num);

    for(int i=0;i<sz+1;i++){
        cout << "Elemento: " << cola.front() << endl;
        cola.pop();
    }
}