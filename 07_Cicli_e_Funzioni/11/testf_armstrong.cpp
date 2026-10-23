#include <iostream>
using namespace std;

int getLength(int num) {
    int length = 0;
    do {
        ++length;
        num /= 10;
    } while (num != 0);
    return length;
}

bool isArmstrong(int n) {
    if (n <= 0) return false;
    int cifre = getLength(n);
    int copia = n;
    long long somma = 0;
    while (copia > 0) {
        int cifra = copia % 10;
        long long potenza = 1;
        for (int i = 0; i < cifre; ++i) potenza *= cifra;
        somma += potenza;
        copia /= 10;
    }
    return somma == n;
}

int main() {
    int n;
    cout << "Inserisci un numero intero positivo: ";
    if (!(cin >> n)) return 1;
    cout << boolalpha << isArmstrong(n) << endl;
    return 0;
}
