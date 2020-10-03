#include <iostream>
#include "Rep.h"
#include "Sequence.h"
using namespace std;

int Sequence::Length(int num){
    int temp = 1;
    while(num>10){
        num = num/10;
        temp++;
    }
    return temp;
}
void Sequence::Descomponer(int num, int* Number, int sz){
    int i;
    for(i=0; i<sz && num>10 ;i++){
        *(Number+i) = num%10;
        num = num/10;
    }
    *(Number+i) = num;
}

void Sequence::AddNum(int num){
    int sz = Length(num);
    int* Temp = new int[sz];
    Descomponer(num,Temp,sz);
    for(int i=0;i<sz;i++){
        AddDigit(Temp[i]);
    }
    delete [] Temp;
}
void Sequence::AddDigit(int num) {
    Rep Extra(num,1); bool add = true;
    for(int i=0;i<szvec;i++){
        if(sequence[i].GetVal() == Extra.GetVal()) { //Operadores Sobrecargados
            sequence[i] += 1;
            add = false;
        }
    }
    if(add){
        sequence = New_Sec(Extra);
    }
}
Rep* Sequence::New_Sec(Rep extra) {
    Rep* Temp = new Rep[szvec+1];
    int cont = 0; bool add = false;
    for(int i=0;i<szvec;i++){
        if(extra < sequence[i] && !add) {
            Temp[cont] = extra;
            cont++;
            add = true;
        }
        Temp[cont] = sequence[i];
        cont++;
    }
    if(!add)
        Temp[cont] = extra;
    szvec += 1;
    delete [] sequence;
    return Temp;
}
void Sequence::Sort(int *vec, int sz) {
    int i,j, change;
    for(i=1; i < sz ;i++){
        change = vec[i];
        for(j = i; j > 0 && change < vec[j-1]; j--)
            vec[j] = vec[j-1];

        vec[j] = change;
    }
}
int Sequence::GetFrec(int *vec, int sz,int* frec) {
    int cont = sz;
    for(int i=0; i<sz-1;i++) {
        if (vec[i] == vec[i+1]){
            frec[vec[i]] += 1;
            cont -= 1;
        }
    }
    return cont;
}

void Sequence::GetReps(int* vec, int sz){
    Sort(vec,sz);
    int Frec[10] = {0};
    szvec = GetFrec(vec,sz,Frec); //One-Hot-Encoding MAX_SIZE = 10
    sequence = new Rep[szvec];
    int cont = 0;
    for(int i=0; i<szvec;i++){
        sequence[i] = Rep(vec[cont], Frec[vec[cont]]+1);
        cont += 1 + Frec[vec[i]];
    }
}
bool Sequence::operator==(const Sequence &obj) {
    bool same = true;
    if(szvec == obj.szvec){
        for(int i=0;i<szvec;i++){
            if(sequence[i]!=obj.sequence[i])
                same = false;
        }
    }else{
        same = false;
    }
    return same;
}
bool Sequence::operator!=(const Sequence &obj) {
    return !(*this == obj);
}
void Sequence::Show() {
    for(int i=0;i<szvec;i++){
        sequence[i].Show();
    }
}
