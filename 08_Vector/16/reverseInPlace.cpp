#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Numero di elementi: ";
    if (!(cin >> n) || n < 0) return 1;
    vector<float> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    for (int i = 0; i < n / 2; ++i) {
        float temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}
