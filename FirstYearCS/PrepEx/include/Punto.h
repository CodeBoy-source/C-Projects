#ifndef PREPEX_PUNTO_H
#define PREPEX_PUNTO_H
#include <iostream>
using namespace std;
class Punto{
private:
    int x,y;
public:
    Punto(){
        x = 0;
        y = 0;
    }
    Punto(int vx, int vy){
        x = vx;
        y = vy;
    }

    int GetX()const{return x;}
    int GetY()const{return y;}
    void SetX(int vx){ x = vx;}
    void SetY(int vy){ y = vy;}
    friend ostream& operator <<(ostream &out, const Punto &obj);
    Punto operator = (const Punto& obj);
    ~Punto();
};
#endif //PREPEX_PUNTO_H
