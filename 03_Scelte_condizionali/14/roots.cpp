#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Input
    double a, b, c;
    cin >> a >> b >> c;
    // Equazione degenere
    if (a == 0) {
        if (b != 0)
            cout << "x = " << -c / b << endl;
        else if (c == 0)
            cout << "Infinite soluzioni" << endl;
        else
            cout << "Nessuna soluzione" << endl;
        return 0;
    }
    // Radici
    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
    } else if (delta == 0) {
        cout << "x = " << -b / (2 * a) << endl;
    } else {
        double reale = -b / (2 * a);
        double immaginaria = sqrt(-delta) / (2 * a);
        if (immaginaria < 0)
            immaginaria = -immaginaria;
        cout << "x1 = " << reale << " + " << immaginaria << "i" << endl;
        cout << "x2 = " << reale << " - " << immaginaria << "i" << endl;
    }
    return 0;
}
