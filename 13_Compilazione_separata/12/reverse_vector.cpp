#include "reverse_vector.h"
using namespace std;

vector<int> reverse(const vector<int> &v) {
    vector<int> r;
    for (size_t i = v.size(); i > 0; --i)
        r.push_back(v[i - 1]);
    return r;
}
