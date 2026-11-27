#include "orderedStringVector_funct.h"
using namespace std;

bool orderedStringVector(const vector<string> &t) {
    for (size_t i = 1; i < t.size(); ++i)
        if (t[i] < t[i - 1]) return false;
    return true;
}
