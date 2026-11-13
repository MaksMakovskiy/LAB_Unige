#include <iostream>
#include <vector>
using namespace std;

int main() {
    long int n;
    cout << "Dimensione della tavola pitagorica: ";
    if (!(cin >> n) || n <= 0) return 1;
    vector<int> table(n * (n + 1) / 2);
    for (long int row = 0; row < n; ++row) {
        for (long int col = 0; col <= row; ++col) {
            table[row * (row + 1) / 2 + col] = (row + 1) * (col + 1);
        }
    }
    // La posizione simmetrica usa lo stesso elemento del triangolo inferiore.
    for (long int row = 0; row < n; ++row) {
        for (long int col = 0; col < n; ++col) {
            long int r = row;
            long int c = col;
            if (c > r) {
                long int temp = r;
                r = c;
                c = temp;
            }
            cout << table[r * (r + 1) / 2 + c] << '	';
        }
        cout << endl;
    }
    return 0;
}
