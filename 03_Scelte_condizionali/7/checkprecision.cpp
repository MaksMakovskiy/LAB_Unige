#include <iostream>
using namespace std;

int main() {
    // Input
    float numero;
    cout << "Inserisci un numero reale: ";
    cin >> numero;
    // Calcolo
    float copia = numero;
    copia = copia / 4.9;
    copia = copia / 3.53;
    copia = copia / 6.9998;
    copia = copia * 4.9;
    copia = copia * 3.53;
    copia = copia * 6.9998;
    // Confronto
    if (copia != numero)
        cout << "moltiplicare NON e' l'inverso di dividere" << endl;
    return 0;
}
