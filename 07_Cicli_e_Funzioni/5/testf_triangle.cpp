#include <iostream>
using namespace std;

void replicate(int N, char c) {
    for (int i = 1; i <= N; ++i) cout << c;
}

void triangle(int length) {
    for (int i = 1; i <= length; ++i) {
        replicate(i, '*');
        cout << endl;
    }
}

int main() {
    cout << "Inserisci un numero maggiore di 0: ";
    int len;
    if (!(cin >> len)) return 1;
    if (len > 0) triangle(len);
    else cout << "Il numero deve essere positivo" << endl;
    return 0;
}
