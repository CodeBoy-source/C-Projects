#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int todecimal(vector<int> num,int power)
{
    int decimal = 0;
    for(int i=0;i<num.size();i++){
        decimal += num[i]*pow(power,num.size()-i);
    }
    return decimal;
}

int main(){
    vector<int> decimal;
    vector<int> type;
    vector<int> temp;
    int base, sz;

    fstream file("liczby.txt");
    string input;

    while(getline(file,input)){
        sz = input.size()-2; //Strings has '\0' in the last pos;
        base = input.at(sz)-'0';
        type.push_back(base);
        for(int i=0; i<sz-1;i++){
            temp.push_back(input.at(i)-'0');
        }
        decimal.push_back(todecimal(temp,base));
        temp.clear();
    }
    for(int i:decimal){
        cout << i << endl;
    }
    file.close();
    decimal.clear();
    type.clear();
}