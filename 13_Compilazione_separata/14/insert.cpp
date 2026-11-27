#include "insert.h"
using namespace std;

void insert(vector<int> &v, size_t i, int val) {
    if (i > v.size())
        throw int(i);
    if (v.size() == 0) {
        v.push_back(val);
        return;
    }
    v.push_back(v[v.size() - 1]);  // la lunghezza aumenta di 1
    for (size_t k = v.size() - 2; k > i; --k)
        v[k] = v[k - 1];          // sposta in avanti partendo dal fondo
    v[i] = val;
}
