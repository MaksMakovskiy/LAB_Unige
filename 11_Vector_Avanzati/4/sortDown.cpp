#include <iostream>
#include <vector>
using namespace std;

void selectionSortDown(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] > v[maxIndex]) maxIndex = j;
        }
        int temp = v[i];
        v[i] = v[maxIndex];
        v[maxIndex] = temp;
    }
}

int main() {
    const int N = 20;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    vector<int> v = a;
    for (size_t i = 0; i < v.size(); ++i) cout << v[i] << ' ';
    cout << endl;
    selectionSortDown(v);
    for (size_t i = 0; i < v.size(); ++i) cout << v[i] << ' ';
    cout << endl;
    return 0;
}
