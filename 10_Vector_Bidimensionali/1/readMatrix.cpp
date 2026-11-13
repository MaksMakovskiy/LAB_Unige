#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int M = 3;
    const int N = 4;
    vector<vector<int>> a(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(cin >> a[i][j])) return 1;
        }
    }
    return 0;
}
