#include <iostream>
#include <cstdlib>
#include <string>
#include "uno.h"
using namespace std;

static string colorName(Color c) {
    switch (c) {
        case RED: return "Rosso";
        case YELLOW: return "Giallo";
        case GREEN: return "Verde";
        case BLUE: return "Blu";
        default: return "Jolly";
    }
}

string cardToString(const Card &c) {
    string v;
    switch (c.value) {
        case SKIP: v = "Salta"; break;
        case REVERSE: v = "Inverti"; break;
        case DRAW_TWO: v = "+2"; break;
        case WILD: return "Jolly (cambia colore)";
        case WILD_DRAW_FOUR: return "Jolly +4";
        default: v = to_string(c.value);
    }
    return colorName(c.color) + " " + v;
}

// 108 carte: per ogni colore uno 0, due copie di 1..9, Salta, Inverti, +2;
// 4 Jolly e 4 Jolly +4
void createDeck(Deck &d) {
    d.clear();
    for (int col = RED; col <= BLUE; ++col) {
        Card c;
        c.color = Color(col);
        c.value = 0;
        d.push_back(c);
        for (int v = 1; v <= DRAW_TWO; ++v) {
            c.value = v;
            d.push_back(c);
            d.push_back(c);
        }
    }
    for (int i = 0; i < 4; ++i) {
        Card w;
        w.color = NONE;
        w.value = WILD;
        d.push_back(w);
        w.value = WILD_DRAW_FOUR;
        d.push_back(w);
    }
}

void shuffleDeck(Deck &d) {
    for (int i = int(d.size()) - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Card tmp = d[i];
        d[i] = d[j];
        d[j] = tmp;
    }
}

// Pesca una carta; se il mazzo e' finito rimescola gli scarti (tranne quello scoperto)
Card drawCard(Game &g) {
    if (g.drawPile.size() == 0) {
        Card top = g.discardPile[g.discardPile.size() - 1];
        for (size_t i = 0; i + 1 < g.discardPile.size(); ++i) {
            Card c = g.discardPile[i];
            if (c.value == WILD || c.value == WILD_DRAW_FOUR) c.color = NONE;
            g.drawPile.push_back(c);
        }
        g.discardPile.clear();
        g.discardPile.push_back(top);
        shuffleDeck(g.drawPile);
        cout << "(Il mazzo è finito: gli scarti vengono rimescolati)" << endl;
    }
    if (g.drawPile.size() == 0) {  // caso limite: nessuna carta disponibile
        throw string("Non ci sono più carte da pescare");
    }
    Card c = g.drawPile[g.drawPile.size() - 1];
    g.drawPile.pop_back();
    return c;
}

void drawCards(Game &g, int player, int n) {
    for (int i = 0; i < n; ++i)
        g.players[player].hand.push_back(drawCard(g));
}

bool isPlayable(const Card &c, const Card &top, Color currentColor) {
    if (c.value == WILD || c.value == WILD_DRAW_FOUR) return true;
    return c.color == currentColor || c.value == top.value;
}

void printHand(const Deck &hand) {
    for (size_t i = 0; i < hand.size(); ++i)
        cout << "  [" << i << "] " << cardToString(hand[i]) << endl;
}

int cardPoints(const Card &c) {
    if (c.value <= 9) return c.value;
    if (c.value <= DRAW_TWO) return 20;
    return 50;
}

void initGame(Game &g, const vector<Player> &players) {
    g.players = players;
    createDeck(g.drawPile);
    shuffleDeck(g.drawPile);
    g.discardPile.clear();
    for (size_t p = 0; p < g.players.size(); ++p) {
        g.players[p].hand.clear();
        drawCards(g, p, 7);
    }
    // la prima carta scoperta non deve essere un Jolly +4
    Card first = drawCard(g);
    while (first.value == WILD_DRAW_FOUR) {
        g.drawPile.insert(g.drawPile.begin(), first);
        first = drawCard(g);
    }
    if (first.value == WILD) first.color = Color(rand() % 4);
    g.discardPile.push_back(first);
    g.currentColor = first.color;
    g.direction = 1;
    g.current = 0;
    // effetti della prima carta
    if (first.value == REVERSE) {
        g.direction = -1;
    } else if (first.value == SKIP) {
        g.current = nextPlayer(g, 0);
    } else if (first.value == DRAW_TWO) {
        drawCards(g, 0, 2);
        g.current = nextPlayer(g, 0);
    }
}

int nextPlayer(const Game &g, int from) {
    int n = g.players.size();
    return ((from + g.direction) % n + n) % n;
}

static Color chooseColor(const Player &p) {
    if (p.human) {
        int c;
        cout << "Scegli il colore (0=Rosso, 1=Giallo, 2=Verde, 3=Blu): ";
        while (!(cin >> c) || c < 0 || c > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Scelta non valida - riprova: ";
        }
        return Color(c);
    }
    // computer: il colore di cui ha piu' carte
    int count[4] = {0, 0, 0, 0};
    for (size_t i = 0; i < p.hand.size(); ++i)
        if (p.hand[i].color != NONE) count[p.hand[i].color]++;
    int best = 0;
    for (int c = 1; c < 4; ++c)
        if (count[c] > count[best]) best = c;
    return Color(best);
}

// Restituisce l'indice della carta da giocare, -1 se si pesca
static int chooseCard(const Game &g, const Player &p) {
    const Card &top = g.discardPile[g.discardPile.size() - 1];
    if (p.human) {
        cout << "Carta in tavola: " << cardToString(top)
             << " - colore attivo: " << colorName(g.currentColor) << endl;
        cout << "La tua mano:" << endl;
        printHand(p.hand);
        while (true) {
            cout << "Indice della carta da giocare (-1 per pescare): ";
            int idx;
            if (!(cin >> idx)) {
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            if (idx == -1) return -1;
            if (idx >= 0 && idx < int(p.hand.size()) &&
                isPlayable(p.hand[idx], top, g.currentColor))
                return idx;
            cout << "Carta non giocabile." << endl;
        }
    }
    // computer: prima carte colorate/numeriche, i jolly per ultimi
    int wild = -1;
    for (size_t i = 0; i < p.hand.size(); ++i) {
        if (isPlayable(p.hand[i], top, g.currentColor)) {
            if (p.hand[i].color == NONE) {
                if (wild == -1) wild = i;
            } else {
                return i;
            }
        }
    }
    return wild;
}

// Gioca la carta idx del giocatore di turno e applica gli effetti
static void playCard(Game &g, int idx) {
    Player &p = g.players[g.current];
    Card c = p.hand[idx];
    p.hand.erase(p.hand.begin() + idx);
    if (c.value == WILD || c.value == WILD_DRAW_FOUR)
        c.color = chooseColor(p);
    g.discardPile.push_back(c);
    g.currentColor = c.color;
    cout << p.name << " gioca " << cardToString(c);
    if (c.value == WILD || c.value == WILD_DRAW_FOUR)
        cout << " e sceglie il " << colorName(c.color);
    cout << endl;
    if (p.hand.size() == 1) cout << p.name << ": UNO!" << endl;

    int next = nextPlayer(g, g.current);
    switch (c.value) {
        case SKIP:
            cout << g.players[next].name << " salta il turno" << endl;
            g.current = nextPlayer(g, next);
            return;
        case REVERSE:
            g.direction = -g.direction;
            // con 2 giocatori vale come Salta: il turno resta allo stesso giocatore
            if (g.players.size() > 2)
                g.current = nextPlayer(g, g.current);
            return;
        case DRAW_TWO:
            cout << g.players[next].name << " pesca 2 carte e salta il turno" << endl;
            drawCards(g, next, 2);
            g.current = nextPlayer(g, next);
            return;
        case WILD_DRAW_FOUR:
            cout << g.players[next].name << " pesca 4 carte e salta il turno" << endl;
            drawCards(g, next, 4);
            g.current = nextPlayer(g, next);
            return;
        default:
            g.current = next;
    }
}

void playTurn(Game &g) {
    Player &p = g.players[g.current];
    cout << endl << "--- Turno di " << p.name << " (" << p.hand.size() << " carte) ---" << endl;
    int idx = chooseCard(g, p);
    if (idx == -1) {
        Card c = drawCard(g);
        p.hand.push_back(c);
        const Card &top = g.discardPile[g.discardPile.size() - 1];
        if (p.human) cout << "Hai pescato: " << cardToString(c) << endl;
        else cout << p.name << " pesca una carta" << endl;
        if (isPlayable(c, top, g.currentColor)) {
            bool play = true;
            if (p.human) {
                char ans;
                cout << "Vuoi giocarla? (s/n): ";
                cin >> ans;
                play = (ans == 's' || ans == 'S');
            }
            if (play) {
                playCard(g, p.hand.size() - 1);
                return;
            }
        }
        g.current = nextPlayer(g, g.current);
        return;
    }
    playCard(g, idx);
}

// Gioca una mano completa; restituisce l'indice del vincitore
int playGame(Game &g) {
    while (true) {
        int who = g.current;
        playTurn(g);
        if (g.players[who].hand.size() == 0) {
            int points = 0;
            for (size_t i = 0; i < g.players.size(); ++i)
                for (size_t j = 0; j < g.players[i].hand.size(); ++j)
                    points += cardPoints(g.players[i].hand[j]);
            cout << endl << g.players[who].name << " ha vinto la mano e guadagna "
                 << points << " punti!" << endl;
            return who;
        }
    }
}
