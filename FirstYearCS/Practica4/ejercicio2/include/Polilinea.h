#ifndef EJERCICIO2_POLILINEA_H
#define EJERCICIO2_POLILINEA_H

class Polilinea{
private:
    Punto* P;
    int num;

public:
    Polilinea(){
        P = 0;
        num = 0;
    }
    Polilinea(const Polilinea& other);
    void Create(int size);

    inline int GetSize() const{
        return num;
    }
    inline Punto GetPunto(int pos)const{
        Punto A;
        if (pos>=0 && pos<num)
            A = *(P+pos);
        return A;
    }

    Punto* Copy(int until);
    void AgregarPunto(Punto A);
    void Organize();
    Polilinea operator +(Polilinea const &obj);
    void DelDuplicates();
    void Remove(int pos);
    void Show();
    ~Polilinea();
};

#endif //EJERCICIO2_POLILINEA_H
