#include <iostream>
using namespace std;

int main() {
    // Input
    char a, b;
    cout << "Mosse dei due giocatori (f, c, s): ";
    cin >> a >> b;
    // Verifica
    if ((a != 'f' && a != 'c' && a != 's') ||
        (b != 'f' && b != 'c' && b != 's')) {
        cout << "Mossa non valida" << endl;
        return 1;
    }
    // Risultato
    if (a == b)
        cout << "Pareggio!" << endl;
    else if ((a == 'f' && b == 'c') || (a == 'c' && b == 's') || (a == 's' && b == 'f'))
        cout << "Giocatore 1 hai vinto!" << endl;
    else
        cout << "Giocatore 2 hai vinto!" << endl;
    return 0;
}
