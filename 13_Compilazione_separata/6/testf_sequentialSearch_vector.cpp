#include <iostream>
#include <vector>
#include "sequentialSearch_vector.h"
#include "iovector.h"
using namespace std;

int main() {
    vector<int> v;
    readVector(v);
    printVector(v);
    cout << "Quale elemento vuoi cercare? ";
    int item;
    cin >> item;
    int pos = sequentialSearch_vector(v, item);
    if (pos == -1)
        cout << "L'elemento " << item << " non è presente" << endl;
    else
        cout << "L'elemento " << item << " è presente in posizione " << pos << endl;
    return 0;
}
