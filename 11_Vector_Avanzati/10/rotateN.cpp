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

    // Positive N: rotate right; negative N: rotate left.
    int steps = N % D;
    if (steps < 0) steps += D;
    vector<int> result(D);
    for (int i = 0; i < D; ++i)
        result[(i + steps) % D] = v[i];

    for (int i = 0; i < D; ++i) cout << result[i] << ' ';
    cout << endl;
    return 0;
}
