#include <stack>
#include <iostream>

using namespace std;

template<class T>
void modificar(stack<T> &P, const T& x, const T& y){
    int sz = P.size();
    stack<T> res;
    T a;
    for(int i=0;i<sz;i++){
        a = P.top();
        P.pop();
        if( a == x)
            a = y;
        res.push(a);
    }
    for(int i=0;i<sz;i++) {
        P.push(res.top());
        res.pop();
    }
}

int main(){

    stack<int> pila;
    stack<int> imprimir;
    for(int i=0;i<10;i++){
        if(i%2==0)
            pila.push(2);
        else
            pila.push(i);
        imprimir.push(pila.top());
    }
    int sz = pila.size();
    cout << "Size of the stack is " << sz << endl;

    for(int i=0;i<sz;i++){
        cout << "Elemento: " << imprimir.top() << endl;
        imprimir.pop();
    }

    cout << "Vamos a cambiar el nunmero 2 al 8..." << endl;

    modificar(pila,2,8);
    while(!pila.empty()){
        cout << "Elemento: " << pila.top() << endl;
        pila.pop();
    }

}

