#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 5;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    int maxVal = a[0];
    int maxCount = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] > maxVal) {
            maxVal = a[i];
            maxCount = 1;
        } else if (a[i] == maxVal) {
            ++maxCount;
        }
    }
    cout << "maxVal = " << maxVal << endl;
    cout << "maxCount = " << maxCount << endl;
    return 0;
}
