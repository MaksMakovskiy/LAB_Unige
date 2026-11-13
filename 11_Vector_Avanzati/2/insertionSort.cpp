#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i) {
        int item = v[i];
        size_t j = i;
        while (j > 0 && v[j - 1] > item) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = item;
    }
}

int main() {
    int n;
    cout << "Numero di elementi: ";
    if (!(cin >> n) || n < 0) return 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    vector<int> v = a;
    insertionSort(v);
    for (size_t i = 0; i < v.size(); ++i) cout << v[i] << ' ';
    cout << endl;
    return 0;
}
