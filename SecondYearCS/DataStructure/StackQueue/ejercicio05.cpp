#include <stack>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

template<class T>
float evalua(string expresion, pair<char, T> *variables, int num_variables) {
    stack<T> temp;
    char oper; T a = 0, b = 0; bool popped;
    for(int i=0;i<expresion.size();i++) {
        temp.push(expresion[i]);
        if (toupper(temp.top()) < 65 || toupper(temp.top()) > 90) {
            oper = temp.top();
            temp.pop();
            do {
                for (int i = 0; i < 2; i++) {
                    popped = false;
                    for (int i = 0; i < num_variables && !temp.empty(); i++) {
                        if (temp.top() == variables[i].first) {
                            temp.pop();
                            popped = true;
                            if (b == 0)
                                b = variables[i].second;
                            else
                                a = variables[i].second;
                        }
                    }
                    if( a == 0 && !temp.empty() && !popped) {
                        a = temp.top();
                        temp.pop();
                    }
                    else if( b == 0 && !temp.empty() && !popped){
                        b = temp.top();
                        temp.pop();
                    }
                }
                switch (oper) {
                    case '+':
                        a = a + b;
                        break;
                    case '-':
                        a = a - b;
                        break;
                    case '*':
                        a = a * b;
                        break;
                    case '/':
                        a = a / b;
                        break;
                    case '^':
                        a = a or b;
                        break;
                    default:
                        cout << "I don't know what to do" << endl;
                        break;
                }
                temp.push(a);
                a = b = 0;
            }while (temp.size()>1 && i==expresion.size()-1);
        }
    }
    return temp.top();
}


int main() {
    int sz_set = 4;
    pair<string, int> expresion[] = {
            {"ab+c-d*",   4}, // 24
            {"ab-c/e+",   5}, // 10
            {"abcde+*+",  5}, // 34
            {"ab+cd*+e*", 5}// 144 
    };
    pair<char, float> variables[] = {
            {'a', 5},
            {'b', 3},
            {'c', 2},
            {'d', 4},
            {'e', 9}
    };
    cout << "Sabiendo los valores de las siguientes variables: " << endl;
    for(int i=0;i<5;i++){
        cout << variables[i].first << " = " << variables[i].second << "; ";
    }
    cout << "\nAnaliza las siguientes expresiones en notacion postfijo:" << endl;
    float result;
    for (int i = 0; i < sz_set; i++) {
        result = evalua(expresion[i].first, variables, expresion[i].second);
        cout << "El resultado de evaluar: " << expresion[i].first << " es " << result << endl;
    }
}