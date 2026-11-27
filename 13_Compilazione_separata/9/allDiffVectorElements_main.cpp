#include <iostream>
#include <vector>
#include "allDiffVectorElements_funct.h"
using namespace std;

void test(const vector<int> &t, bool expected) {
    bool r = allDiffVectorElements(t);
    cout << (r ? "true" : "false") << " " << (r == expected ? "OK" : "ERRORE") << endl;
}

int main() {
    test({1, 2, 3, 4}, true);
    test({1, 2, 3, 1}, false);
    test({5, 5}, false);
    test({7}, true);
    test({}, true);
    return 0;
}
