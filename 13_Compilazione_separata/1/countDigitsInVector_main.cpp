#include <iostream>
#include <vector>
#include "countDigitsInVector_funct.h"
using namespace std;

void printCharVector(const vector<char> &v) {
    cout << "{ ";
    for (size_t i = 0; i < v.size(); ++i) cout << "'" << v[i] << "' ";
    cout << "}";
}

void test(const vector<char> &v, int expected) {
    printCharVector(v);
    int r = countDigitsInVector(v);
    cout << " -> " << r << " cifre (atteso " << expected << ") "
         << (r == expected ? "OK" : "ERRORE") << endl;
}

int main() {
    // Test 1: vector con 2 cifre
    vector<char> test1 = {'f', '4', 'c', 'r', '5', 'R'};
    test(test1, 2);
    // Test 2: nessuna cifra
    vector<char> test2 = {'a', 'b', 'c', 'd', 'e', 'f'};
    test(test2, 0);
    // Test 3: solo cifre
    vector<char> test3 = {'0', '1', '2', '7', '8', '9'};
    test(test3, 6);
    // Test 4: vector vuoto
    vector<char> test4;
    test(test4, 0);
    return 0;
}
