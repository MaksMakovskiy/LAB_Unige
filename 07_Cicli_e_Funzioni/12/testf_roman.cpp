#include <iostream>
using namespace std;

void roman(int n) {
    if (n < 1 || n > 3000) {
        cout << "Numero non valido: deve essere compreso tra 1 e 3000";
        return;
    }
    while (n >= 1000) { cout << "M"; n -= 1000; }
    if (n >= 900) { cout << "CM"; n -= 900; }
    if (n >= 500) { cout << "D"; n -= 500; }
    if (n >= 400) { cout << "CD"; n -= 400; }
    while (n >= 100) { cout << "C"; n -= 100; }
    if (n >= 90) { cout << "XC"; n -= 90; }
    if (n >= 50) { cout << "L"; n -= 50; }
    if (n >= 40) { cout << "XL"; n -= 40; }
    while (n >= 10) { cout << "X"; n -= 10; }
    if (n == 9) { cout << "IX"; return; }
    if (n >= 5) { cout << "V"; n -= 5; }
    if (n == 4) { cout << "IV"; return; }
    while (n > 0) { cout << "I"; --n; }
}

int main() {
    int n;
    cout << "Inserisci un numero tra 1 e 3000: ";
    if (!(cin >> n)) return 1;
    roman(n);
    cout << endl;
    return 0;
}
