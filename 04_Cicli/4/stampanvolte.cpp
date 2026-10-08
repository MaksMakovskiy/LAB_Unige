#include <iostream>
using namespace std;

int main() {
    // Input
    int len;
    cout << "Inserisci un numero positivo: ";
    cin >> len;
    if (len <= 0) {
        cout << "Avevo detto positivo!" << endl;
        return 1;
    }
    char c;
    cout << "Inserisci il carattere da replicare: ";
    cin >> c;
    // Output
    for (int i = 0; i < len; ++i)
        cout << c;
    cout << endl;
    return 0;
}
