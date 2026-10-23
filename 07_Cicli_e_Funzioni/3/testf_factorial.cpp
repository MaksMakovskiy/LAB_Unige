#include <iostream>
#include <limits>
using namespace std;

int factorial(int n) {
    if (n < 0) {
        cout << "Il numero non può essere negativo" << endl;
        return -1;
    }
    // Con int il risultato deve rimanere rappresentabile.
    int risultato = 1;
    for (int i = 1; i <= n; ++i) {
        if (risultato > numeric_limits<int>::max() / i) {
            cout << "Fattoriale troppo grande per il tipo int" << endl;
            return -1;
        }
        risultato *= i;
    }
    return risultato;
}

int main() {
    cout << "Inserire un numero positivo: ";
    int num;
    if (!(cin >> num)) return 1;
    int risultato = factorial(num);
    if (risultato >= 0)
        cout << risultato << " è il fattoriale di " << num << endl;
    else cout << "Impossibile calcolare il fattoriale" << endl;
    return 0;
}
