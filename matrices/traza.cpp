#include <iostream>
#include <String>
#include "matriz.h"

using namespace std;

int traza(const vector<vector<int>>& matriz) {
    int suma = 0;
    for (int i = 0; i < matriz.size(); i++) {
        suma += matriz[i][i];
    }
    return suma;
}