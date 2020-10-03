#ifndef EJERCICIO4_REP_H
#define EJERCICIO4_REP_H

class Rep{
private:
    int value;
    int times;
public:
    Rep(){
        value=0;
        times=0;
    }
    Rep(int val, int vx){
        value = val;
        times = vx;
    }
    inline void SetVal(int val){
        value = val;
    }
    inline void SetReps(int vx){
        times = vx;
    }
    inline int GetVal() const{
        return value;
    }
    inline int GetRep()const{
        return times;
    }
    bool operator ==(const Rep& obj);
    bool operator !=(const Rep& obj);
    void operator +=(const int& num);
    bool operator <(const Rep& obj);
    void Show();
};

#endif //EJERCICIO4_REP_H
