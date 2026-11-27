#include "isPresentInVector_funct.h"
using namespace std;

bool isPresentInVector(const vector<int> &t, int x) {
    for (size_t i = 0; i < t.size(); ++i)
        if (t[i] == x) return true;
    return false;
}
