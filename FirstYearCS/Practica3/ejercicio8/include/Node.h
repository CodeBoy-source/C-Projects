#ifndef EJERCICIO458_NODE_H
#define EJERCICIO458_NODE_H

class Node{
private:
    double data;
    Node* next;

public:
    Node(){
        data = 0;
        next = 0;
    }
    void Set(double a, Node B){
        data = a;
        next = &B;
    }
    void Set_Pointer(Node* B){
        next = B;
    }
    void Set_Data(double vdata){
        data = vdata;
    }
    double Get_Data(){
        return data;
    }
    Node* Get_Next(){
        return next;
    }
    void Show();
};

#endif //EJERCICIO458_NODE_H
