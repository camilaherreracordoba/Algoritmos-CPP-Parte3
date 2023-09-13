#include <iostream>
#include <String>
#include "matriz.h"

using namespace std;

bool esMatrizIdentidad(const vector<vector<int>>& matriz) {
    int n = matriz.size();

    if (n != matriz[0].size()) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && matriz[i][j] != 1) {
                return false; 
            } else if (i != j && matriz[i][j] != 0) {
                return false; 
            }
        }
    }

    return true; 
}