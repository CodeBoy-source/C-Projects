#include <stack>
#include <iostream>
using namespace std;

template<class T>
class ventana{
private:
    stack<T> data;
    stack<T> edits;

public:
    ventana(){}

    ventana(const T& elem){
        data.push(elem);
    }

    void insertar(const T& elem){
        data.push(elem);
    }

    void mover_derecha(){
        if(!this->fin()){
            stack<T> temp;
            while(!edits.empty()){
                temp.push(edits.top());
                edits.pop();
            }
            data.push(temp.top());
            temp.pop();
            while(!temp.empty()){
                edits.push(temp.top());
                temp.pop();
            }
        }else {
            cout << "#########################################" << endl;
            cout << "Error: ya estamos al final de la ventana " << endl;
            cout << *this << endl;
            cout << "#########################################" << endl;

        }
    }

    void mover_izquierda(){
        if(!this->inicio()){
            stack<T> temp;
            while(!edits.empty()) {
                temp.push(edits.top());
                edits.pop();
            }
            edits.push(data.top());
            data.pop();
            while(!temp.empty()){
                edits.push(temp.top());
                temp.pop();
            }
        }else {
            cout << "#########################################" << endl;
            cout << "Error: ya estamos al inicio de la ventana " << endl;
            cout << *this << endl;
            cout << "#########################################" << endl;
        }
    }

    bool inicio() const {
        return data.empty();
    }

    bool fin() const {
        return edits.empty();
    }

    T devolver_elemento() const{
        if(!data.empty()){
            return data.top();
        }
    }

    void borrar_elemento(){
        if(!data.empty()){
            data.pop();
        }
    }

    friend ostream& operator<<(ostream& out, ventana& obj){
        out << "Lado Izquierdo: ";
        stack<T> print, print2, temp, temp2;
        print = obj.data; print2 = obj.edits;
        while(!print.empty()){
            temp.push(print.top());
            print.pop();
        }
        while(!print2.empty()){
            temp2.push(print2.top());
            print2.pop();
        }
        while(!temp.empty()){
            out << temp.top() << " ";
            temp.pop();
        }
        out  << " _ " << endl;
        out << "Lado Derecho: ";
        while(!temp2.empty()){
            out << temp2.top() << " ";
            temp2.pop();
        }
        return out;
    }
};

int main(){

    ventana<int> window;

    for(int i=0;i<10;i++){
        window.insertar(i);
    }
    cout << window << endl;

    int pos = 5;
    cout << "Ahora vamos a movernos " << pos << " a la izquierda..." << endl;

    for(int i=0;i<pos;i++){
        window.mover_izquierda();
    }

    cout << window << endl;

    cout << "Ahora voy a insertar un valor donde estamos " << endl;
    window.insertar(69);
    cout << window << endl;

    cout << "Ahora voy a borrar ese numero" << endl;
    window.borrar_elemento();
    cout << window << endl;

    cout << "Ahora quiero saber que elemento tengo " << endl;
    cout << window.devolver_elemento() << endl;

    cout << window << endl;

    pos = 3;
    cout << "Ahora vamos a movernos " << pos << " a la derecha..." << endl;

    for(int i=0;i<pos;i++){
        window.mover_derecha();
    }

    cout << window << endl;

    cout << "Ahora probamos salirnos de la ventana..." << endl;

    pos=12;
    for(int i=0;i<pos;i++){
        window.mover_izquierda();
    }
    for(int i=0;i<pos;i++){
        window.mover_derecha();
    }
}