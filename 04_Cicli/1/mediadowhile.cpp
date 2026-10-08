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
    int i = 0;
    do {
        cout << "\nInserisci un numero ";
        float x;
        cin >> x;
        sum = sum + x;
        ++i;
    } while (i < how_many);
    // Output
    cout << "\nLa media e' " << sum / how_many << endl;
    return 0;
}
