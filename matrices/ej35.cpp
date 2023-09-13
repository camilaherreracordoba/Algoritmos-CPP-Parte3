/*
35) Escribir un algoritmo que halle una matriz C como suma de dos matrices A y B. La
dimensión de las matrices de M × N se lee como dato (suponer un MAX para fila y
columna).

*/
#include <iostream>
#include <vector>
#include <String>
#include "sumarMatrices.h"
#include "matriz.h"
using namespace std;




void ejecicio35(){
    int max_filas, max_columnas;

    cout << "Ingrese la cantidad de filas: ";
    cin >> max_filas;
    cout << "Ingrese la cantidad de columnas: ";
    cin >> max_columnas;

    vector<vector<int>> a(max_filas, vector<int>(max_columnas));
    vector<vector<int>> b(max_filas, vector<int>(max_columnas));
    cout << "Ingrese los elementos de la matriz A: " << endl;
    for (int i = 0; i < max_filas; i++) {
        for (int j = 0; j < max_columnas; j++) {
            cout << "Ingrese el elemento " << i << "," << j << ": ";
            cin >> a[i][j];
        }
    }
    cout << "Ingrese los elementos de la matriz B: " << endl;
    for (int i = 0; i < max_filas; i++) {
        for (int j = 0; j < max_columnas; j++) {
            cout << "Ingrese el elemento " << i << "," << j << ": ";
            cin >> b[i][j];
        }
    }
    cout << "Matriz A: " << endl;
    printMatriz(a);
    cout << "Matriz B: " << endl;
    printMatriz(b);
    cout << "Matriz A + B: " << endl;
    printMatriz(sumarMatrices(a, b));
}
int main() {
    
    ejecicio35();
    return 0;
}