#include <iostream>
using namespace std;

int main() {
    // Input e stampa
    char answer;
    do {
        int n;
        cout << "inserisci un numero intero positivo: ";
        if (!(cin >> n))
            return 1;
        cout << endl;
        for (int i = 0; i < n; ++i)
            cout << '|';
        cout << "\ninserisci s o S per terminare, qualsiasi altro carattere per proseguire: ";
        if (!(cin >> answer))
            return 1;
    } while (answer != 's' && answer != 'S');
    // Output
    cout << "ho terminato perche' hai inserito " << answer << endl;
    return 0;
}
