#ifndef EJERCICIO2_PUNTO_H
#define EJERCICIO2_PUNTO_H

class Punto{
private:
    double x,y;
public:
    Punto(){
        x=0;
        y=0;
    }
    Punto(double vx,double vy){
        x=vx;
        y=vy;
    }
    inline double GetX() const{
        return x;
    }
    inline double GetY() const{
        return y;
    }
    inline void SetX(double vx){
        x = vx;
    }
    inline void SetY(double vy){
        y = vy;
    }
    bool operator ==(Punto const &obj);
    void Show();
};

#endif //EJERCICIO2_PUNTO_H
