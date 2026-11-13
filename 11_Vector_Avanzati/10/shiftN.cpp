#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int D = 4;
    vector<int> v(D);
    for (int i = 0; i < D; ++i)
        if (!(cin >> v[i])) return 1;
    int N;
    if (!(cin >> N)) return 1;

    // Positive N: shift right; negative N: shift left.
    // Use long long so even INT_MIN can be handled safely.
    long long steps = N < 0 ? -(long long)N : (long long)N;
    if (steps >= D) {
        for (int i = 0; i < D; ++i) v[i] = 0;
    } else if (N > 0) {
        for (int i = D - 1; i >= steps; --i)
            v[i] = v[i - steps];
        for (int i = 0; i < steps; ++i) v[i] = 0;
    } else if (N < 0) {
        for (int i = 0; i + steps < D; ++i)
            v[i] = v[i + steps];
        for (int i = D - steps; i < D; ++i) v[i] = 0;
    }

    for (int i = 0; i < D; ++i) cout << v[i] << ' ';
    cout << endl;
    return 0;
}
