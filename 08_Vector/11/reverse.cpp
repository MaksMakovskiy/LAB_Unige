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
    vector<int> dest(n);
    for (int i = 0; i < n; ++i) {
        dest[i] = source[n - 1 - i];
        cout << source[i] << ' ';
    }
    cout << endl << endl;
    for (int i = 0; i < n; ++i) {
        cout << dest[i] << ' ';
    }
    cout << endl;
    return 0;
}
