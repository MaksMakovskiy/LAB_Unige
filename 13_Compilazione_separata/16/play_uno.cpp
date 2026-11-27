#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "uno.h"
using namespace std;

int main() {
    srand(time(0));
    cout << "=== UNO ===" << endl;
    int n;
    cout << "Numero di giocatori (2-10): ";
    while (!(cin >> n) || n < 2 || n > 10) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Valore non valido - riprova: ";
    }
    int humans;
    cout << "Quanti sono giocatori umani (0-" << n << ")? ";
    while (!(cin >> humans) || humans < 0 || humans > n) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Valore non valido - riprova: ";
    }

    vector<Player> players(n);
    for (int i = 0; i < n; ++i) {
        players[i].human = i < humans;
        if (players[i].human) {
            cout << "Nome del giocatore " << i + 1 << ": ";
            cin >> players[i].name;
        } else {
            players[i].name = "Computer" + to_string(i - humans + 1);
        }
    }

    Game g;
    try {
        initGame(g, players);
        playGame(g);
    } catch (const string &msg) {
        cout << "Partita interrotta: " << msg << endl;
    }
    return 0;
}
