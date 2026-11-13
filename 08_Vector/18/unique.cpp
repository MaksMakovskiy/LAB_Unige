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
    vector<int> uniqueValues;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] != a[i - 1]) uniqueValues.push_back(a[i]);
    }
    for (int i = 0; i < n; ++i) a[i] = 0;
    for (size_t i = 0; i < uniqueValues.size(); ++i) a[i] = uniqueValues[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
