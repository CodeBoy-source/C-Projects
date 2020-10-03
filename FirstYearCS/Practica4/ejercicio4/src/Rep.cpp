#include <iostream>
#include "Rep.h"
using namespace std;

bool Rep::operator==(const Rep &obj) {
    return(value==obj.value && times==obj.times);
}
bool Rep::operator!=(const Rep &obj) {
    return !(*this==obj);
}
void Rep::operator+=(const int& num) {
    times += num;
}
bool Rep::operator<(const Rep &obj) {
    return (value<obj.value);
}
void Rep::Show() {
    cout << "El numero: " << value << " ha aparecido " << times << " veces" << endl;
}

