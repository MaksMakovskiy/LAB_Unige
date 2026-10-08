#include <iostream>
using namespace std;

int main() {
    // Input
    float base, altezza;
    cout << "Inserisci base e altezza: ";
    cin >> base >> altezza;
    // Calcolo
    float area = base * altezza / 2;
    // Output
    cout << "Area: " << area << endl;
    return 0;
}
