#include <iostream>
#include <vector>
#include "primes.h"
using namespace std;

int main() {
    int n;
    cout << "Inserire n: ";
    cin >> n;
    vector<int> p = primes(n);
    if (p.size() == 0) {
        cout << "Nessun numero primo tra 2 e " << n << endl;
    } else {
        cout << "Numeri primi tra 2 e " << n << ": ";
        for (size_t i = 0; i < p.size(); ++i) cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}
