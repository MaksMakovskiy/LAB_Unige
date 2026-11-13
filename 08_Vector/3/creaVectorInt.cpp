#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 10;
    vector<int> a(N, 0);
    for (int i = 0; i < N; ++i) {
        a[i] = N - i;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}
