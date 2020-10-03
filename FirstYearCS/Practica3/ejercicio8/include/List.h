#ifndef EJERCICIO458_LIST_H
#define EJERCICIO458_LIST_H
#include "Node.h"

class List {
private:
    Node *content;
public:
    List() {
        content = nullptr;
    }
    void Create(int sz);
    int Length();
    void AddStart(double vdata);
    Node* Obtain(int pos);
    void AddEnd(double vdata);
    void AddPos(double vdata, int pos);
    void RemEnd();
    void Release();
    void Show();
    void RevShow();
};

#endif //EJERCICIO458_LIST_H
