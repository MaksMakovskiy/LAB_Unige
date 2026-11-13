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
    vector<int> counts(n, 0);
    for (int i = 0; i < n; ++i) {
        bool alreadyCounted = false;
        for (int j = 0; j < i; ++j) {
            if (a[j] == a[i]) alreadyCounted = true;
        }
        if (!alreadyCounted) {
            for (int j = 0; j < n; ++j) {
                if (a[j] == a[i]) ++counts[i];
            }
            cout << a[i] << ": " << counts[i] << endl;
        }
    }
    return 0;
}
