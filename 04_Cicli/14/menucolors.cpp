#include <iostream>
using namespace std;

int main() {
    // Menu
    bool valido = false;
    do {
        cout << "r Rosso\nv Verde\nb Blu\ng Giallo\na Arancio\nScegli un colore: ";
        char scelta;
        if (!(cin >> scelta))
            return 1;
        // Scelta
        valido = true;
        switch (scelta) {
        case 'r': case 'R': cout << "Rosso" << endl; break;
        case 'v': case 'V': cout << "Verde" << endl; break;
        case 'b': case 'B': cout << "Blu" << endl; break;
        case 'g': case 'G': cout << "Giallo" << endl; break;
        case 'a': case 'A': cout << "Arancio" << endl; break;
        default:
            cout << "Scelta non valida" << endl;
            valido = false;
        }
    } while (!valido);
    return 0;
}
