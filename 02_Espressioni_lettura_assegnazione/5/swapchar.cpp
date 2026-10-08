#include <iostream>
using namespace std;

int main() {
    // Input
    char a, b;
    cout << "Inserisci il valore di a: ";
    cin >> a;
    cout << "Inserisci il valore di b: ";
    cin >> b;
    cout << "\na vale " << a << "\nb vale " << b << endl;
    // Scambio
    char c = a;
    a = b;
    b = c;
    // Output
    cout << "\na vale " << a << "\nb vale " << b << endl;
    return 0;
}
