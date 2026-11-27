#include <iostream>
#include <string>
#include "phoneBook.h"
using namespace std;

void testFind(const phoneBook &B, const string &s) {
    size_t pos;
    bool found = find_phoneBook_contact_by_surname(B, s, pos);
    cout << "Cerco \"" << s << "\": " << (found ? "trovato" : "non trovato")
         << ", pos = " << pos << endl;
}

int main() {
    // --- (a) + (b): inserimento in coda e stampa
    phoneBook B;
    push_contact_in_phoneBook(B, "Turing", "Alan", "+441234567");
    push_contact_in_phoneBook(B, "Lovelace", "Ada", "0101010");
    cout << "== Rubrica creata con push_contact_in_phoneBook:" << endl;
    print_phoneBook(B);

    // --- (c): lettura da file
    phoneBook F;
    read_phoneBook_from_file(F, "phoneBook.txt");
    cout << endl << "== Rubrica letta da phoneBook.txt:" << endl;
    print_phoneBook(F);

    // --- (e): ordinamento
    sort_phoneBook_by_surnames(F);
    cout << endl << "== Rubrica ordinata per cognome:" << endl;
    print_phoneBook(F);

    // --- (f): ricerca binaria
    cout << endl << "== Ricerca binaria:" << endl;
    testFind(F, "Gauss");       // presente
    testFind(F, "Einstein");    // presente, primo
    testFind(F, "Tesla");       // presente, ultimo
    testFind(F, "Bohr");        // assente, prima di tutti -> 0
    testFind(F, "Galilei");     // assente, in mezzo -> 2
    testFind(F, "Volta");       // assente, dopo tutti -> F.size()
    phoneBook empty;
    testFind(empty, "Gauss");   // rubrica vuota -> 0

    // --- (g): shift
    cout << endl << "== Test shift_phoneBook:" << endl;
    phoneBook S = F;
    shift_phoneBook(S, 1);
    print_phoneBook(S);
    try {
        shift_phoneBook(S, S.size() + 1);
    } catch (const string &msg) {
        cout << "Eccezione: " << msg << endl;
    }

    // --- (h): inserimento ordinato
    add_contact_to_phoneBook(F, "Galilei", "Galileo", "0551564");    // in mezzo
    add_contact_to_phoneBook(F, "Bohr", "Niels", "+4533123");        // in testa
    add_contact_to_phoneBook(F, "Volta", "Alessandro", "031987654"); // in coda
    add_contact_to_phoneBook(empty, "Curie", "Marie", "+3311223344"); // rubrica vuota
    cout << endl << "== Rubrica dopo add_contact_to_phoneBook:" << endl;
    print_phoneBook(F);
    cout << "== Rubrica (prima vuota) dopo add_contact_to_phoneBook:" << endl;
    print_phoneBook(empty);

    // --- (d): scrittura su file e rilettura per verifica
    write_phoneBook_to_file(F, "phoneBook_out.txt");
    phoneBook R;
    read_phoneBook_from_file(R, "phoneBook_out.txt");
    cout << endl << "== Rubrica riletta da phoneBook_out.txt (" << R.size() << " contatti):" << endl;
    print_phoneBook(R);
    return 0;
}
