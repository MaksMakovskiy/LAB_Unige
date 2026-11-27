#include <vector>
#include "reverse_vector.h"
#include "iovector.h"
using namespace std;

int main() {
    vector<int> source;
    readVectorAlt(source);
    vector<int> dest = reverse(source);
    printVector(source);
    printVector(dest);
    return 0;
}
