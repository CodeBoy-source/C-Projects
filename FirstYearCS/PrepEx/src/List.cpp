#include "List.h"
#include "Node.h"
#include "Punto.h"
#include <iostream>
using namespace std;

void List::AddStart(Punto vp){
    Node* Extra = new Node;
    Extra->SetNext(this->content);
    this->content = Extra;
    Extra->SetPunto(vp);
}
void List::AddEnd(Punto vp){
    Node* extra;
    if(this->content){
        extra = this->content;
        while(extra->GetNext() != 0)
            extra = extra->GetNext();
        extra->SetNext(new Node);
        extra = extra ->GetNext();
    }else{
        this->content = new Node;
        extra = this->content;
    }
    extra->SetPunto(vp);
}

int List::GetLen(){
   Node* temp = this->content;
   int cont = 0;
   while(temp != 0){
       cont++;
       temp = temp->GetNext();
   }
   return cont;
}

void List::RemPos(int pos){
    Node* temp = this->content;
    if(pos==0){
        temp = temp->GetNext();
        this->content = temp;
    }else if(pos>0){
        int cont = 1;
        while(temp->GetNext()!=0 && cont<pos){
            temp = temp->GetNext();
            cont++;
        }
        if(temp->GetNext()!=0){
            if(temp->GetNext()->GetNext()!=0)
                temp->SetNext(temp->GetNext()->GetNext());
            else
                temp->SetNext(0);
        }else{
            temp->SetNext(0);
        }
    }
}
Node* List::GetPos(int pos){
    Node* temp = this->content;
    if(temp && pos>=0){
        int cont = 0;
        while(temp != 0 && cont<pos){
            temp = temp->GetNext();
            cont++;
        }
    }
    return temp;
}

ostream& operator << (ostream &out, const List &obj){
    Node* temp = obj.content;
    if(temp) {
        while (temp != 0) {
            out << *temp;
            temp = temp->GetNext();
            if (temp != 0)
                out << " -> ";
        }
    }
    out << endl;
    return out;
}