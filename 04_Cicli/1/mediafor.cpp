#include <iostream>
using namespace std;

int main() {
    // Input
    cout << "Di quanti numeri vuoi fare la media?";
    int how_many;
    cin >> how_many;
    if (how_many <= 0) {
        cout << "Errore: il numero doveva essere positivo" << endl;
        return 42;
    }
    // Calcolo
    float sum = 0;
    for (int i = 0; i < how_many; ++i) {
        cout << "\nInserisci un numero ";
        float x;
        cin >> x;
        sum = sum + x;
    }
    // Output
    cout << "\nLa media e' " << sum / how_many << endl;
    return 0;
}
