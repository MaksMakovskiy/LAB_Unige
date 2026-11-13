#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void stampaVector(const vector<int>& v) {
    cout << "{ ";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << v[i];
    }
    cout << " }" << endl;
}

void selectionSort(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < v.size(); ++j)
            if (v[j] < v[minIndex]) minIndex = j;
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }
}

int main() {
    const int N = 9, M = 10;
    vector<int> s1(N), s2(M), d(N + M);
    srand(unsigned(time(nullptr)));
    for (int i = 0; i < N; ++i) s1[i] = rand() % 256;
    for (int i = 0; i < M; ++i) s2[i] = rand() % 256;

    cout << "Vector s1 (generato) = "; stampaVector(s1);
    cout << "Vector s2 (generato) = "; stampaVector(s2);
    selectionSort(s1);
    selectionSort(s2);

    size_t i = 0, j = 0, k = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] <= s2[j]) d[k++] = s1[i++];
        else d[k++] = s2[j++];
    }
    while (i < s1.size()) d[k++] = s1[i++];
    while (j < s2.size()) d[k++] = s2[j++];

    cout << "Vector s1 (ordinato) = "; stampaVector(s1);
    cout << "Vector s2 (ordinato) = "; stampaVector(s2);
    cout << "Vector d = "; stampaVector(d);
    return 0;
}
