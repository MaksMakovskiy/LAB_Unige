#include <iostream>
using namespace std;

int main() {
    // Input
    int n;
    cout << "Inserisci un numero intero positivo: ";
    cin >> n;
    if (n <= 0) {
        cout << "Valore non valido" << endl;
        return 1;
    }
    // Parte superiore
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j)
            cout << ' ';
        for (int j = 0; j < 2 * i + 1; ++j)
            cout << '*';
        cout << endl;
    }
    // Parte inferiore
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j)
            cout << ' ';
        for (int j = 0; j < 2 * i + 1; ++j)
            cout << '*';
        cout << endl;
    }
    return 0;
}
