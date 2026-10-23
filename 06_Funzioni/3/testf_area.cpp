#include <iostream>
using namespace std;

float area(float base, float altezza) {
    if (base <= 0 && altezza <= 0) return -3;
    if (base <= 0) return -1;
    if (altezza <= 0) return -2;
    return base * altezza;
}

int main() {
    float b, h;
    cout << "Inserisci base e altezza: ";
    if (!(cin >> b >> h)) return 1;
    float a = area(b, h);
    if (a == -3) cout << "Base e altezza non valide" << endl;
    else if (a == -1) cout << "Base non valida" << endl;
    else if (a == -2) cout << "Altezza non valida" << endl;
    else cout << "Area: " << a << endl;
    return 0;
}
