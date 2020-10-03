#include <iostream>
#include "Node.h"
#include "Punto.h"
using namespace std;

ostream & operator <<(ostream &out, const Node &obj){
    out << obj.point;
    return out;
}

Node::~Node(){
    next = 0;
}