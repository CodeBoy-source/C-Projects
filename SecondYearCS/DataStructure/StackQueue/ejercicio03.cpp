#include <iostream>
#include <stack>

using namespace std;

template<class T>
class cola{
private:
    stack<T> frente;
    stack<T> ultimo;

public:
    cola(){    }
    cola(const T& elem){
        frente.push(elem);
        ultimo.push(elem);
    }

    void push(const T& elem){
        ultimo.push(elem);
        stack<T> temp(ultimo), empty;
        frente= empty;
        for (int i = 0; !temp.empty() ; i++) {
            frente.push(temp.top());
            temp.pop();
        }
    }

    int size(){
        return frente.size();
    }

    T& front(){
      return frente.top();
    }

    T& back(){
        return ultimo.top();
    }

    void pop(){
        frente.pop();
        stack<T> temp = frente, empty;
        ultimo = empty;
        while(!temp.empty()){
            ultimo.push(temp.top());
            temp.pop();
        }
    }

    void swap(cola<T> &otra){
        frente = otra.frente;
        ultimo = otra.ultimo;
    }

    void emplace(const T &elem){
        this->push(elem);
    }

    bool empty(){
        return frente.size() <= 0;
    }
};

int main(){
    cola<int> cafe;

    for(int i=0;i<5;i++){
        cout << "Introducimos el elemento: " << i << endl;
        cafe.push(i);
    }
    for(int i = 0;cafe.size()>0;i++){
        cout << "Primero " <<  cafe.front() << endl;
        cout << "Ultimo " << cafe.back() << endl;
        cafe.pop();
    }
}