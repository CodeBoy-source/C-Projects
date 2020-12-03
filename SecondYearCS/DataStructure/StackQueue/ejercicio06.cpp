#include <stack>
#include <iostream>
using namespace std;

template<class T>
void insertar(stack<T> &P, int pos, const T& x){
    if(pos >= 0 && pos < P.size()) {
        stack <T> temp;
        if(pos>0)
            pos-=1;
        int sz = P.size();
        for (int i = 0; i < sz; i++) {
            temp.push(P.top());
            P.pop();
        }
        for (int i = 0; i < sz; i++) {
            if (i == pos)
                P.push(x);
            P.push(temp.top());
            temp.pop();
        }
    }
}

int main(){
    stack<int> pila;
    int sz = 5;
    for(int i=0;i<sz;i++){
        cout << "Introducimos el elemento: " << i << endl;
        pila.push(i);
    }

    int pos = 2, num = 69;
    cout << "Vamos a insertar en la posicion: " << pos << " El numero " << num << endl;

    insertar(pila,pos,num);

    for(int i=0;pila.size()>0;i++){
        cout << "Elemento: " << pila.top() << endl;
        pila.pop();
    }
}