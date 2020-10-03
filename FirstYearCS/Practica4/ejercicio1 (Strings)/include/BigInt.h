#ifndef EJERCICIO3_BIGINT_H
#define EJERCICIO3_BIGINT_H
using namespace std;
#include <iostream>
#include <string>

class BigInt{
private:
    int* Number;
    int size;
public:
    BigInt(){
        size = 1;
        Number = new int[size];
        *(Number) = 0;
    }

    BigInt(string num){
        size = num.size();
        Transform(num);
    }
    BigInt(int* vec, int sz){
        size = sz;
        Number = new int[sz];
        for(int i=0;i<sz;i++){
            Number[i] = vec[i];
        }
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
    void Transform(string num);
    BigInt Add(BigInt Other);
    friend ostream& operator << (ostream &out, const BigInt &Obj);
    ~BigInt();
};

#endif //EJERCICIO3_BIGINT_H
