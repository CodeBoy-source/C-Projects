#ifndef PREPEX_NODE_H
#define PREPEX_NODE_H
#include <iostream>
#include "Punto.h"

class Node{
private:
    Punto point;
    Node* next;
public:
    Node(){
        next = 0;
    }
    Node(Punto vp){
        point = vp;
        next = 0;
    }
    inline void SetPunto(Punto vp){ point = vp;}
    inline void SetNext(Node* sig){ next = sig;}
    inline Node* GetNext() const{ return next;}
    inline Punto GetPunto() const{ return point;}
    friend ostream & operator << (ostream &out, const Node &obj);
    ~Node();
};

#endif //PREPEX_NODE_H
