#include <iostream>
using namespace std;

int main() {
    // Input
    float a, b, c;
    cin >> a >> b >> c;
    cout << a << " " << b << " " << c << endl;
    // Rotazione
    float aux = a;
    a = b;
    b = c;
    c = aux;
    // Output
    cout << a << " " << b << " " << c << endl;
    return 0;
}
