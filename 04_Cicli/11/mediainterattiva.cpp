#include <iostream>
using namespace std;

int main() {
    // Input e somma
    double somma = 0;
    int quanti = 0;
    char risposta;
    do {
        int n;
        cout << "Inserisci un numero intero: ";
        if (!(cin >> n))
            return 1;
        somma = somma + n;
        ++quanti;
        cout << "Continuare? (n per terminare): ";
        if (!(cin >> risposta))
            return 1;
    } while (risposta != 'n');
    // Output
    cout << "La media e' " << somma / quanti << endl;
    return 0;
}
