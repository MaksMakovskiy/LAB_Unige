#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

int leggiVoto(int numeroStudente) {
    int voto;
    while (true) {
        cout << "Inserisci il voto dello studente " << numeroStudente << " (0-100): ";
        if (!(cin >> voto)) exit(1);
        if (voto >= 0 && voto <= 100) return voto;
        cout << "Voto non valido. Riprova." << endl;
    }
}

bool isPromosso(int voto) { return voto >= 60; }
int aggiornaSomma(int sommaAttuale, int voto) { return sommaAttuale + voto; }
int aggiornaPromossi(int promossiAttuali, int voto) {
    return promossiAttuali + (isPromosso(voto) ? 1 : 0);
}
int aggiornaBocciati(int bocciatiAttuali, int voto) {
    return bocciatiAttuali + (isPromosso(voto) ? 0 : 1);
}
int calcolaMassimo(int votoMassimo, int voto) {
    return voto > votoMassimo ? voto : votoMassimo;
}
int calcolaMinimo(int votoMinimo, int voto) {
    return voto < votoMinimo ? voto : votoMinimo;
}

int main() {
    int studenti;
    cout << "Inserisci il numero di studenti: ";
    if (!(cin >> studenti)) return 1;
    // Manteniamo rappresentabile la somma anche con tutti i voti pari a 100.
    if (studenti <= 0 || studenti > numeric_limits<int>::max() / 100) {
        cout << "Numero di studenti non valido" << endl;
        return 1;
    }
    int somma = 0, promossi = 0, bocciati = 0, massimo = 0, minimo = 100;
    for (int i = 1; i <= studenti; ++i) {
        int voto = leggiVoto(i);
        somma = aggiornaSomma(somma, voto);
        promossi = aggiornaPromossi(promossi, voto);
        bocciati = aggiornaBocciati(bocciati, voto);
        massimo = calcolaMassimo(massimo, voto);
        minimo = calcolaMinimo(minimo, voto);
    }
    cout << "\nMedia della classe: " << static_cast<double>(somma) / studenti << endl;
    cout << "Numero di studenti promossi: " << promossi << endl;
    cout << "Numero di studenti bocciati: " << bocciati << endl;
    cout << "Voto più alto: " << massimo << endl;
    cout << "Voto più basso: " << minimo << endl;
    return 0;
}
