#include <iostream>
#include <stack>
#include <cstdlib>

#define MAX_ITER 200
using namespace std;
/*
 * Esta fue la solucion que se me ocurrió, después de hablar con el profesor.
 */
stack <pair<int, int>> salida_laberinto(char** laberinto, int num_filas, int num_columnas) {
    stack <pair<int, int>> camino;
    pair<int, int> entrada;
    bool found = false;
    int i, j;
    for (i = 0; i < num_filas && !found; i++) {
        for (j = 0; j < num_columnas; j++) {
            if (laberinto[i][j] == 'E') {
                entrada.first = i;
                entrada.second = j;
                camino.push(entrada);
                found = true;
                break;
            }
        }
    }
    pair<int, int> temp = camino.top(); // NEW CURRENT CELL
    i = temp.first;
    j = temp.second;
    char dir[4] = {'N', 'E', 'S', 'W'};
    int x = 0, d;
    found = false;
    bool tried[4] = {0};
    while (!found && x < MAX_ITER) {
        d = rand() % 4;
        if (dir[d] == 'N') {
            tried[d] = true;
            if (i > 0) {
                if (laberinto[i - 1][j] == '0' || laberinto[i - 1][j] == 'S') {
                    for (int b = 0; b < 4; b++) {
                        tried[b] = false;
                    }
                    i--;
                    temp.first = i;
                    temp.second = j;
                    if (laberinto[i][j] == 'S')
                        found = true;
                    else
                        laberinto[i][j] = 'x';
                    camino.push(temp);
                }
            }
        }
        if (dir[d] == 'E') {
            tried[d] = true;
            if (j < num_columnas - 1) {
                if (laberinto[i][j + 1] == '0' || laberinto[i][j + 1] == 'S') {
                    for (int b = 0; b < 4; b++) {
                        tried[b] = false;
                    }
                    j++;
                    temp.first = i;
                    temp.second = j;
                    if (laberinto[i][j] == 'S')
                        found = true;
                    else
                        laberinto[i][j] = 'x';
                    camino.push(temp);
                }
            }
        }
        if (dir[d] == 'S') {
            tried[d] = true;
            if (i < num_filas - 1) {
                if (laberinto[i + 1][j] == '0' || laberinto[i + 1][j] == 'S') {
                    for (int b = 0; b < 4; b++) {
                        tried[b] = false;
                    }
                    i++;
                    temp.first = i;
                    temp.second = j;
                    if (laberinto[i][j] == 'S')
                        found = true;
                    else
                        laberinto[i][j] = 'x';
                    camino.push(temp);
                }
            }
        }
        if (dir[d] == 'W') {
            tried[d] = true;
            if (j > 0) {
                if (laberinto[i][j - 1] == '0' || laberinto[i][j - 1] == 'S') {
                    for (int b = 0; b < 4; b++) {
                        tried[b] = false;
                    }
                    j--;
                    temp.first = i;
                    temp.second = j;
                    if (laberinto[i][j] == 'S')
                        found = true;
                    else
                        laberinto[i][j] = 'x';
                    camino.push(temp);
                }
            }
        }
        if (tried[0] && tried[1] && tried[2] && tried[3] && camino.size() > 1) {
            camino.pop();
            temp = camino.top(); //New current cell if all directions failed.
            i = temp.first;
            j = temp.second;
            for (int i = 0; i < 4; i++) {
                tried[i] = false;
            }
        }
        x++;
    }
    return camino;
}

int main() {
    srand(time(NULL));
    int num_filas = 5, num_columnas = 5;
    char draw[num_filas][num_columnas] = {
            {'E', '0', '0', '0', '0'},
            {'0', '0', '1', '1', '0'},
            {'0', '0', '0', '0', '0'},
            {'1', '0', '1', '0', '1'},
            {'1', '0', '1', '0', 'S'}
    };
    char **laberinto = new char*[num_filas];

    for (int i = 0; i < num_filas; i++) {
        laberinto[i] = new char[num_columnas];
        for (int j = 0; j < num_columnas; j++) {
            laberinto[i][j] = draw[i][j];
        }
    }

    for (int i = 0; i < num_filas; i++) {
        for (int j = 0; j < num_columnas; j++) {
            cout << laberinto[i][j] << " ";
        }
        cout << endl;
    }

    stack <pair<int, int>> camino = salida_laberinto(laberinto,num_filas,num_columnas);
    cout << endl;
    for (int i = 0; i < num_filas; i++) {
        for (int j = 0; j < num_columnas; j++) {
            cout << laberinto[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hemos encontrado una salida: " << endl;

    int i = 0, sz = camino.size();
    while (!camino.empty()) {
        cout << "( " << camino.top().first << ", " << camino.top().second << " )";
        camino.pop();
        if (i != sz - 1)
            cout << " -> ";
        else
            cout << endl;
        i++;
    }
}