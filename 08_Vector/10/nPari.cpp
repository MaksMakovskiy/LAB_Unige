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
    int P = 0;
    int D = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) ++P;
        else ++D;
    }
    cout << "Pari: " << P << "\nDispari: " << D << endl;
    return 0;
}
