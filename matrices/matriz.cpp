#include <iostream>
#include <vector>
using namespace std;

void printMatriz(const vector<vector<int>>& matriz) {
    for (const vector<int>& fila : matriz) {
        cout << "[ ";
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << "]" << endl;
    }
}