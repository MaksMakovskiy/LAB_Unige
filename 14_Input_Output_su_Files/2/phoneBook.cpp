#include <iostream>
#include <fstream>
#include "phoneBook.h"
using namespace std;

// (a) aggiunge un contatto in coda alla rubrica
void push_contact_in_phoneBook(phoneBook &B, const string &surname, const string &name,
                               const string &number) {
    contact c;
    c.surname = surname;
    c.name = name;
    c.phoneNumber = number;
    B.push_back(c);
}

// (b) stampa la rubrica, un contatto per riga
void print_phoneBook(const phoneBook &B) {
    for (size_t i = 0; i < B.size(); ++i)
        cout << B[i].surname << " " << B[i].name << " " << B[i].phoneNumber << endl;
}

// (c) legge la rubrica da file: numero di contatti seguito da triple cognome nome telefono
void read_phoneBook_from_file(phoneBook &B, const string &fileName) {
    ifstream infile;
    infile.open(fileName);
    if (!infile) {
        cout << "Impossibile aprire il file " << fileName << endl;
        return;
    }
    string data;
    infile >> data;
    int N = stoi(data);
    for (int i = 0; i < N; ++i) {
        string surname, name, number;
        infile >> surname >> name >> number;
        push_contact_in_phoneBook(B, surname, name, number);
    }
    infile.close();
}

// (d) salva la rubrica su file nello stesso formato usato per la lettura
void write_phoneBook_to_file(const phoneBook &B, const string &fileName) {
    ofstream outfile;
    outfile.open(fileName);
    if (!outfile) {
        cout << "Impossibile aprire il file " << fileName << endl;
        return;
    }
    outfile << B.size() << endl;
    for (size_t i = 0; i < B.size(); ++i)
        outfile << B[i].surname << " " << B[i].name << " " << B[i].phoneNumber << endl;
    outfile.close();
}

// (e) ordina alfabeticamente per cognome (selection sort)
void sort_phoneBook_by_surnames(phoneBook &B) {
    for (size_t i = 0; i < B.size(); ++i) {
        size_t index = i;
        for (size_t j = i + 1; j < B.size(); ++j)
            if (B[j].surname < B[index].surname) index = j;
        contact tmp = B[i];
        B[i] = B[index];
        B[index] = tmp;
    }
}

// (f) ricerca binaria per cognome (la rubrica deve essere ordinata)
bool find_phoneBook_contact_by_surname(const phoneBook &B, const string &s, size_t &pos) {
    size_t first = 0, last = B.size();  // intervallo [first, last)
    while (first < last) {
        size_t mid = first + (last - first) / 2;
        if (B[mid].surname == s) {
            pos = mid;
            return true;
        } else if (B[mid].surname < s) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    // non trovato: first e' la posizione del primo cognome maggiore di s (o B.size())
    pos = first;
    return false;
}

// (g) aggiunge un elemento in fondo e sposta a destra di uno gli elementi da pos in poi
void shift_phoneBook(phoneBook &B, size_t pos) {
    if (pos > B.size())
        throw string("void shift_phoneBook: posizione fuori dai limiti ammissibili");
    if (pos == B.size() || B.size() == 0)
        return;
    B.push_back(B[B.size() - 1]);
    for (size_t i = B.size() - 2; i > pos; --i)
        B[i] = B[i - 1];
}

// (h) inserisce il contatto nella posizione corretta in ordine alfabetico
//     (precondizione: B ordinata per cognome)
void add_contact_to_phoneBook(phoneBook &B, const string &surname, const string &name,
                              const string &number) {
    size_t pos;
    find_phoneBook_contact_by_surname(B, surname, pos);
    if (pos == B.size()) {  // in fondo o rubrica vuota
        push_contact_in_phoneBook(B, surname, name, number);
        return;
    }
    shift_phoneBook(B, pos);
    B[pos].surname = surname;
    B[pos].name = name;
    B[pos].phoneNumber = number;
}
