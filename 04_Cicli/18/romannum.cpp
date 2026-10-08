#include <iostream>
using namespace std;

int main() {
    // Input
    int n;
    cin >> n;
    if (n < 1 || n > 3000) {
        cout << "Valore non valido" << endl;
        return 1;
    }
    // Conversione
    while (n >= 1000) {
        cout << "M";
        n = n - 1000;
    }
    while (n >= 900) {
        cout << "CM";
        n = n - 900;
    }
    while (n >= 500) {
        cout << "D";
        n = n - 500;
    }
    while (n >= 400) {
        cout << "CD";
        n = n - 400;
    }
    while (n >= 100) {
        cout << "C";
        n = n - 100;
    }
    while (n >= 90) {
        cout << "XC";
        n = n - 90;
    }
    while (n >= 50) {
        cout << "L";
        n = n - 50;
    }
    while (n >= 40) {
        cout << "XL";
        n = n - 40;
    }
    while (n >= 10) {
        cout << "X";
        n = n - 10;
    }
    while (n >= 9) {
        cout << "IX";
        n = n - 9;
    }
    while (n >= 5) {
        cout << "V";
        n = n - 5;
    }
    while (n >= 4) {
        cout << "IV";
        n = n - 4;
    }
    while (n >= 1) {
        cout << "I";
        n = n - 1;
    }
    cout << endl;
    return 0;
}
