#include <iostream>
using namespace std;

int main() {
    // Input
    int a, b;
    cout << "Inserisci il valore di a: ";
    cin >> a;
    cout << "Inserisci il valore di b: ";
    cin >> b;
    cout << "\na vale " << a << "\nb vale " << b << endl;
    // Scambio
    int c = a;
    a = b;
    b = c;
    // Output
    cout << "\na vale " << a << "\nb vale " << b << endl;
    return 0;
}
