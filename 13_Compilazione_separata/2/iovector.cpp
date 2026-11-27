#include <iostream>
#include "iovector.h"
using namespace std;

void readVector(vector<int> &v) {
    cout << "Inserisci la dimensione della sequenza: ";
    int N;
    cin >> N;
    while (N <= 0) {
        cout << "La dimensione deve essere positiva - riprova: ";
        cin >> N;
    }
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void printVector(const vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}
