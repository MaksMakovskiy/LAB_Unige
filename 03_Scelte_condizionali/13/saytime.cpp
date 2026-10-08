#include <iostream>
using namespace std;

int main() {
    // Input
    int ore, minuti;
    cin >> ore >> minuti;
    if (ore < 0 || ore > 23 || minuti < 0 || minuti > 59) {
        cout << "Orario non valido" << endl;
        return -1;
    }
    // Ore
    cout << "Sono le ore ";
    switch (ore) {
    case 0: cout << "mezzanotte"; break;
    case 1: cout << "l'una"; break;
    case 2: cout << "due"; break;
    case 3: cout << "tre"; break;
    case 4: cout << "quattro"; break;
    case 5: cout << "cinque"; break;
    case 6: cout << "sei"; break;
    case 7: cout << "sette"; break;
    case 8: cout << "otto"; break;
    case 9: cout << "nove"; break;
    case 10: cout << "dieci"; break;
    case 11: cout << "undici"; break;
    case 12: cout << "dodici"; break;
    case 13: cout << "tredici"; break;
    case 14: cout << "quattordici"; break;
    case 15: cout << "quindici"; break;
    case 16: cout << "sedici"; break;
    case 17: cout << "diciassette"; break;
    case 18: cout << "diciotto"; break;
    case 19: cout << "diciannove"; break;
    case 20: cout << "venti"; break;
    case 21: cout << "ventuno"; break;
    case 22: cout << "ventidue"; break;
    case 23: cout << "ventitre"; break;
    }
    // Minuti
    if (minuti >= 45)
        cout << " e tre quarti";
    else if (minuti >= 30)
        cout << " e mezza";
    else if (minuti >= 15)
        cout << " e un quarto";
    if (minuti % 15 != 0)
        cout << " passate";
    cout << endl;
    return 0;
}
