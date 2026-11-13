#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[minIndex]) minIndex = j;
        }
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
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
    selectionSort(v);
    for (size_t i = 0; i < v.size(); ++i) cout << v[i] << ' ';
    cout << endl;
    return 0;
}
