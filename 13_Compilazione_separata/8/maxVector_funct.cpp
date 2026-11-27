#include <string>
#include "maxVector_funct.h"
using namespace std;

int maxVector(const vector<int> &t) {
    if (t.size() == 0)
        throw string("maxVector: il vector è vuoto");
    int max = t[0];
    for (size_t i = 1; i < t.size(); ++i)
        if (t[i] > max) max = t[i];
    return max;
}
