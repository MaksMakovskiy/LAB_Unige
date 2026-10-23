#include <iostream>
#include <cstdlib>
using namespace std;

double onlineAverage() {
    double media = 0;
    int count = 0;
    char risposta;
    do {
        double numero;
        cout << "Inserisci un numero reale: ";
        if (!(cin >> numero)) exit(1);
        ++count;
        media += (numero - media) / count;
        do {
            cout << "Vuoi continuare? (y/n): ";
            if (!(cin >> risposta)) exit(1);
        } while (risposta != 'y' && risposta != 'n');
    } while (risposta == 'y');
    return media;
}

int main() {
    double media = onlineAverage();
    cout << "La media è " << media << endl;
    return 0;
}
