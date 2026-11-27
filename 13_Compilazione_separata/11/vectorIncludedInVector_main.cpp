#include <iostream>
#include <vector>
#include "vectorIncludedInVector_funct.h"
using namespace std;

void test(const vector<int> &t1, const vector<int> &t2, bool expected) {
    bool r = vectorIncludedInVector(t1, t2);
    cout << (r ? "true" : "false") << " " << (r == expected ? "OK" : "ERRORE") << endl;
}

int main() {
    test({1, 2, 3}, {3, 2, 1, 4}, true);
    test({1, 1, 2}, {2, 1}, true);       // ripetizioni ignorate
    test({1, 5}, {1, 2, 3}, false);
    test({}, {1, 2}, true);              // t1 vuoto
    test({}, {}, true);
    test({1}, {}, false);
    return 0;
}
