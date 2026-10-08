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
    // Numero di cifre
    int k = numero;
    int cifre = 0;
    while (k > 0) {
        ++cifre;
        k = k / 10;
    }
    // Somma delle potenze
    k = numero;
    long long somma = 0;
    while (k > 0) {
        int cifra = k % 10;
        long long potenza = 1;
        for (int i = 0; i < cifre; ++i)
            potenza = potenza * cifra;
        somma = somma + potenza;
        k = k / 10;
    }
    // Verifica
    if (somma == numero)
        cout << "Numero di Armstrong" << endl;
    else
        cout << "Non e' un numero di Armstrong" << endl;
    return 0;
}
