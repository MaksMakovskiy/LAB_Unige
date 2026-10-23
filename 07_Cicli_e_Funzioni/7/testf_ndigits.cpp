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

int main() {
    int num;
    cout << "Inserisci un numero intero: ";
    if (!(cin >> num)) return 1;
    cout << "Numero di cifre: " << getLength(num) << endl;
    return 0;
}
