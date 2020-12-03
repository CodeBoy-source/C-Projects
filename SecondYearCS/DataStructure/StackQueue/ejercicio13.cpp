#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct CountVowels{
    bool operator()(const string& obj1, const string& obj2){
        bool result = false;
        int cont1 = 0, cont2 = 0;
        int min = (obj1.size() < obj2.size()) ? obj1.size() : obj2.size();
        string vowels = "AEIOU";
        for(int i=0;i<obj1.size();i++){
            for(int j=0;j<vowels.size();j++){
                if(toupper(obj1[i]) == vowels[j])
                    cont1++;
            }
        }
        for(int i=0;i<obj2.size();i++){
            for(int j=0;j<vowels.size();j++){
                if(toupper(obj2[i]) == vowels[j])
                    cont2++;
            }
        }

        if(cont1 < cont2)
            result = true;
        else if(cont1 == cont2) {
            for (int i = 0; i < min; i++) {
                if (toupper(obj1[i]) == toupper(obj2[i])) {
                    continue;
                } else if (toupper(obj1[i]) < toupper(obj2[i])) {
                    result = false;
                    break;
                } else if (toupper(obj1[i] > toupper(obj2[i]))) {
                    result = true;
                    break;
                }
            }
        }

        return result;
    }
};

int main(){
    string a = "Brian ";
    string b = "Prian ";
    string c = "aeiou";

    priority_queue<string, vector<string>, CountVowels> cola;
    cola.push(a);
    cola.push(b);
    cola.push(c);

    cout << "Elemento: " << cola.top() << endl;
    cola.pop();
    cout << "Elemento: " << cola.top() << endl;
    cola.pop();
    cout << "Elemento: " << cola.top() << endl;

}