/*
39) Escribir un algoritmo que construya un vector con los valores mínimos de cada una
de las filas de una matriz
*/

#include <iostream>
#include <String>
#include <vector>
#include "matriz.h"
#include "vectores.h"

using namespace std;

vector<int> minimosFilas(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    vector<int> minimos(n);

    for (int i = 0; i < n; i++) {
        int minimo = matriz[i][0];
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
            }
        }
        minimos[i] = minimo;
    }

    return minimos;
}

void ejercicio39() {
    int max_filas, max_columnas;

    cout << "Ingrese la cantidad de filas: ";
    cin >> max_filas;
    cout << "Ingrese la cantidad de columnas: ";
    cin >> max_columnas;
    vector<vector<int>> matriz(max_filas, vector<int>(max_columnas));
    cout << "Ingrese los elementos de la matriz: " << endl;
    for (int i = 0; i < max_filas; i++) {
        for (int j = 0; j < max_columnas; j++) {
            cout << "Ingrese el elemento " << i << "," << j << ": ";
            cin >> matriz[i][j];
        }
    }
    cout << "Matriz: " << endl;
    printMatriz(matriz);
    cout << "Vector minimos: " << endl;
    printVector(minimosFilas(matriz));
}

int main(){
    ejercicio39();
    return 0;
}