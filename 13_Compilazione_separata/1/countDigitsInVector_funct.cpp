#include "countDigitsInVector_funct.h"

int countDigitsInVector(const std::vector<char>& v) {
    int count = 0;
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (v[i] >= '0' && v[i] <= '9')
            count++;
    }
    return count;
}
