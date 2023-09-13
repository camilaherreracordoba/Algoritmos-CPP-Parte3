/*
36) Escribir un algoritmo que halle un vector cuyos elementos son la suma de los
elementos de cada fila de una matriz previamente ingresada.
*/
#include <iostream>
#include <vector>
#include <String>
#include "sumarMatrices.h"
#include "vectores.h"
#include "matriz.h"
#include "sumarFilas.h"

using namespace std;


void ejercicio36() {
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
    cout << "Vector suma: " << endl;
    printVector(sumarFilas(matriz));
}

int main() {
    ejercicio36();
    return 0;
}
