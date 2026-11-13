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
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 0) {
            cout << "Sono richiesti interi positivi" << endl;
            return 1;
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (count == 0 || a[i] != a[count - 1]) {
            a[count] = a[i];
            ++count;
        }
    }
    for (int i = count; i < n; ++i) a[i] = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
