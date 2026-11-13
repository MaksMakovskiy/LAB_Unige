#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 5;
    vector<float> a(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    cout << "I valori contenuti nel vector a sono: { ";
    for (size_t i = 0; i < a.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << a[i];
    }
    cout << " }" << endl;
    return 0;
}
