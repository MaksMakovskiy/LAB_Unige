#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 10;
    const int LIMIT = 1 << N;
    int number;
    if (!(cin >> number)) return 1;
    if (number < 0 || number >= LIMIT) {
        cout << "Numero NON valido" << endl;
        return 0;
    }
    vector<int> bits(N, 0);
    int value = number;
    for (int i = N - 1; i >= 0 && value > 0; --i) {
        bits[i] = value % 2;
        value /= 2;
    }
    for (int i = 0; i < N; ++i) cout << bits[i];
    cout << endl;
    return 0;
}
