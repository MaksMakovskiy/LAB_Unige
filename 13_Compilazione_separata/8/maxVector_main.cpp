#include <iostream>
#include <vector>
#include <string>
#include "maxVector_funct.h"
using namespace std;

void test(const vector<int> &t) {
    try {
        int m = maxVector(t);
        cout << "max = " << m << endl;
    } catch (const string &msg) {
        cout << "Eccezione: " << msg << endl;
    }
}

int main() {
    test({4, 9, -1, 9, 2});   // atteso 9
    test({-5, -3, -8});       // atteso -3
    test({42});               // atteso 42
    test({});                 // eccezione
    return 0;
}
