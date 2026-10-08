#include <iostream>
using namespace std;

int main() {
    // Input
    int n;
    cout << "Inserisci un numero intero: ";
    cin >> n;
    // Calcolo
    long long quadrato = n;
    quadrato = quadrato * n;
    // Tentativi
    long long risposta;
    do {
        cout << "Indovina il quadrato: ";
        if (!(cin >> risposta))
            return 1;
        if (risposta != quadrato)
            cout << "Riprova!" << endl;
    } while (risposta != quadrato);
    cout << "Bravo!" << endl;
    return 0;
}
