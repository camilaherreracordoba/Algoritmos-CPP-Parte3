/*
38) Escribir un algoritmo que determine si una matriz cuadrada ingresada es la matriz
identidad. Optimizar el código.
*/

#include <iostream>
#include <String>
#include "matriz.h"
#include "esMatrizIdentidad.h"
using namespace std;



void ejercicio38() {
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
    if(esMatrizIdentidad(matriz)) {
        cout << "La matriz es identidad" << endl;
    } else {
        cout << "La matriz no es identidad" << endl;
    }
}
int main() {
    ejercicio38();
    return 0;
}