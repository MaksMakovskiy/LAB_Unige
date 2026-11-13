#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int D = 4;
    vector<int> v(D);
    for (int i = 0; i < D; ++i)
        if (!(cin >> v[i])) return 1;

    int last = v[D - 1];
    for (int i = D - 1; i > 0; --i)
        v[i] = v[i - 1];
    v[0] = last;

    for (int i = 0; i < D; ++i) cout << v[i] << ' ';
    cout << endl;
    return 0;
}
