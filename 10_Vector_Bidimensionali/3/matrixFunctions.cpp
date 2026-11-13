#include <iostream>
#include <vector>
using namespace std;

bool readMatrix(vector<vector<int>>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            if (!(cin >> a[i][j])) return false;
        }
    }
    return true;
}

void printMatrix(const vector<vector<int>>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    const int M = 3;
    const int N = 4;
    vector<vector<int>> a(M, vector<int>(N, 0));
    if (!readMatrix(a)) return 1;
    printMatrix(a);
    return 0;
}
