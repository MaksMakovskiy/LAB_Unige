#include <iostream>
using namespace std;

int main() {
    // Input
    int numero;
    cout << "Inserire un numero non nullo senza zeri finali: ";
    cin >> numero;
    if (numero == 0 || numero % 10 == 0) {
        cout << "Valore non valido" << endl;
        return 66;
    }
    // Inversione
    long long k = numero;
    if (k < 0)
        k = -k;
    long long inv = 0;
    while (k > 0) {
        int mod = k % 10;
        k = k / 10;
        inv = inv * 10 + mod;
    }
    if (numero < 0)
        inv = -inv;
    // Output
    cout << "Rovesciando " << numero << " si ottiene " << inv << endl;
    return 0;
}
