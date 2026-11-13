#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 10;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}
