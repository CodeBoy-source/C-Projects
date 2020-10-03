#ifndef EJERCICIO3_BIGINT_H
#define EJERCICIO3_BIGINT_H
using namespace std;
#include <iostream>

class BigInt{
private:
    int* Number;
    int size;
    int Length(long long int num); //funcion auxiliar.
public:
    BigInt(){
        size = 1;
        Number = new int[size];
        *(Number) = 0;
    }

    BigInt(long long int num){
        size = Length(num);
        Descomponer(num);
    }

    BigInt(const BigInt& other);

    inline int GetSize() const{
        return size;
    }

    inline int GetElement(int pos) const{
        int temp = 0;
        if(Number)
            temp = *(Number+pos);
        return temp;
    }

    void Descomponer(long long int num);
    long long int GetNum();
    BigInt Add(BigInt Other);
    friend ostream& operator << (ostream &out, const BigInt &Obj) {
        for(int i=0;i<Obj.size;i++){
            out << Obj.Number[i] << " ";
        }
        out << endl;
        return out;
    }
    ~BigInt();
};

#endif //EJERCICIO3_BIGINT_H
