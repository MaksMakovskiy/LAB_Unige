#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n;
    cout << "Inserisci un numero intero: ";
    if (!(cin >> n)) return 1;
    cout << boolalpha << isPrime(n) << endl;
    return 0;
}
