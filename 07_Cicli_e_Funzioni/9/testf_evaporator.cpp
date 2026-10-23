#include <iostream>
using namespace std;

int evaporator(float litri, int percentuale, float soglia) {
    // -1 indica che non si raggiunge mai una quantità inferiore alla soglia.
    if (percentuale < 0 || percentuale > 100 || litri < 0 || soglia < 0)
        return -2;
    if (litri < soglia) return 0;
    if (soglia == 0 || percentuale == 0) return -1;
    if (percentuale == 100) return 1;
    double acqua = litri;
    int giorni = 0;
    while (acqua >= soglia) {
        acqua *= 1.0 - percentuale / 100.0;
        ++giorni;
    }
    return giorni;
}

int main() {
    float litri, soglia;
    int percentuale;
    cout << "Inserisci litri iniziali, percentuale giornaliera e soglia minima: ";
    if (!(cin >> litri >> percentuale >> soglia)) return 1;
    int giorni = evaporator(litri, percentuale, soglia);
    if (giorni == -2) cout << "Dati non validi: la percentuale deve essere tra 0 e 100" << endl;
    else if (giorni == -1) cout << "La macchina non scende mai sotto la soglia" << endl;
    else cout << "Giorni di funzionamento: " << giorni << endl;
    return 0;
}
