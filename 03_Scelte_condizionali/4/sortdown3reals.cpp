#include <iostream>
using namespace std;

int main() {
    // Input
    double a, b, c, aux;
    cin >> a >> b >> c;
    // Ordinamento
    if (a < b) {
        aux = a;
        a = b;
        b = aux;
    }
    if (a < c) {
        aux = a;
        a = c;
        c = aux;
    }
    if (b < c) {
        aux = b;
        b = c;
        c = aux;
    }
    // Output
    cout << a << " " << b << " " << c << endl;
    return 0;
}
