#include <iostream>
using namespace std;

int main() {
    // Input
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    // Scambio
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    // Output
    cout << a << " " << b << endl;
    return 0;
}
