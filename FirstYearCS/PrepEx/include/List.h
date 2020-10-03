#ifndef PREPEX_LIST_H
#define PREPEX_LIST_H
#include <iostream>
#include "Punto.h"
#include "Node.h"
using namespace std;
class List{
private:
    Node* content;
public:
    List(){
        content = 0;
    }

    void AddStart(Punto vp);
    void AddEnd(Punto vp);
    int GetLen();
    Node* GetPos(int pos);
    void RemPos(int pos);
    void Clear();
    friend ostream & operator << (ostream &out, const List &obj);
};
#endif //PREPEX_LIST_H
