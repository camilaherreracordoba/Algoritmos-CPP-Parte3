/*
37) Escribir un programa que calcule la traza de una matriz cuadrada. Recordar que la
traza de una matriz es la suma de los elementos de su diagonal principa
*/
#include <iostream>
#include <String>
#include "matriz.h"
#include "traza.h"

using namespace std;



void ejercicio37() {
    int filas_columnas;

    cout << "Ingrese la cantidad de filas y columnas (recordar que es una matriz cuadrada): ";
    cin >> filas_columnas;


    vector<vector<int>> matriz(filas_columnas, vector<int>(filas_columnas));
    cout << "Ingrese los elementos de la matriz: " << endl;
    for (int i = 0; i < filas_columnas; i++) {
        for (int j = 0; j < filas_columnas; j++) {
            cout << "Ingrese el elemento " << i << "," << j << ": ";
            cin >> matriz[i][j];
        }
    }
    cout << "Matriz: " << endl;
    printMatriz(matriz);
    cout << "Traza: " << traza(matriz) << endl;
}

int main() {
    ejercicio37();
    return 0;
}