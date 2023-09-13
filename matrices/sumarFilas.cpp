#include <iostream>
#include <vector>

using namespace std;

vector<int> sumarFilas(const vector<vector<int>>& matriz){
    vector<int> vectorSuma(matriz.size());
    for (int i = 0; i < matriz.size(); i++) {
        int suma = 0;
        for (int j = 0; j < matriz[0].size(); j++) {
            suma += matriz[i][j];
        }
        vectorSuma[i] = suma;
    }
    return vectorSuma;
}