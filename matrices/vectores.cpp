#include <iostream>
#include <vector>
#include <String>
using namespace std;

void printVector(vector<int> vec) {
    string str = "{";
    for (int i = 0; i < vec.size(); i++) {
        str += to_string(vec[i]);
        if (i != vec.size() - 1) {
            str += ", ";
        }   
    }
    str += "}";
    cout << str << endl;
}

vector<int> ordenarVector(vector<int> vec) {
    vector<int> vec2(vec.size());
    int min = vec[0];
    int pos = 0;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] < min) {
                min = vec[j];
                pos = j;
            }
        }
        vec2[i] = min;
        vec[pos] = 999999999;
        min = 999999999;
    }
    return vec2;
}