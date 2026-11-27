#ifndef UNO_H
#define UNO_H

#include <vector>
#include <string>

// Colori: le carte jolly hanno colore NONE finche' non vengono giocate
enum Color { RED, YELLOW, GREEN, BLUE, NONE };

// Valori: 0..9 numeri, poi le carte azione
const int SKIP = 10;       // salta il turno
const int REVERSE = 11;    // inverti il senso di gioco
const int DRAW_TWO = 12;   // pesca due
const int WILD = 13;       // cambia colore
const int WILD_DRAW_FOUR = 14;  // cambia colore + pesca quattro

struct Card {
    Color color;
    int value;
};

typedef std::vector<Card> Deck;

struct Player {
    std::string name;
    bool human;
    Deck hand;
};

struct Game {
    Deck drawPile;            // mazzo da cui pescare
    Deck discardPile;         // carte in tavola (l'ultima e' quella scoperta)
    std::vector<Player> players;
    Color currentColor;       // colore attivo (scelto con i jolly)
    int current;              // indice del giocatore di turno
    int direction;            // +1 o -1
};

std::string cardToString(const Card &c);
void createDeck(Deck &d);
void shuffleDeck(Deck &d);
Card drawCard(Game &g);
void drawCards(Game &g, int player, int n);
bool isPlayable(const Card &c, const Card &top, Color currentColor);
void printHand(const Deck &hand);
int cardPoints(const Card &c);
void initGame(Game &g, const std::vector<Player> &players);
int nextPlayer(const Game &g, int from);
void playTurn(Game &g);
int playGame(Game &g);

#endif
