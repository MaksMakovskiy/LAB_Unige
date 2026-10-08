#include <iostream>
using namespace std;

int main() {
    // Input
    float base, altezza;
    cout << "Inserisci base e altezza: ";
    cin >> base >> altezza;
    // Calcolo
    float perimetro = 2 * (base + altezza);
    float area = base * altezza;
    // Output
    cout << "Perimetro: " << perimetro << "\nArea: " << area << endl;
    return 0;
}
