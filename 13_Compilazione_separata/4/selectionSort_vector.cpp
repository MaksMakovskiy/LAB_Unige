#include "selectionSort_vector.h"
using namespace std;

void selectionSort_vector(vector<int> &v, bool ascending) {
    size_t index;
    for (size_t i = 0; i < v.size(); ++i) {
        index = i;
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (ascending ? v[j] < v[index] : v[j] > v[index])
                index = j;
        }
        int tmp = v[i];
        v[i] = v[index];
        v[index] = tmp;
    }
}
