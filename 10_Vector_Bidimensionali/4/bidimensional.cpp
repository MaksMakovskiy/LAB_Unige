#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int M = 5;
    const int N = 8;
    vector<vector<int>> a(M, vector<int>(N, 0));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = i;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > 0) cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
