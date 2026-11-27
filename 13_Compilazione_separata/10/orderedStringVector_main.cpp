#include <iostream>
#include <vector>
#include <string>
#include "orderedStringVector_funct.h"
using namespace std;

void test(const vector<string> &t, bool expected) {
    bool r = orderedStringVector(t);
    cout << (r ? "true" : "false") << " " << (r == expected ? "OK" : "ERRORE") << endl;
}

int main() {
    test({"albero", "banana", "casa", "cassa"}, true);
    test({"casa", "albero", "banana"}, false);
    test({"uno", "uno", "zero"}, true);
    test({"solo"}, true);
    test({}, true);
    return 0;
}
