#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Punto.h"
#include "Node.h"
#include "List.h"
#include "Utilities.h"

using namespace std;

int main() {
    int action = 0;
    List Menu;
    vector <string> lines = {
            "---------------------------------",
            "|   Welcome to my shit-program  |",
            "|   1) AddPoints                |",
            "|   2) RemPoints                |",
            "|   3) ShowPoints               |",
            "|   4) Show Area                |",
            "|   5) Divide it into pieces    |",
            "|   6) Send it to a file        |",
            "|   7) Get Points from file     |",
            "|   8) Clear                    |",
            "---------------------------------",
    };
    while(action!=-1) {
        for(auto i: lines)
            cout << i << endl;
        cin >> action;
        Menu = Do(action, Menu);
        cout << "Press a key to continue " << endl;
        char c = getchar();
        char d = getchar();
        system("clear");
    }
}
