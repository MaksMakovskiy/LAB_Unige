#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Preparazione
    srand(time(NULL));
    char risposta;
    do {
        // Input
        char mossa;
        do {
            cout << "Scegli f, c oppure s: ";
            if (!(cin >> mossa))
                return 1;
        } while (mossa != 'f' && mossa != 'c' && mossa != 's');
        // Computer
        int numero = rand() % 3;
        char computer;
        if (numero == 0)
            computer = 'f';
        else if (numero == 1)
            computer = 'c';
        else
            computer = 's';
        cout << "Computer: " << computer << endl;
        // Risultato
        if (mossa == computer)
            cout << "Pareggio!" << endl;
        else if ((mossa == 'f' && computer == 'c') ||
                 (mossa == 'c' && computer == 's') ||
                 (mossa == 's' && computer == 'f'))
            cout << "Hai vinto!" << endl;
        else
            cout << "Ha vinto il computer!" << endl;
        cout << "Vuoi continuare? (s/S): ";
        if (!(cin >> risposta))
            return 1;
    } while (risposta == 's' || risposta == 'S');
    return 0;
}
