#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int leggiMese() {
    int mese;
    cout << "Inserisci il numero del mese: ";
    if (!(cin >> mese)) exit(1);
    return mese;
}

string nomeMese(int mese) {
    switch (mese) {
        case 1: return "gennaio";
        case 2: return "febbraio";
        case 3: return "marzo";
        case 4: return "aprile";
        case 5: return "maggio";
        case 6: return "giugno";
        case 7: return "luglio";
        case 8: return "agosto";
        case 9: return "settembre";
        case 10: return "ottobre";
        case 11: return "novembre";
        case 12: return "dicembre";
        default: return "Mese NON valido!";
    }
}

void stampaRisultato(string risultato) {
    cout << risultato << endl;
}

int main() {
    int mese = leggiMese();
    string risultato = nomeMese(mese);
    stampaRisultato(risultato);
    return 0;
}
