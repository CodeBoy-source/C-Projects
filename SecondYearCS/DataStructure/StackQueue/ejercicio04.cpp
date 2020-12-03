#include <queue>
#include <iostream>
using namespace std;

template<class T>
class pila{
private:
    queue<T> cola;
    queue<T> reversed;

public:
    pila(){}
    pila(const T& elem){
        cola.push(elem);
        reversed.push(elem);
    }

    void push(const T& elem){
        reversed.push(elem);
        queue<T> res;
        for(int i=0;i<reversed.size();i++){
            queue<T> temp = reversed;
            for(int j=reversed.size()-1; j > i; j--){
                temp.pop();
            }
            res.push(temp.front());
        }
        cola = res;

    }

    int size(){
        return cola.size();
    }

    T& top(){
        return cola.front();
    }

    void pop(){
        cola.pop();
        queue<T> temp = cola, empty;
        reversed = empty;
        while(!temp.empty()){
            reversed.push(temp.front());
            temp.pop();
        }
    }

    bool empty(){
        return cola.size() <= 0;
    }

};

int main(){
    pila<int> pil;

    for(int i=0;i<5;i++){
        cout << "Introducimos el elemento: " << i << endl;
        pil.push(i);
    }

    while(!pil.empty()){
        cout << "Tope de la pila: " << pil.top() << endl;
        pil.pop();
    }
}