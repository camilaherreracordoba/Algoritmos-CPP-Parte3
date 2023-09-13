#include <iostream>
#include <vector>
#include <String>

using namespace std;

vector<vector<int>> sumarMatrices(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) {
    vector<vector<int>> matrizSuma(matriz1.size(), vector<int>(matriz1[0].size()));
    for (int i = 0; i < matriz1.size(); i++) {
        for (int j = 0; j < matriz1[0].size(); j++) {
            matrizSuma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return matrizSuma;
}
