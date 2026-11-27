#include <iostream>
#include <vector>
#include "isPresentInVector_funct.h"
using namespace std;

void test(const vector<int> &t, int x, bool expected) {
    bool r = isPresentInVector(t, x);
    cout << "x=" << x << " -> " << (r ? "true" : "false") << " "
         << (r == expected ? "OK" : "ERRORE") << endl;
}

int main() {
    vector<int> t = {3, 7, -2, 10, 7};
    test(t, 7, true);
    test(t, 3, true);    // primo elemento
    test(t, -2, true);
    test(t, 10, true);
    test(t, 5, false);
    vector<int> empty;
    test(empty, 1, false);  // vector vuoto
    return 0;
}
