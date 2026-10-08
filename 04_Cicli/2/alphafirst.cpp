#include <iostream>
using namespace std;

int main() {
    // Prima lettera
    char first;
    cout << "Inserisci una lettera maiuscola: ";
    do {
        if (!(cin >> first))
            return 1;
    } while (first < 'A' || first > 'Z');
    // Confronti
    char c = 'Z';
    do {
        if (c < first)
            first = c;
        cout << "Inserisci una lettera maiuscola (o altro carattere per terminare): ";
        if (!(cin >> c))
            break;
    } while (c >= 'A' && c <= 'Z');
    // Output
    cout << "La lettera piu' piccola inserita e' " << first << endl;
    return 0;
}
