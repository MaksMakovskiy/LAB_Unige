#include <iostream>
using namespace std;

int main() {
    // Input
    int K;
    cout << "Inserisci un numero intero positivo: ";
    cin >> K;
    if (K <= 0) {
        cout << "Il numero inserito NON e' valido" << endl;
        return 1;
    }
    // Conteggio
    int cifre = 0;
    while (K > 0) {
        K = K / 10;
        ++cifre;
    }
    // Output
    if (cifre == 1)
        cout << "Il numero inserito e' composto da 1 cifra" << endl;
    else
        cout << "Il numero inserito e' composto da " << cifre << " cifre" << endl;
    return 0;
}
