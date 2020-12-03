#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct CompareSize {
    bool operator()(const string &obj1, const string &obj2) {
        bool result = false;
        if (obj1.size() < obj2.size())
            result = true;
        else if (obj1.size() == obj2.size()) {
            for (int i = 0; i < obj1.size(); i++) {
                if (toupper(obj1[i]) == toupper(obj2[i])) {
                    continue;
                }
                else if (toupper(obj1[i]) > toupper(obj2[i])) {
                    result = true;
                    break;
                }else if(toupper(obj1[i] < toupper(obj2[i]))) {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }

};

int main() {
    string a = "Brian";
    string b = "Profesor";

    priority_queue <string, vector<string>, CompareSize> cola;
    cola.push(a);
    cola.push(b);

    cout << "Elemento primero " << cola.top() << endl;
}