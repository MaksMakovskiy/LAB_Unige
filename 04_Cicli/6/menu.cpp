#include <iostream>
using namespace std;

int main() {
    // Menu
    int answer;
    do {
        cout << "1 Prima scelta\n2 Seconda scelta\n3 Terza scelta\n0 Uscita dal programma\nFai una scelta: ";
        if (!(cin >> answer))
            return 1;
        // Scelta
        switch (answer) {
        case 1: cout << "Hai fatto la prima scelta" << endl; break;
        case 2: cout << "Hai fatto la seconda scelta" << endl; break;
        case 3: cout << "Hai fatto la terza scelta" << endl; break;
        case 0: cout << "Hai scelto di uscire dal programma." << endl; break;
        default: cout << "Scelta non valida" << endl;
        }
    } while (answer != 0);
    return 0;
}
