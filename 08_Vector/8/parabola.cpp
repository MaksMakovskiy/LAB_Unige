#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 10;
    vector<float> arr(N);
    float a, b, c;
    cout << "Inserisci a, b e c: ";
    if (!(cin >> a >> b >> c)) return 1;
    cout << "Valori nell'intervallo [0,9] della parabola "
         << a << "x^2 + " << b << "x + " << c << endl;
    for (int x = 0; x < N; ++x) {
        arr[x] = a * x * x + b * x + c;
    }
    for (int x = 0; x < N; ++x) {
        cout << "Valore di arr[" << x << "] = " << arr[x] << endl;
    }
    return 0;
}
