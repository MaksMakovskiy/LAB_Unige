#include <iostream>
using namespace std;

int main() {
    // Input
    int length;
    cout << "Inserisci un numero maggiore di 0: ";
    cin >> length;
    if (length <= 0) {
        cout << "Valore non valido" << endl;
        return 1;
    }
    // Triangolo
    for (int i = 1; i <= length; ++i) {
        for (int j = 1; j <= i; ++j)
            cout << '*';
        cout << endl;
    }
    return 0;
}
