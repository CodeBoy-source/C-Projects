#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool parentizada(string expresion){
    bool result = true;
    stack<char> left; char ultimo;
    for(int i=0;i<expresion.size();i++){
        if(expresion[i]!=')' && expresion[i]!='(' &&
           expresion[i]!='{' && expresion[i]!='}' &&
           expresion[i]!='[' && expresion[i]!=']')
        {
            continue;
        }
        else if(expresion[i]=='(' || expresion[i]=='[' || expresion[i]=='{') {
            left.push(expresion[i]);
        }
        else if(left.empty()){
            result = false;
            break;
        }else{
            ultimo = left.top();
            if(expresion[i]==')' && ultimo=='(' ||
               expresion[i]==']' && ultimo=='[' ||
               expresion[i]=='}' && ultimo=='{')
            {
                left.pop();
            }
        }
    }
    if(left.size()>0)
        result=false;
    return result;
}

int main(){
    int sz_set = 10;
    string test_set[] = {
            "][",
            "}{",
            ")(",
            "()}{(()",
            "(()[()])",
            "({[]})(())",
            "(()))(()()",
            "1+[(x-3)*2]^-1",
            "((-1)/(-2)",
            "Y entonces dijo ( el mayordomo ): [..]"
    };

    bool result = false;
    for(int i=0;i<sz_set;i++){
        result = parentizada(test_set[i]);
        if(result)
            cout << "La expresion: " << test_set[i] << " si esta parentizada correctamente" << endl;
        else
            cout << "La expresion: " << test_set[i] << " no esta parentizada correctamente" << endl;
    }
}
