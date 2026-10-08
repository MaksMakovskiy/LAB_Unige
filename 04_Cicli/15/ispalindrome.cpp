#include <iostream>
using namespace std;

int main() {
    // Input
    int numero;
    cout << "Inserisci un numero intero positivo: ";
    cin >> numero;
    if (numero <= 0) {
        cout << "Valore non valido" << endl;
        return 1;
    }
    // Inversione
    int k = numero;
    long long inv = 0;
    while (k > 0) {
        inv = inv * 10 + k % 10;
        k = k / 10;
    }
    // Verifica
    if (inv == numero)
        cout << "Palindromo" << endl;
    else
        cout << "Non palindromo" << endl;
    return 0;
}
