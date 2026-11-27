#include "vectorIncludedInVector_funct.h"
using namespace std;

bool vectorIncludedInVector(const vector<int> &t1, const vector<int> &t2) {
    for (size_t i = 0; i < t1.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < t2.size() && !found; ++j)
            if (t1[i] == t2[j]) found = true;
        if (!found) return false;
    }
    return true;
}
