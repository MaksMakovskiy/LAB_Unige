#include "sequentialSearch_vector.h"
using namespace std;

/*
 * Variante con return anticipato.
 * Differenze rispetto alla versione dell'esercizio 5:
 *  - non servono le variabili ausiliarie loc e found: appena l'elemento
 *    viene trovato la funzione termina restituendo direttamente i;
 *  - la condizione del ciclo controlla solo la fine del vector;
 *  - ci sono due punti di uscita (due return) invece di uno solo.
 * Il risultato e il numero di confronti eseguiti sono identici.
 */
int sequentialSearch_vector(const vector<int> &v, int item) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == item)
            return i;
    }
    return -1;
}
