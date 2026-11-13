#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Numero di elementi: ";
    if (!(cin >> n) || n < 0) return 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    vector<int> source = a;
    vector<int> dest = source;
    // Porta verso destra il maggiore di ogni coppia adiacente.
    for (int end = n - 1; end > 0; --end) {
        for (int i = 0; i < end; ++i) {
            if (dest[i] > dest[i + 1]) {
                int temp = dest[i];
                dest[i] = dest[i + 1];
                dest[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << dest[i] << ' ';
    cout << endl;
    return 0;
}
