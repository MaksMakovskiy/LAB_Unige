#include "sequentialSearch_vector.h"
using namespace std;

int sequentialSearch_vector(const vector<int> &v, int item) {
    int loc = -1;
    bool found = false;
    for (size_t i = 0; i < v.size() && !found; ++i) {
        if (v[i] == item) {
            found = true;
            loc = i;
        }
    }
    return loc;
}
