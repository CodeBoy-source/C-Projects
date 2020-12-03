#include <iostream>
#include <stack>
#include <cstdlib>

#define MAXR 5
#define MAXC 5
#define MAX_ITER 1000
using namespace std;

template<class T>
stack<T> quitarDuplicados(stack<T> camino){
    stack<T> temp, res;
    T valor;
    while(!camino.empty()){
        valor = camino.top();
        camino.pop();
        temp = camino;
        while(!temp.empty()){
            if(valor == temp.top()) {
                temp.pop();
                camino = temp;
            }else
                temp.pop();
        }
        res.push(valor);
    }

    return res;
}

stack <pair<int, int>> salida_laberinto(char laberinto[MAXR][MAXC]) {
    char dir[4] = {'N', 'E', 'S', 'W'};
    stack <pair<int, int>> camino;
    pair<int, int> temp;
    bool found = false;
    int i, j, d = 0, still = 0;
    for (i = 0; i < MAXR && !found; i++) {
        for (j = 0; j < MAXC; j++) {
            if (laberinto[i][j] == 'E') {
                temp.first = i;
                temp.second = j;
                camino.push(temp);
                found = true;
                break;
            }
        }
    }
    temp = camino.top();
    i = temp.first;
    j = temp.second;
    found = false;
    int x = 0;
    while (!found && x < MAX_ITER) {
        if (dir[d] == 'N' && i > 0) {
            i--;
            if (laberinto[i][j] != '1') {
                if (laberinto[i][j] == 'S')
                    found = true;
                temp.first = i;
                temp.second = j;
                camino.push(temp);
            }else {
                i++;
            }
        }
        if (dir[d] == 'E' && j < MAXC-1) {
            j++;
            if (laberinto[i][j] != '1') {
                if (laberinto[i][j] == 'S')
                    found = true;
                temp.first = i;
                temp.second = j;
                camino.push(temp);
            }else {
                j--;
            }
        }
        if (dir[d] == 'S' && i < MAXR-1) {
            i++;
            if (laberinto[i][j] != '1') {
                if (laberinto[i][j] == 'S')
                    found = true;
                temp.first = i;
                temp.second = j;
                camino.push(temp);
            }else{
                i--;
            }
        }
        if (dir[d] == 'W' && j > 0) {
            j--;
            if (laberinto[i][j] != '1') {
                if (laberinto[i][j] == 'S')
                    found = true;
                temp.first = i;
                temp.second = j;
                camino.push(temp);
            }else {
                j++;
            }
        }
        d = (rand()%4);
        if (d > 3) {
            d = 0;
        }
        x++;
    }
    camino = quitarDuplicados(camino);
    return camino;
}

int main() {
    srand(time(NULL));
    char laberinto[MAXR][MAXC] = {
            {'E', '0', '0', '0', '0'},
            {'0', '0', '1', '1', '0'},
            {'0', '0', '0', '0', '0'},
            {'1', '0', '1', '0', '1'},
            {'1', '0', '1', '0', 'S'}
    };

    for(int i=0;i<MAXR;i++){
        for(int j=0;j<MAXC;j++){
            cout << laberinto[i][j] << " ";
        }
        cout << endl;
    }

    stack <pair<int, int>> camino = salida_laberinto(laberinto);

    int i=0, sz = camino.size();
    while(!camino.empty()){
        cout << "( " << camino.top().first << ", " << camino.top().second << " )";
        camino.pop();
        if (i != sz - 1)
            cout << " -> ";
        else
            cout << endl;
        i++;
    }
}