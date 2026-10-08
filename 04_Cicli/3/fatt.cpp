#include <iostream>
using namespace std;

int main() {
    // Input
    int n;
    cout << "Inserire un numero positivo o uguale a 0: ";
    cin >> n;
    if (n < 0) {
        cout << "Avevo detto positivo o uguale a 0!" << endl;
        return 7;
    }
    if (n > 20) {
        cout << "Numero troppo grande: massimo 20" << endl;
        return 1;
    }
    // Calcolo
    long long F = n;
    for (int i = n - 1; i > 1; --i)
        F = F * i;
    // Output
    if (F == 0)
        cout << "Il fattoriale di 0 e' 1" << endl;
    else
        cout << "Il fattoriale di " << n << " e' " << F << endl;
    return 0;
}
