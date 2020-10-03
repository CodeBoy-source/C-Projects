#ifndef EJERCICIO4_SECUENCE_H
#define EJERCICIO4_SECUENCE_H

class Sequence{
private:
    Rep* sequence;
    int szvec;
    //Métodos auxiliares para calcular las parejas (Basando nuestro código en vectores).
    void Sort(int* vec, int sz);
    int GetFrec(int* vec,int sz,int* frec);
    int Length(int num);
    void Descomponer(int num, int* Number, int sz);
public:
    Sequence(){
        sequence = 0;
        szvec = 0;
    }
    Sequence(int num){
        int sz = Length(num);
        int* Temp = new int[sz];
        Descomponer(num,Temp,sz);
        GetReps(Temp,sz);
        delete [] Temp;
    }
    Sequence(int* vec, int sz){;
        GetReps(vec,sz);
    }
    Sequence(const Sequence& obj){
        szvec = obj.szvec;
        sequence = new Rep[szvec];
        for(int i=0; i<szvec;i++){
            *(sequence+i) = obj.sequence[i];
        }
    }
    inline int GetSize()const{
        return szvec;
    }
    inline Rep GetPos(int pos)const{
        Rep Extra;
        if (pos>=0 && pos<szvec)
            Extra = *(sequence+pos);
        return Extra;
    }

    void AddNum(int num);
    void AddDigit(int num);
    Rep* New_Sec(Rep extra);
    void GetReps(int* vec, int sz);
    bool operator ==(const Sequence& obj);
    bool operator !=(const Sequence& obj);
    void Show();
    ~Sequence(){
        delete [] sequence;
        sequence = 0;
        szvec = 0;
    }
};

#endif //EJERCICIO4_SECUENCE_H
