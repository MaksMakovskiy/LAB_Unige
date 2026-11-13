#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& v, int item) {
    int left = 0;
    int right = int(v.size()) - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (v[middle] == item) return middle;
        if (v[middle] < item) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

int main() {
    const int N = 15;
    int item;
    cout << "Elemento da cercare: ";
    if (!(cin >> item)) return 1;
    vector<int> v(N);
    cout << "Inserisci 15 interi in ordine crescente: ";
    for (int i = 0; i < N; ++i) {
        if (!(cin >> v[i])) return 1;
        if (i > 0 && v[i] < v[i - 1]) {
            cout << "Il vector deve essere ordinato" << endl;
            return 1;
        }
    }
    int position = binarySearch(v, item);
    if (position >= 0) cout << "Posizione: " << position << endl;
    else cout << "Elemento assente" << endl;
    return 0;
}
